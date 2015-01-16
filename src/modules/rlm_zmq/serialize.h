/* Copyright 2006 The FreeRADIUS server project */

#ifndef _ZMQ_SERIALIZE_H
#define _ZMQ_SERIALIZE_H

RCSIDH(zmq_serialize_h, "$Id$")

#include <freeradius-devel/radiusd.h>
#include <freeradius-devel/modules.h>

#include "rlm_zmq.pb-c.h"
#include "rlm_zmq.h"

FRAVP pack_freeradius_valuepair(TALLOC_CTX *ctx, VALUE_PAIR *vp);
FRPacket pack_freeradius_packet(TALLOC_CTX *ctx, RADIUS_PACKET *packet);
FRRequest pack_freeradius_request(TALLOC_CTX *ctx, REQUEST *request);
ModState pack_mod_request(TALLOC_CTX *ctx, REQUEST *request, rlm_zmq_t *inst, rlm_components_t comp);

#endif /*_ZMQ_SERIALIZE_H*/
