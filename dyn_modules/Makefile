#################################################################
###
### Makefile for Singular-modules
###
### $Id$
###
#################################################################

SHELL		= /bin/sh

## 
## various paths
##
topsrcdir	= .
srcdir		= .
prefix 		= /cygdrive/c/lapa/sing/Singular-f5-like
exec_prefix 	= /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win
libdir 		= /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win/lib
# program executable goes here
bindir		= /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win
install_bindir	= /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win
# Singular libs go here
includedir	= /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win/include
INC_SRC		= ${topsrcdir}/Singular
SINGUNAME       = ix86-Win
install_bindir  = ${install_prefix}/${SINGUNAME}/MOD

## 
## various programs
##
CC		= gcc
CXX		= g++
#LEXP		= @LEXP@
PERL		= @PERL@
BISON		= bison

MKINSTALLDIRS   = ./mkinstalldirs
MODGEN		= ${srcdir}/modgen/modgen

##
## compiler and linker options
##
CFLAGS		= -g -O2 -pipe -I${srcdir} -I${INC_SRC}
CXXFLAGS	= -g -O2 -pipe 
#CXXTEMPLFLAGS	= @CXXTEMPLFLAGS@
CPPFLAGS	= -I${srcdir}  -I${includedir} -I${INC_SRC}
DEFS		= -DHAVE_CONFIG_H -DNDEBUG
LDFLAGS		= -L/cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win/lib -g # @LD_DYNAMIC@
#STATIC_LDFLAGS	= @STATIC_LDFLAGS@
#LIBS		= @NEED_LIBS@

##
## End configuration dependend stuff
#################################################################
##
## compiler and linker options
##
CFLAGS		+= ${DEFS}

#ifndef ix86-Win
MOD_FILES = loctriv
#MOD_DIRS = kernel
MOD_DIRS =
#else
MOD_FILES =
MOD_DIRS =
#endif

##
##
##

all: modgen mod_prepare modules

mod_prepare: modgen/modgen 
	for file in ${MOD_FILES}; do \
		if test -d $${file}; then \
	  	  echo Directory $${file} exists! Ignoring $${file}; \
		  echo Use make mod_clean or remove directory by hand; \
		elif test -f $${file}.mod; then \
		  ${MODGEN} $${file}.mod >$${file}.log ;\
		fi; \
	done

modgen/modgen:
	cd modgen; ${MAKE} install

modules: mod_prepare
	for SUBDIR in ${MOD_DIRS} ${MOD_FILES}; \
	do \
		if test -d $${SUBDIR}; then \
		   echo ${MAKE} $@ in $${SUBDIR}; \
		   ( cd $${SUBDIR} && ${MAKE} ;) \
		fi;\
		if test ! -d $${SUBDIR}; then \
		   echo directory $${SUBDIR} does not exist!; \
		fi;\
	done

clean:
	rm -f *.o *.lo *.so* *.la *~ core
	( cd modgen && ${MAKE} $@; )
	for SUBDIR in ${MOD_DIRS} ${MOD_FILES}; \
	do \
		if test -d $${SUBDIR}; then \
		   echo ${MAKE} $@ in $${SUBDIR}; \
		  if [ -e "$${SUBDIR}/Makefile" ]; then (cd $${SUBDIR}; $(MAKE) $@) fi \
		fi; \
	done

mod_clean:
	for SUBDIR in ${MOD_FILES}; \
	do \
		if test -d $${SUBDIR}; then \
		echo removing $${SUBDIR};\
		   rm -rf $${SUBDIR}; \
		fi; \
	done 

	for SUBDIR in ${MOD_DIRS}; \
	do \
		if test -d $${SUBDIR}; then \
		   echo ${MAKE} clean in $${SUBDIR}; \
		  if [ -e "$${SUBDIR}/Makefile" ]; then (cd $${SUBDIR}; $(MAKE) clean;) fi \
		fi; \
	done

distclean: clean mod_clean
	( cd modgen && ${MAKE} clean )
	for SUBDIR in ${MOD_DIRS}; \
	do \
		echo ${MAKE} $@ in $${SUBDIR}; \
		  if [ -e "$${SUBDIR}/Makefile" ]; then (cd $${SUBDIR}; $(MAKE) clean;) fi \
	done
	rm -f Makefile

install bindist: all
	(cd modgen; ${MAKE} $@)
	for SUBDIR in ${MOD_DIRS} ${MOD_FILES}; \
	do \
		echo ${MAKE} $@ in $${SUBDIR}; \
		( cd $${SUBDIR} && ${MAKE} $@;) || true; \
	done

install_all: install

install-bindist: all
	(cd modgen; ${MAKE} install_bindir=${install_bindir} $@)
	for SUBDIR in ${MOD_DIRS} ${MOD_FILES}; \
	do \
		echo ${MAKE} install_bindir=${install_bindir} $@ in $${SUBDIR}; \
		( cd $${SUBDIR} && ${MAKE} install_bindir=${install_bindir} $@;)|| true ;\
	done

depend:
	@echo "No make depend available!"