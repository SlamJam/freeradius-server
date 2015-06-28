/*
 * serialize.c
 *
 * Version:	$Id$
 *
 * Copyright (c) 2014, Anton Shurpin <anton.shurpin@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

RCSID("$Id$")

#include "serialize.h"

#define PACK_LIST(ctx, req, request, PAIR_LIST, list) do { int count; req->list = pack_list(ctx, request, PAIR_LIST, &count); if (count == -1) goto error; req->n_##list = count; } while(0);

#define UNPACK_LIST(ctx, resp, request, PAIR_LIST, list) do { int count = unpack_list(ctx, resp->list, resp->n_##list, request, PAIR_LIST); if (count == -1) goto error; } while(0);

//#define SERIALIZE(prefix)
//#define TALLOC_PROTOBUF(ctx, type) talloc_zero(ctx, type)

static int count_vps(const VALUE_PAIR *vps) {
    if (!vps) return 0;

    int count = 0;
    vp_cursor_t cursor;

    VALUE_PAIR *vp = fr_cursor_init(&cursor, &vps);

    while (vp) {
        vp = fr_cursor_next(&cursor);
        count++;
    }

    return count;
}

FRAVP *pack_freeradius_valuepair(TALLOC_CTX *ctx, const VALUE_PAIR *vp) {
    FRAVP *avp = talloc_zero(ctx, FRAVP);
    if (!avp) goto error;
    fr__avp__init(avp);

    avp->attr = vp->da->attr;
    avp->vendor = vp->da->vendor;
    avp->value = vp_aprints_value(ctx, vp, '\0');
    avp->op = talloc_strdup(avp, fr_token_name(vp->op));
    if (vp->da->flags.has_tag) {
        avp->tag = vp->tag;
    }

    return avp;

error:
    TALLOC_FREE(avp);
    return NULL;
}

FRAVP **pack_freeradius_valuepairs(TALLOC_CTX *ctx, const VALUE_PAIR *vps, int *p_count) {
    int vps_count = count_vps(vps);
    FRAVP **avps = NULL;
    if (!vps_count) goto release;

    vp_cursor_t cursor;
    VALUE_PAIR *vp;
    int i = 0;

    avps = talloc_array(ctx, FRAVP*, vps_count);
    if (!avps) goto error;

	for (vp = fr_cursor_init(&cursor, &vps);
         vp;
         vp = fr_cursor_next(&cursor)) {
        FRAVP *avp = pack_freeradius_valuepair(avps, vp);
        if (!avp) goto error;
        avps[i++] = avp;
    }

release:
    *p_count = vps_count;
    return avps;

error:
    TALLOC_FREE(avps);
    *p_count = -1;
    return NULL;
}

FRAVP **pack_list(TALLOC_CTX *ctx, REQUEST *request, pair_lists_t list, int *p_count) {
	VALUE_PAIR **p_vps = radius_list(request, list);
    VALUE_PAIR *vps = NULL;
	//rad_assert(vps);

    if (p_vps) vps = *p_vps;

    return pack_freeradius_valuepairs(ctx, vps, p_count);
}

Request *pack_request(TALLOC_CTX *ctx, REQUEST *request, UNUSED const rlm_zmq_t *inst, rlm_components_t comp) {
    Request *req = talloc_zero(ctx, Request);
    if (!req) goto error;
    request__init(req);

    req->component = (RLMCOMPONENT)comp;

    PACK_LIST(ctx, req, request, PAIR_LIST_REQUEST, request);
    PACK_LIST(ctx, req, request, PAIR_LIST_REPLY, reply);
    PACK_LIST(ctx, req, request, PAIR_LIST_CONTROL, control);
    PACK_LIST(ctx, req, request, PAIR_LIST_STATE, session_state);
#ifdef WITH_PROXY
    PACK_LIST(ctx, req, request, PAIR_LIST_PROXY_REQUEST, proxy_request);
    PACK_LIST(ctx, req, request, PAIR_LIST_PROXY_REPLY, proxy_reply);
#endif
#ifdef WITH_COA
    PACK_LIST(ctx, req, request, PAIR_LIST_COA, coa);
    PACK_LIST(ctx, req, request, PAIR_LIST_COA_REPLY, coa_reply);
    PACK_LIST(ctx, req, request, PAIR_LIST_DM, disconnect);
    PACK_LIST(ctx, req, request, PAIR_LIST_DM_REPLY, disconnect_reply);
#endif

    return req;

error:
    TALLOC_FREE(req);
    return NULL;
}

void *serialize_request(TALLOC_CTX *ctx, REQUEST *request, rlm_zmq_t *inst, rlm_components_t comp, size_t *len) {
    void *buf = NULL;
    Request *req = pack_request(ctx, request, inst, comp);
    if (!req) goto release;

    size_t buf_len = request__get_packed_size(req);

    buf = talloc_zero_size(ctx, buf_len); // Allocate required serialized buffer length
    if (!buf) goto release;
    request__pack(req, buf);
    *len = buf_len;

release:
    TALLOC_FREE(req);
    return buf;
}

/* UNPACKING & DESERIALIZATION */

