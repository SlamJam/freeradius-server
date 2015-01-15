/*
 * zmq.c
 *
 * Version:	$Id$
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 * Copyright 2000,2006  The FreeRADIUS server project
 * Copyright 2000  your name <your address>
 */

RCSID("$Id$")

#include	<freeradius-devel/radiusd.h>
#include	<freeradius-devel/rad_assert.h>
#include	<freeradius-devel/modules.h>

#include <stdio.h>

#include <zmq.h>

#include "rlm_zmq.h"
#include "zmq.h"

rlm_rcode_t CC_HINT(nonnull) zmq_mod_call(void *instance, REQUEST *request, rlm_components_t comp) {
	rlm_rcode_t rcode = RLM_MODULE_NOOP;

	rlm_zmq_t *inst = instance;
	rlm_zmq_handle_t  *handle;

	rad_assert(request->packet != NULL);
	rad_assert(request->reply != NULL);

	/*
	 *	Reserve a socket
	 *
	 *	After this point use goto error or goto release to cleanup socket temporary pairlists and
	 *	temporary attributes.
	 */
	handle = fr_connection_get(inst->pool);
	if (!handle) {
		goto error;
	}


    // serialize()
    // send()
    // receive()
    // deserialize()



release:
	fr_connection_release(inst->pool, handle);
	return rcode;

error:
	rcode = RLM_MODULE_FAIL;
    goto release;
}

static int _mod_conn_free(rlm_zmq_handle_t *conn) {
	rlm_zmq_t *inst = conn->inst;

	rad_assert(inst);

	exec_trigger(NULL, inst->cs, "modules.zmq.close", false);

	return 0;
}

void *mod_conn_create(TALLOC_CTX *ctx, void *instance) {
	rlm_zmq_t *inst = instance;
	rlm_zmq_handle_t *handle;

	/*
	 *	Connections cannot be alloced from the inst or
	 *	pool contexts due to threading issues.
	 */
	handle = talloc_zero(ctx, rlm_zmq_handle_t);
	if (!handle) return NULL;

	/*
	 *	Handle requires a pointer to the SQL inst so the
	 *	destructor has access to the module configuration.
	 */
	handle->inst = inst;

	/*
	 *	When something frees this handle the destructor set by
	 *	the driver will be called first, closing any open sockets.
	 *	Then we call our destructor to trigger an modules.sql.close
	 *	event, then all the memory is freed.
	 */
	talloc_set_destructor(handle, _mod_conn_free);

    handle->sock = zmq_socket(inst->zmq_context, ZMQ_DEALER);

	if (!handle->sock) {
		exec_trigger(NULL, inst->cs, "modules.zmq.fail", true);

		/*
		 *	Destroy any half opened connections.
		 */
		talloc_free(handle);
		return NULL;
	}

    zmq_connect(handle->sock, inst->zmq_addr);

	exec_trigger(NULL, inst->cs, "modules.zmq.open", false);
	return handle;
}
