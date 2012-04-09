/* config.h.  Generated from config.h.in by configure.  */
/* emacs edit mode for this file is -*- C -*- */

#ifndef INCL_CONFIG_H
#define INCL_CONFIG_H

/* {{{ docu
 *
 * config.h.in - used by `configure' to create `config.h'.
 *
 * This file is included at building time from almost all source
 * files belonging to Factory.  Furthermore, it is (textually)
 * included into `factoryconf.h' by `makeheader' so we have an
 * installed version of this file, too.  This way, the installed
 * source files will be compiled with the same settings as the
 * library itself.
 *
 * In general, you should let `configure' guess the correct
 * values for the `#define's below.  But if something seriously
 * goes wrong in configuring, please inform the authors and feel
 * free to edit the marked section.
 *
 */
/* }}} */

/************** START OF CONFIGURABLE SECTION **************/

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define as __inline if that's what the C compiler calls it.  */
/* #undef inline */

/* factory version */
#define FACTORYVERSION "3.1.4"

/* factory configuration */
#define FACTORYCONFIGURATION "' '--without-MP' '--disable-sgroup' '--disable-MP' '--without-sgroup' '--without-dbm' '--disable-dbm' '--with-malloc=system' '--prefix=/cygdrive/c/lapa/sing/Singular-f5-like' '--exec_prefix=/cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win' '--bindir=/cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win' '--libdir=/cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win/lib' '--includedir=/cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win/include' '--enable-omalloc' '--with-external-config_h=/cygdrive/c/lapa/sing/Singular-f5-like/Singular/omSingularConfig.h' '--with-track-custom' '--enable-NTL' '--enable-factory' '--enable-libfac' '--enable-Singular' '--enable-IntegerProgramming' '--enable-Plural' '--enable-doc' '--enable-emacs' '--with-apint=gmp' '--with-factory' '--with-libfac' '--with-Singular=yes' '--cache-file=.././config.cache' '--srcdir=.' 'LDFLAGS=-L/cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win/lib -g'' in /cygdrive/c/lapa/sing/Singular-f5-like/factory"

/* where the gftables live */
#define GFTABLEDIR "/cygdrive/c/lapa/sing/Singular-f5-like/factory//factory/gftables"

/* define if your compiler does arithmetic shift */
/* #undef HAS_ARITHMETIC_SHIFT */

/* define to use "configurable inline methods" (see `cf_inline.cc') */
/* #undef CF_USE_INLINE */

/* define to build factory without stream IO */
#define NOSTREAMIO 1

/* which C++ header variants to use */
/* #undef HAVE_IOSTREAM_H */
/* #undef HAVE_FSTREAM_H */
/* #undef HAVE_STRSTREAM_H */

/* #undef HAVE_IOSTREAM */
/* #undef HAVE_FSTREAM */
/* #undef HAVE_STRING */

#define HAVE_CSTDIO 1

/* define if linked to Singular */
#define SINGULAR 1

/* define if build with OMALLOC */
#define HAVE_OMALLOC 1

/* define if linked with factory memory manager */
/* #undef USE_MEMUTIL */

/* define if linked with old factory memory manager */
/* #undef USE_OLD_MEMMAN */

/* define if linked with new factory manager, debugging version */
/* #undef MDEBUG */

/* define if you do not want to activate assertions */
#define NOASSERT 1

/* define if you want to activate the timing stuff */
/* #undef TIMING */

/* define if you want to have debugging output */
/* #undef DEBUGOUTPUT */

/* define type of your compilers 64 bit integer type */
#define INT64 long long int

/* define size of long */
#define SIZEOF_LONG 4

#define HAVE_NTL 1

/************** END OF CONFIGURABLE SECTION **************/

#endif /* ! INCL_CONFIG_H */
