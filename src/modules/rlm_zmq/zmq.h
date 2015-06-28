/* Copyright 2006 The FreeRADIUS server project */

#ifndef _ZMQ_H
#define _ZMQ_H

RCSIDH(zmq_h, "$Id$")

#include	<freeradius-devel/modules.h>

typedef struct rlm_zmq_handle {
	void		*sock;	//!< ZMQ socket handle.
	rlm_zmq_t	*inst;	//!< The rlm_zmq instance this connection belongs to.
} rlm_zmq_handle_t;

void *mod_conn_create(TALLOC_CTX *ctx, void *instance);
rlm_rcode_t CC_HINT(nonnull) zmq_mod_call(void *instance, REQUEST *request, rlm_components_t comp);

#endif /*_ZMQ_H*/
