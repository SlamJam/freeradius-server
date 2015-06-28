AC_PREREQ([2.53])
AC_INIT(rlm_zmq.c)
AC_REVISION($Revision$)
AC_DEFUN(modname,[rlm_zmq])

if test x$with_[]modname != xno; then

	dnl ############################################################
	dnl # Check for compiler
	dnl ############################################################
	AC_PROG_CC

	dnl ############################################################
	dnl # Check for protoc-c compiler binary
	dnl ############################################################

	AC_ARG_WITH([protoc-c],
		[AS_HELP_STRING([--with-protoc-c=PATH],
			[location of the protoc-c protocol buffer compiler binary, defaults to protoc-c])],
		[PROTOCC="$withval"],
		[PROTOCC='protoc-c'])

	AC_PATH_PROG([PROTOCC_TEST], [${PROTOCC}], [no])
	AS_IF([test "${PROTOCC_TEST}" == "no"], [AC_MSG_WARN([ProtoBuf compiler "${PROTOCC}" not found. Could not regenerate rlm_zmq.proto])])

	AC_SUBST([PROTOCC])

    dnl ############################################################
    dnl # Check for zmq
    dnl ############################################################

	dnl extra argument: --with-zmq-include-dir=DIR
	zmq_include_dir=
	AC_ARG_WITH(zmq-include-dir,
		[AS_HELP_STRING([--with-zmq-include-dir=DIR],
		[Directory where the zmq includes may be found])],
		[case "$withval" in
			no)
				AC_MSG_ERROR(Need zmq-include-dir)
			;;
			yes)
			;;
			*)
				zmq_include_dir="$withval"
			;;
		esac])

	dnl extra argument: --with-zmq-lib-dir=DIR
	zmq_lib_dir=
	AC_ARG_WITH(zmq-lib-dir,
	[AS_HELP_STRING([--with-zmq-lib-dir=DIR],
		[Directory where the zmq libraries may be found])],
		[case "$withval" in
			no)
				AC_MSG_ERROR(Need zmq-lib-dir)
			;;
			yes)
			;;
			*)
				zmq_lib_dir="$withval"
			;;
		esac])

	dnl extra argument: --with-zmq-dir=DIR
	AC_ARG_WITH(zmq-dir,
	[AS_HELP_STRING([--with-zmq-dir=DIR],
		[Base directory where zmq is installed])],
		[case "$withval" in
			no)
				AC_MSG_ERROR(Need zmq-dir)
			;;
			yes)
			;;
			*)
				zmq_lib_dir="$withval/lib"
				zmq_include_dir="$withval/include"
			;;
		esac])

	dnl ############################################################
	dnl # Check for zmq header files
	dnl ############################################################

	have_zmq="yes"

	smart_prefix=""
	smart_try_dir="$zmq_include_dir"
	FR_SMART_CHECK_INCLUDE([zmq.h])
	if test "x$ac_cv_header_zmq_h" != "xyes"; then
		have_zmq="no"
		AC_MSG_WARN([zmq headers not found. Use --with-zmq-include-dir=<path>.])
	fi

	dnl ############################################################
	dnl # Check for zmq libraries
	dnl ############################################################

	smart_try_dir="$zmq_lib_dir"
	FR_SMART_CHECK_LIB([zmq], [zmq_init])
	if test "x$ac_cv_lib_zmq_zmq_init" != "xyes"; then
		have_zmq="no"
		AC_MSG_WARN([zmq libraries not found. Use --with-zmq-lib-dir=<path>.])
	fi

	if test x"$have_zmq" != x"yes"; then
		fail="$fail libzmq"
	fi

    dnl ############################################################
    dnl # Check for protobuf-c
    dnl ############################################################

	dnl extra argument: --with-protobufc-include-dir=DIR
	protobufc_include_dir=
	AC_ARG_WITH(protobufc-include-dir,
		[AS_HELP_STRING([--with-protobufc-include-dir=DIR],
		[Directory where the protobuf-c includes may be found])],
		[case "$withval" in
			no)
				AC_MSG_ERROR(Need protobufc-include-dir)
			;;
			yes)
			;;
			*)
				protobufc_include_dir="$withval"
			;;
		esac])

	dnl extra argument: --with-protobufc-lib-dir=DIR
	protobufc_lib_dir=
	AC_ARG_WITH(protobufc-lib-dir,
	[AS_HELP_STRING([--with-protobufc-lib-dir=DIR],
		[Directory where the protobuf-c libraries may be found])],
		[case "$withval" in
			no)
				AC_MSG_ERROR(Need protobufc-lib-dir)
			;;
			yes)
			;;
			*)
				protobufc_lib_dir="$withval"
			;;
		esac])

	dnl extra argument: --with-protobufc-dir=DIR
	AC_ARG_WITH(protobufc-dir,
	[AS_HELP_STRING([--with-protobufc-dir=DIR],
		[Base directory where protobuf-c is installed])],
		[case "$withval" in
			no)
				AC_MSG_ERROR(Need protobufc-dir)
			;;
			yes)
			;;
			*)
				protobufc_lib_dir="$withval/lib"
				protobufc_include_dir="$withval/include"
			;;
		esac])

	dnl ############################################################
	dnl # Check for protobuf-c header files
	dnl ############################################################

	have_protobuf_c="yes"

	smart_prefix="protobuf-c"
	smart_try_dir="$protobufc_include_dir"
	FR_SMART_CHECK_INCLUDE([protobuf-c.h])
	if test "x$ac_cv_header_protobufmc_h" != "xyes"; then
		have_protobuf_c="no"
		AC_MSG_WARN([protobuf-c headers not found. Use --with-protobufc-include-dir=<path>.])
	fi

	dnl ############################################################
	dnl # Check for protobuf-c libraries
	dnl ############################################################

	smart_try_dir="$protobufc_lib_dir"
	FR_SMART_CHECK_LIB([protobuf-c], [protobuf_c_version])
	if test "x$ac_cv_lib_protobuf_c_protobuf_c_version" != "xyes"; then
		have_protobuf_c="no"
		AC_MSG_WARN([protobuf-c libraries not found. Use --with-libprotobufc-lib-dir=<path>.])
	fi

	if test x"$have_protobuf_c" != x"yes"; then
		fail="$fail protobuf-c"
	fi

	dnl ############################################################
	dnl # Checks done - set targetname
	dnl ############################################################

	targetname=modname
else
	targetname=
	echo \*\*\* module modname is disabled.
fi

if test x"$fail" != x""; then
	if test x"${enable_strict_dependencies}" = x"yes"; then
		AC_MSG_ERROR([set --without-]modname[ to disable it explicitly.])
	else
		AC_MSG_WARN([silently not building ]modname[.])
		AC_MSG_WARN([FAILURE: ]modname[ requires: $fail.]);
		targetname=""
	fi
fi

mod_ldflags="${SMART_LIBS}"
mod_cflags="${SMART_CPPFLAGS}"

AC_SUBST(mod_cflags)
AC_SUBST(mod_ldflags)

AC_CONFIG_HEADER(config.h)

AC_SUBST(targetname)
AC_OUTPUT(all.mk)
