/* Copyright 2006 The FreeRADIUS server project */

#ifndef _ZMQ_SERIALIZE_H
#define _ZMQ_SERIALIZE_H

RCSIDH(zmq_serialize_h, "$Id$")

#include <freeradius-devel/radiusd.h>
#include <freeradius-devel/modules.h>

#include "rlm_zmq.pb-c.h"
#include "rlm_zmq.h"

FRAVP *pack_freeradius_valuepair(TALLOC_CTX *ctx, const VALUE_PAIR *vp);
int pack_freeradius_valuepairs(TALLOC_CTX *ctx, const VALUE_PAIR *vps, FRAVP ***avps);
int pack_list(TALLOC_CTX *ctx, REQUEST *request, pair_lists_t list, FRAVP ***out_avps);
Request *pack_request(TALLOC_CTX *ctx, REQUEST *request, const rlm_zmq_t *inst, rlm_components_t comp);

void *serialize_request(TALLOC_CTX *ctx, size_t *len, REQUEST *request, rlm_zmq_t *inst, rlm_components_t comp);

#endif /*_ZMQ_SERIALIZE_H*/
