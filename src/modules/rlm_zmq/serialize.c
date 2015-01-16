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

FRAVP pack_freeradius_valuepair(UNUSED TALLOC_CTX *ctx, UNUSED VALUE_PAIR *vp) {
    FRAVP avp = FR__AVP__INIT;
        /*
        // копипаста потенциально полезного кода
        vp->op;
        if (vp->da->flags.has_tag) {
			snprintf(buf, BUF_SIZE, "%s:%d", vp->da->name, vp->tag);
		} else {
			strlcpy(buf, vp->da->name, sizeof(buf));
		}
        vp_prints_value(buf, sizeof(buf), vp, '"');
        if (vp->da->type != PW_TYPE_STRING) continue;
        */
    return avp;
}


FRPacket pack_freeradius_packet(TALLOC_CTX *ctx, RADIUS_PACKET *packet) {
    FRPacket pkt = FR__PACKET__INIT;
    pkt.code = packet->code;
    pkt.id = packet->id;

    vp_cursor_t cursor;
    VALUE_PAIR *vp;

	for (vp = fr_cursor_init(&cursor, &packet->vps);
         vp;
         vp = fr_cursor_next(&cursor)) {
        pack_freeradius_valuepair(ctx, vp);
    }

    return pkt;
}

FRRequest pack_freeradius_request(UNUSED TALLOC_CTX *ctx, UNUSED REQUEST *request) {
    FRRequest req = FR__REQUEST__INIT;

    return req;
}

ModState pack_mod_request(UNUSED TALLOC_CTX *ctx, UNUSED REQUEST *request, UNUSED rlm_zmq_t *inst, UNUSED rlm_components_t comp) {
    ModState state = MOD__STATE__INIT;

    return state;
}
