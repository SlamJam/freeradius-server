/* Copyright 2006 The FreeRADIUS server project */

#ifndef _ZMQ_SERIALIZE_H
#define _ZMQ_SERIALIZE_H

RCSIDH(zmq_serialize_h, "$Id$")

void *pack_freeradius_packet(TALLOC_CTX *ctx, RADIUS_PACKET *packet, size_t *len);

#endif /*_ZMQ_SERIALIZE_H*/
