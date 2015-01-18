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

#endif /*_ZMQ_SERIALIZE_H*/
