#
#
#
topsrcdir	= ..
srcdir		= .
prefix 		= /cygdrive/c/lapa/sing/Singular-f5-like
exec_prefix 	= /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win
libdir 		= /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win/lib
includedir	= /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win/include
# program executable goes here
bindir		= /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win
install_bindir	= /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win
# Singular libs go here
includedir	= /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win/include
MOD_DEST	= ./include
INC_SRC		= $(topsrcdir)/Singular

##
## various programs
##

CC		= gcc
LD              = gcc
CXX		= g++
LEX		= sh ../../Singular/flexer.sh
PERL		= @PERL@
BISON		= bison

SINGUNAME	= ix86-Win
SING_UNAME	= ix86_Win
SINGULAR_VERSION = 3-1-4
S_VERSION       = $${SINGULAR_VERSION-3-1-4}
DISTROOT_NAME   = Singular-${S_VERSION}
BINDIST_NAME    = ${DISTROOT_NAME}-${SINGUNAME}
SHAREDIST_NAME  = ${DISTROOT_NAME}-share
MKINSTALLDIRS   = ../mkinstalldirs
LN_S            = ln -s
INSTALL 	= $(INSTALL_SH)
INSTALL_PROGRAM	= ${INSTALL}
INSTALL_DATA	= ${INSTALL} -m 644
INSTALL_SH 	= $(topsrcdir)/./../install-sh -c
MODGEN		= $(bindir)/modgen

##
## compiler and linker options
##
CFLAGS	+= --no-rtti --no-exceptions -O3 -w -fomit-frame-pointer -pipe -fno-implicit-templates \
	-g -I${includedir} -I../include -I${topsrcdir}/.. -DNDEBUG -DMODULE_GENERATOR \
	-D${SING_UNAME}
LIBS	+= -L/usr/local/lib

OBJS	= main.o mod_grammar.o scanner.o misc.o makefile.o utils.o \
	creat_top.o proc.o proc_setup.o getopt.o getopt1.o

############################################################
###
###
############################################################
all	= modgen

modgen: pathnames.h ${OBJS} modgen.h decl.inc typmap.h stype.h
	$(LD) -o $@ ${CFLAGS} ${OBJS} ${LIBS}

install bindist: modgen
	${MKINSTALLDIRS} ${bindir}
	${INSTALL_PROGRAM} modgen ${bindir}/modgen-${SINGULAR_VERSION}
	rm -f ${bindir}/modgen
	cd ${bindir}; ${LN_S} modgen-${SINGULAR_VERSION} modgen

install-bindist: modgen
	${MKINSTALLDIRS} ${install_bindir}
	${INSTALL_PROGRAM} modgen ${install_bindir}/modgen-${SINGULAR_VERSION}
	rm -f ${install_bindir}/modgen
	cd ${install_bindir}; ${LN_S} modgen-${SINGULAR_VERSION} modgen

############################################################
###
###
############################################################
.SUFFIXES: .o .so .dll .lo .y

.cc.o:
	$(CXX) -c ${CFLAGS} $<

.c.o:
	$(CC) -c ${CFLAGS} $<

.y.cc:
	@if test -r mod_grammar.cc; then \
                touch mod_grammar.cc ;\
        else \
        if test "x${BISON}" = x; then \
                echo Error: no bison given, could not rebuilt grammar.cc;\
                exit 1; \
        fi;\
        ${BISON} -d -t -o mod_grammar.cc $<;\
        ./mvbison;\
        fi

pathnames.h:
	echo "/*" > pathnames.h
	echo " *" >> pathnames.h
	echo " */" >> pathnames.h
	echo "" >> pathnames.h
	echo "#define TOPSRCDIR \"$(topsrcdir)\"" >> pathnames.h
	echo "#define SINGUNAME \"$(SINGUNAME)\"" >> pathnames.h

scanner.cc: scanner.l mod_grammar.h modgen.h
	@if test -r scanner.cc; then \
		touch scanner.cc ;\
	else \
	if test "x${LEX}" = x; then \
		echo Error: no lex given, could not rebuilt scanner.cc;\
                exit 1; \
	fi;\
	fi
	${LEX} -s -I -t scanner.l > scanner.cc.lmp
	cp scanner.cc.lmp scanner.cc

#	$(LEX) -Pyymod scanner.l > scanner.cc

############################################################
###
###
############################################################
clean:
	rm -f *.o core modgen
	rm -f decl.inc 
	rm -f pathnames.h

distclean: clean
	rm -f a.out *~ 
	rm -f mod_grammar.cc mod_grammar.h decl.inc 
#	rm -f Makefile


#
#
#
test:	modgen
	rm -rf tmp
	mkdir tmp
	./modgen ../kernel/kernel.mod

#
#
#
decl.inc: ../../Singular/grammar.h ../../Singular/tok.h
	-echo "/* declaration for modgen.cc */" > $@
	-grep "^#define" ../../Singular/grammar.h | awk \
		'{print "\tcase "$$2": strcpy(name,\""$$2"\"); break;"}' >> $@
	-echo "" >> $@
	-echo "/* declaration from tok.h */" >> $@
	-grep "^  [A-Z_]*," ../../Singular/tok.h | sed "s/,//g" | awk \
		'{print "\tcase "$$1": strcpy(name,\""$$1"\"); break;"}'>>$@

############################################################
###
###
############################################################
makefile.cc:	pathnames.h
misc.cc:	modgen.h decl.inc
utils.cc:	modgen.h
mod_grammar.cc:	mod_grammar.y
mod_grammar.h:	mod_grammar.y
