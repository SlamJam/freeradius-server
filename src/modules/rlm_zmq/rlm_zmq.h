/*
 * The MIT License (MIT)
 *
 * Copyright (c) [year] [fullname]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/*************************************************************************** *
 * * rlm_zmq.h           rlm_zmq - FreeRADIUS ZMQ Module                     *
 * *                                                                         *
 * *     Header for main ZMQ module file                                     *
 * *                                                                         *
 * *                   Anton Shurpin <anton.shurpin@gmail.com>               *
 * ***************************************************************************/
#ifndef _RLM_ZMQ_H
#define _RLM_ZMQ_H

RCSIDH(rlm_zmq_h, "$Id$")

#include <freeradius-devel/radiusd.h>

/*
 *  Define a structure for our module configuration.
 *
 *  These variables do not need to be in a structure, but it's
 *  a lot cleaner to do so, and a pointer to the structure can
 *  be used as the instance handle.
 */
typedef struct rlm_zmq_t {
	char const				*name;			// Instance name.
	CONF_SECTION			*cs;
	void 					*zctx;
	char const				*connect_uri;	// URI we attempt to connect to
	int						timeout;
	fr_connection_pool_t	*pool;
} rlm_zmq_t;

#endif
