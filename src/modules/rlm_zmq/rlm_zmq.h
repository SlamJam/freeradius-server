/*************************************************************************** *
 * * rlm_zmq.h           rlm_zmq - FreeRADIUS ZMQ Module                     *
 * *                                                                         *
 * *     Header for main SQL module file                                     *
 * *                                                                         *
 * *                   Anton Shurpin <anton.shurpin@gmail.com>               *
 * ***************************************************************************/
#ifndef _RLM_ZMQ_H
#define _RLM_ZMQ_H

RCSIDH(rlm_zmq_h, "$Id$")

#include <freeradius-devel/connection.h>

/*
 *  Define a structure for our module configuration.
 *
 *  These variables do not need to be in a structure, but it's
 *  a lot cleaner to do so, and a pointer to the structure can
 *  be used as the instance handle.
 */
typedef struct rlm_zmq_t {
	CONF_SECTION			*cs;
	void 					*zmq_context;
	char const				*zmq_addr;
	fr_connection_pool_t	*pool;
} rlm_zmq_t;

#endif
