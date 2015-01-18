/* Copyright 2006 The FreeRADIUS server project */

#ifndef _ZMQ_SERIALIZE_H
#define _ZMQ_SERIALIZE_H

RCSIDH(zmq_serialize_h, "$Id$")

#include <freeradius-devel/radiusd.h>
#include <freeradius-devel/modules.h>

#include "rlm_zmq.pb-c.h"
#include "rlm_zmq.h"

FRAVP *pack_freeradius_valuepair(TALLOC_CTX *ctx, const VALUE_PAIR *vp);
FRAVP **pack_freeradius_valuepairs(TALLOC_CTX *ctx, const VALUE_PAIR *vps, int *p_count);
FRAVP **pack_list(TALLOC_CTX *ctx, REQUEST *request, pair_lists_t list, int *p_count);
Request *pack_request(TALLOC_CTX *ctx, REQUEST *request, const rlm_zmq_t *inst, rlm_components_t comp);

void *serialize_request(TALLOC_CTX *ctx, REQUEST *request, rlm_zmq_t *inst, rlm_components_t comp, size_t *len);


VALUE_PAIR *unpack_freeradius_valuepair(TALLOC_CTX *ctx, FRAVP *avp);
int unpack_freeradius_valuepairs(TALLOC_CTX *ctx, FRAVP **avps, size_t count, VALUE_PAIR **p_vps);
int unpack_list(TALLOC_CTX *ctx, FRAVP **avps, size_t count, REQUEST *request, pair_lists_t list);
int unpack_response(TALLOC_CTX *ctx, Response *resp, REQUEST *request, rlm_zmq_t *inst, rlm_rcode_t *rcode);

int deserialize_response(TALLOC_CTX *ctx, REQUEST *request, rlm_zmq_t *inst, void const *buf, size_t len, rlm_rcode_t *rcode);

#endif /*_ZMQ_SERIALIZE_H*/
