/*
 *   This program is is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License, version 2 if the
 *   License as published by the Free Software Foundation.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

/**
 * $Id$
 * @file rlm_zmq.c
 * @brief Example module code.
 *
 * @copyright 2014 The FreeRADIUS server project
 * @copyright 2014 Anton Shurpin <anton.shurpin@gmail.com>
 */
RCSID("$Id$")

#include <freeradius-devel/rad_assert.h>

#include <zmq.h>

#include "rlm_zmq.h"
#include "zmq.h"

/*
 *	A mapping of configuration file names to internal variables.
 */
static const CONF_PARSER module_config[] = {
	{ "connect_uri", FR_CONF_OFFSET(PW_TYPE_STRING, rlm_zmq_t, connect_uri), NULL },
	{ "timeout", FR_CONF_OFFSET(PW_TYPE_SIGNED, rlm_zmq_t, timeout), "3000" },
	{ NULL, -1, 0, NULL, NULL }		/* end the list */
};

/*
 *	Do any per-module initialization that is separate to each
 *	configured instance of the module.  e.g. set up connections
 *	to external databases, read configuration files, set up
 *	dictionary entries, etc.
 *
 *	If configuration information is given in the config section
 *	that must be referenced in later calls, store a handle to it
 *	in *instance otherwise put a null pointer there.
 */
static int mod_instantiate(CONF_SECTION *conf, void *instance)
{
	rlm_zmq_t *inst = instance;
	char const *name;

	name = cf_section_name2(conf);
	if (!name) {
		name = cf_section_name1(conf);
	}

	inst->name = name;
	inst->cs = conf;

	inst->zctx = zmq_ctx_new();
	if (!inst->zctx) return -1;

	inst->pool = fr_connection_pool_module_init(inst->cs, inst, mod_conn_create, NULL, NULL);
	if (!inst->pool) return -1;

	int major, minor, patch;
	zmq_version (&major, &minor, &patch);
	INFO("rlm_zmq loaded. Current ØMQ version is %d.%d.%d", major, minor, patch);

	return 0;
}

/*
 *	Only free memory we allocated.  The strings allocated via
 *	cf_section_parse() do not need to be freed.
 */
static int mod_detach(UNUSED void *instance)
{
	rlm_zmq_t *inst = instance;

	if (inst->pool) fr_connection_pool_delete(inst->pool);
	if (inst->zctx) zmq_ctx_destroy(inst->zctx);

	/*
	 *  We need to explicitly free all children, so if the driver
	 *  parented any memory off the instance, their destructors
	 *  run before we unload the bytecode for them.
	 *
	 *  If we don't do this, we get a SEGV deep inside the talloc code
	 *  when it tries to call a destructor that no longer exists.
	 */
	talloc_free_children(inst);

	return 0;
}

/*
 *	Find the named user in this modules database.  Create the set
 *	of attribute-value pairs to check and reply with for this user
 *	from the database. The authentication code only needs to check
 *	the password, the rest is done here.
 */
static rlm_rcode_t CC_HINT(nonnull) mod_authorize(void *instance, REQUEST *request) {
	return zmq_mod_call(instance, request, RLM_COMPONENT_AUTZ);
}

/*
 *	Authenticate the user with the given password.
 */
static rlm_rcode_t CC_HINT(nonnull) mod_authenticate(void *instance, REQUEST *request)
{
	return zmq_mod_call(instance, request, RLM_COMPONENT_AUTH);
}

/*
 *	Massage the request before recording it or proxying it
 */
static rlm_rcode_t CC_HINT(nonnull) mod_preacct(void *instance, REQUEST *request)
{
	return zmq_mod_call(instance, request, RLM_COMPONENT_PREACCT);
}

/*
 *	Write accounting information to this modules database.
 */
static rlm_rcode_t CC_HINT(nonnull) mod_accounting(void *instance, REQUEST *request)
{
	return zmq_mod_call(instance, request, RLM_COMPONENT_ACCT);
}

/*
 *	See if a user is already logged in. Sets request->simul_count to the
 *	current session count for this user and sets request->simul_mpp to 2
 *	if it looks like a multilink attempt based on the requested IP
 *	address, otherwise leaves request->simul_mpp alone.
 *
 *	Check twice. If on the first pass the user exceeds his
 *	max. number of logins, do a second pass and validate all
 *	logins by querying the terminal server (using eg. SNMP).
 */
static rlm_rcode_t CC_HINT(nonnull) mod_checksimul(void *instance, REQUEST *request)
{
	return zmq_mod_call(instance, request, RLM_COMPONENT_SESS);
}

/*
 *	The module name should be the only globally exported symbol.
 *	That is, everything else should be 'static'.
 *
 *	If the module needs to temporarily modify it's instantiation
 *	data, the type should be changed to RLM_TYPE_THREAD_UNSAFE.
 *	The server will then take care of ensuring that the module
 *	is single-threaded.
 */
module_t rlm_zmq = {
	RLM_MODULE_INIT,
	"zmq",
	RLM_TYPE_THREAD_SAFE,	/* type */
	sizeof(rlm_zmq_t),
	module_config,			/* CONF_PARSER */
	mod_instantiate,		/* instantiation */
	mod_detach,				/* detach */
	{
		mod_authenticate,	/* authentication */
		mod_authorize,		/* authorization */
		mod_preacct,		/* preaccounting */
		mod_accounting,		/* accounting */
		mod_checksimul,		/* checksimul */
		NULL,				/* pre-proxy */
		NULL,				/* post-proxy */
		NULL				/* post-auth */
#ifdef WITH_COA
		, NULL,
		NULL
#endif
	}
};
