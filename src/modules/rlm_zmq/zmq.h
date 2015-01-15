/* Copyright 2006 The FreeRADIUS server project */

#ifndef _ZMQ_H
#define _ZMQ_H

RCSIDH(zmq_h, "$Id$")

typedef struct rlm_zmq_handle {
	void		*sock;	//!< ZMQ socket handle.
	rlm_zmq_t	*inst;	//!< The rlm_zmq instance this connection belongs to.
} rlm_zmq_handle_t;

void *mod_conn_create(TALLOC_CTX *ctx, void *instance);

#endif /*_ZMQ_H*/