VALUE_PAIR *unpack_freeradius_valuepair(TALLOC_CTX *ctx, FRAVP *avp) {
    VALUE_PAIR *vp;
    DICT_ATTR const* da;
    int ret;

    da = dict_attrbyvalue(avp->attr, avp->vendor);
    if (!da) {
    	DEBUG("Attribute code: \"%d\" vendor: \"%d\" unknown", avp->attr, avp->vendor);
    }

    vp = pairalloc(ctx, da);
    if (!vp) {
    	DEBUG("Failed creating valuepair");

    	goto error;
    }

    ret = pairparsevalue(vp, avp->value, -1);
    if (ret < 0) {
    	DEBUG("Incompatible value assignment, skipping");
    	goto error;
    }

    const char *p = avp->op;
    FR_TOKEN op = getop(&p);
    if (op == T_INVALID) {
    	goto error;
    }
    vp->op = op;

    if (vp->da->flags.has_tag) {
        vp->tag = avp->tag;
    }

    return vp;

error:
    TALLOC_FREE(vp);
    return NULL;
}

int unpack_freeradius_valuepairs(TALLOC_CTX *ctx, FRAVP **avps, size_t count, VALUE_PAIR **p_vps) {
    VALUE_PAIR *vp;

    for(size_t i = 0; i < count; i++) {
        FRAVP *avp = avps[i];
        vp = unpack_freeradius_valuepair(ctx, avp);
        if (!vp) goto error;
        pairadd(p_vps, vp);
    }

    return count;

error:
    return -1;
}

int unpack_list(UNUSED TALLOC_CTX *ctx, FRAVP **avps, size_t count, REQUEST *request, pair_lists_t list) {
    if (!count) return 0;
    if (!avps) return -1;

	VALUE_PAIR **p_vps = radius_list(request, list);
	//rad_assert(p_vps);

    if (!p_vps) return -1;

    // Если листа нет, то варнинг в консоль. Лучше дергать в самом конце, когда остальное проверено
    TALLOC_CTX *list_ctx = radius_list_ctx(request, list);

    return unpack_freeradius_valuepairs(list_ctx, avps, count, p_vps);
}

int unpack_response(TALLOC_CTX *ctx, Response *resp, REQUEST *request, UNUSED rlm_zmq_t *inst, rlm_rcode_t *rcode) {

    UNPACK_LIST(ctx, resp, request, PAIR_LIST_REQUEST, request);
    UNPACK_LIST(ctx, resp, request, PAIR_LIST_REPLY, reply);
    UNPACK_LIST(ctx, resp, request, PAIR_LIST_CONTROL, control);
    UNPACK_LIST(ctx, resp, request, PAIR_LIST_STATE, session_state);
#ifdef WITH_PROXY
    UNPACK_LIST(ctx, resp, request, PAIR_LIST_PROXY_REQUEST, proxy_request);
    UNPACK_LIST(ctx, resp, request, PAIR_LIST_PROXY_REPLY, proxy_reply);
#endif
#ifdef WITH_COA
    UNPACK_LIST(ctx, resp, request, PAIR_LIST_COA, coa);
    UNPACK_LIST(ctx, resp, request, PAIR_LIST_COA_REPLY, coa_reply);
    UNPACK_LIST(ctx, resp, request, PAIR_LIST_DM, disconnect);
    UNPACK_LIST(ctx, resp, request, PAIR_LIST_DM_REPLY, disconnect_reply);
#endif

    *rcode = (rlm_rcode_t)resp->rcode;
    return 0;

error:
    *rcode = RLM_MODULE_FAIL;
    return -1;
}


int deserialize_response(TALLOC_CTX *ctx, REQUEST *request, rlm_zmq_t *inst, void const *buf, size_t len, rlm_rcode_t *rcode) {
    int ret = 0;

    Response *resp = response__unpack(NULL, len, buf);
    if (resp == NULL) {
        WARN("error unpacking incoming message");
        goto error;
    }

    if (unpack_response(ctx, resp, request, inst, rcode) == -1) goto error;

release:
    if (resp) response__free_unpacked(resp, NULL);
    return ret;

error:
    ret = -1;
    goto release;
}
