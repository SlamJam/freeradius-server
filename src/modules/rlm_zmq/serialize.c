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
size_t buf_len = fr__packet__get_packed_size (&pkt);
*len = buf_len;

void *buf = talloc_zero_size(ctx, buf_len); // Allocate required serialized buffer length
fr__packet__pack (&pkt, buf);

return buf;
*/

/*
// копипаста потенциально полезного кода
FR_TOKEN getop(char const **ptr)
*/

#define TALLOC_PROTOBUF(ctx, type) talloc_zero(ctx, type)

static int count_vps(const VALUE_PAIR *vps) {
    int count = 0;
    vp_cursor_t cursor;

    fr_cursor_init(&cursor, vps);

    while (fr_cursor_next(&cursor)) {
        count++;
    }

    return count;
}

FRAVP *pack_freeradius_valuepair(TALLOC_CTX *ctx, const VALUE_PAIR *vp) {
    FRAVP *avp = talloc_zero(ctx, FRAVP);
    fr__avp__init(avp);

    avp->attr = vp->da->attr;
    avp->vendor = vp->da->vendor;
    avp->value = vp_aprints_value(ctx, vp, '\0');
    avp->op = fr_token_name(vp->op);
    if (vp->da->flags.has_tag) {
        avp->tag = vp->tag;
    }

	DEBUG("ZMQ serialize attr: %s", vp->da->name);

    return avp;
}

int pack_freeradius_valuepairs(TALLOC_CTX *ctx, const VALUE_PAIR *vps, FRAVP ***avps) {
    int vps_count = count_vps(vps);
    *avps = talloc_array(ctx, FRAVP*, vps_count);

    vp_cursor_t cursor;
    VALUE_PAIR *vp;
    int i = 0;

	for (vp = fr_cursor_init(&cursor, vps);
         vp;
         vp = fr_cursor_next(&cursor)) {
        *avps[i++] = pack_freeradius_valuepair(ctx, vp);
    }

    return vps_count;
}

FRPacket *pack_freeradius_packet(TALLOC_CTX *ctx, const RADIUS_PACKET *packet) {
    FRPacket *pkt = talloc_zero(ctx, FRPacket);
    fr__packet__init(pkt);

    pkt->code = packet->code;
    pkt->id = packet->id;

    pkt->n_attrs = pack_freeradius_valuepairs(pkt, packet->vps, &pkt->attrs);

    /*
    int vps_count = count_vps(&packet->vps);
    pkt->vps_n = vps_count;
    pkt->vps = talloc_array_zero(pkt, *FRAVP, vps_count);

    vp_cursor_t cursor;
    VALUE_PAIR *vp;
    int i = 0;

	for (vp = fr_cursor_init(&cursor, &packet->vps);
         vp;
         vp = fr_cursor_next(&cursor)) {
        pkt->vps[i++] = pack_freeradius_valuepair(pkt, vp);
    }
    */
    return pkt;
}

FRRequest *pack_freeradius_request(TALLOC_CTX *ctx, const REQUEST *request) {
    FRRequest *req = talloc_zero(ctx, FRRequest);
    fr__request__init(req);

    req->packet = pack_freeradius_packet(req, request->packet);
    req->reply = pack_freeradius_packet(req, request->reply);

    req->n_config_items = pack_freeradius_valuepairs(req, request->config_items, &req->config_items);
    req->n_state = pack_freeradius_valuepairs(req, request->state, &req->state);

    return req;
}

ModState *pack_mod_request(TALLOC_CTX *ctx, const REQUEST *request, UNUSED const rlm_zmq_t *inst, rlm_components_t comp) {
    ModState *mod = talloc_zero(ctx, ModState);
    mod__state__init(mod);

    mod->component = (RLMCOMPONENT)comp;
    mod->request = pack_freeradius_request(mod, request);

    return mod;
}
/*
void *serialize_mod_request(UNUSED TALLOC_CTX *ctx, UNUSED REQUEST *request, UNUSED rlm_zmq_t *inst, UNUSED rlm_components_t comp)
*/
