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

// MACROS SERIALIZE(prefix)

/*
// копипаста потенциально полезного кода
FR_TOKEN getop(char const **ptr)
*/

#define TALLOC_PROTOBUF(ctx, type) talloc_zero(ctx, type)

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
    avp->op = (char *)fr_token_name(vp->op);
    if (vp->da->flags.has_tag) {
        avp->tag = vp->tag;
    }

    return avp;

error:
    TALLOC_FREE(avp);
    return NULL;
}

int pack_freeradius_valuepairs(TALLOC_CTX *ctx, const VALUE_PAIR *vps, FRAVP ***out_avps) {
    int vps_count = count_vps(vps);
    if (!vps_count) return 0;

    vp_cursor_t cursor;
    VALUE_PAIR *vp;
    int i = 0;

    FRAVP **avps = talloc_array(ctx, FRAVP*, vps_count);
    if (!avps) goto error;

	for (vp = fr_cursor_init(&cursor, &vps);
         vp;
         vp = fr_cursor_next(&cursor)) {
        FRAVP *avp = pack_freeradius_valuepair(ctx, vp);
        if (!avp) goto error;
        avps[i++] = avp;
    }

    *out_avps = avps;
    return vps_count;

error:
    for(int j = 0; j < i; j++) TALLOC_FREE(avps[j]);
    TALLOC_FREE(avps);
    return -1;
}

int pack_list(TALLOC_CTX *ctx, REQUEST *request, pair_lists_t list, FRAVP ***out_avps) {
/*
	da = dict_attrbyname(attribute);
	if (!da) {
		RWDEBUG("Attribute \"%s\" unknown, skipping", attribute);

		curl_free(name);

		continue;
	}

	ctx = radius_list_ctx(reference, list);

	vp = pairalloc(ctx, da);
	if (!vp) {
		REDEBUG("Failed creating valuepair");
		talloc_free(expanded);

		goto error;
	}

	ret = pairparsevalue(vp, expanded, -1);
	if (ret < 0) {
		RWDEBUG("Incompatible value assignment, skipping");
		talloc_free(vp);
		goto skip;
	}

	pairadd(vps, vp);
*/
	VALUE_PAIR **vps = radius_list(request, list);
	//rad_assert(vps);

    if (!vps) return 0;

    return pack_freeradius_valuepairs(ctx, *vps, out_avps);
}

Request *pack_request(TALLOC_CTX *ctx, REQUEST *request, UNUSED const rlm_zmq_t *inst, rlm_components_t comp) {
    Request *req = talloc_zero(ctx, Request);
    if (!req) goto error;
    request__init(req);

    int attr_count;

    req->component = (RLMCOMPONENT)comp;

    attr_count = pack_list(req, request, PAIR_LIST_REQUEST, &req->request);
    if (attr_count == -1) goto error;
    req->n_request = attr_count;

    attr_count = pack_list(req, request, PAIR_LIST_REPLY, &req->reply);
    if (attr_count == -1) goto error;
    req->n_reply = attr_count;

    attr_count = pack_list(req, request, PAIR_LIST_CONTROL, &req->control);
    if (attr_count == -1) goto error;
    req->n_control = attr_count;

    attr_count = pack_list(req, request, PAIR_LIST_STATE, &req->session_state);
    if (attr_count == -1) goto error;
    req->n_session_state = attr_count;

#ifdef WITH_PROXY
    attr_count = pack_list(req, request, PAIR_LIST_PROXY_REQUEST, &req->proxy_request);
    if (attr_count == -1) goto error;
    req->n_proxy_request = attr_count;

    attr_count = pack_list(req, request, PAIR_LIST_PROXY_REPLY, &req->proxy_reply);
    if (attr_count == -1) goto error;
    req->n_proxy_reply = attr_count;
#endif
#ifdef WITH_COA
    attr_count = pack_list(req, request, PAIR_LIST_COA, &req->coa);
    if (attr_count == -1) goto error;
    req->n_coa = attr_count;

    attr_count = pack_list(req, request, PAIR_LIST_COA_REPLY, &req->coa_reply);
    if (attr_count == -1) goto error;
    req->n_coa_reply = attr_count;

    attr_count = pack_list(req, request, PAIR_LIST_DM, &req->disconnect);
    if (attr_count == -1) goto error;
    req->n_disconnect = attr_count;

    attr_count = pack_list(req, request, PAIR_LIST_DM_REPLY, &req->disconnect_reply);
    if (attr_count == -1) goto error;
    req->n_disconnect_reply = attr_count;
#endif

    return req;

error:
    TALLOC_FREE(req);
    return NULL;
}

void *serialize_request(TALLOC_CTX *ctx, size_t *len, REQUEST *request, rlm_zmq_t *inst, rlm_components_t comp) {
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
