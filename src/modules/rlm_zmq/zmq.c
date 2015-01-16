/*
 * zmq.c
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

#include <freeradius-devel/radiusd.h>
#include <freeradius-devel/rad_assert.h>

#include <stdio.h>
#include <zmq.h>

#include "rlm_zmq.h"
#include "zmq.h"
#include "serialize.h"

rlm_rcode_t CC_HINT(nonnull) zmq_mod_call(void *instance, REQUEST *request, UNUSED rlm_components_t comp) {
	rlm_rcode_t rcode = RLM_MODULE_NOOP;

	rlm_zmq_t *inst = instance;
	rlm_zmq_handle_t  *handle;
    void *buf = NULL;
    size_t buf_len = 0;

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

    // serialize
    //buf = serialize_mod_state(request, request, &buf_len);

    // send
    int res = zmq_send(handle->sock, buf, buf_len, 0);
    if (res == -1) goto error;

    // receive

    // deserialize

release:
    TALLOC_FREE(buf);
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

    zmq_connect(handle->sock, inst->connect_uri);

	exec_trigger(NULL, inst->cs, "modules.zmq.open", false);
	return handle;
}
