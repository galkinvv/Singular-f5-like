# Generated automatically from Makefile.in by configure.
## Makefile for integer programming
SINGUNAME       = ix86-Win
##
## various paths
##
bindir          = /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win
prefix          = /cygdrive/c/lapa/sing/Singular-f5-like
slibdir         = ${prefix}/LIB
install_bindir  = ${install_prefix}/${SINGUNAME}
libdir          = /cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win/lib


##
## various programs
##

CXX             = c++
## gcc won't work
ifeq ($(CXX),gcc)
CXX := c++
endif

INSTALL		= /usr/bin/install -c
INSTALL_PROGRAM	= ${INSTALL}  -s
MKINSTALLDIRS   = ../mkinstalldirs

##
## compiler and linker options
##
CPPFLAGS	= -I. -I/cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win/include 
CXXFLAGS        = -O
LDFLAGS         = -L${libdir} -L/cygdrive/c/lapa/sing/Singular-f5-like/ix86-Win/lib -g -lgmp


MAIN1	:= solve_IP
OBJECTS1:= $(MAIN1).o

MAIN2	:= change_cost
OBJECTS2:= $(MAIN2).o

MAIN3	:= toric_ideal
OBJECTS3:= $(MAIN3).o

MAIN4   := gen_test
OBJECTS4:= $(MAIN4).o

LLL   := LLL
OBJECTS_LLL:= LLL_lattice_to_send.o

%.o: %.cc si_gcc_v.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

all: $(MAIN1) $(MAIN2) $(MAIN3) $(MAIN4) $(LLL)

install-nolns: install

install_all: install

install install-libsingular: $(MAIN1) $(MAIN2) $(MAIN3) $(MAIN4) $(LLL)
	${MKINSTALLDIRS} ${bindir}
	${INSTALL_PROGRAM} $(MAIN1) ${bindir}
	${INSTALL_PROGRAM} $(MAIN2) ${bindir}
	${INSTALL_PROGRAM} $(MAIN3) ${bindir}
	${INSTALL_PROGRAM} $(MAIN4) ${bindir}
	${INSTALL_PROGRAM} $(LLL) ${bindir}

install-bindist: $(MAIN1) $(MAIN2) $(MAIN3) $(MAIN4)
	${MKINSTALLDIRS} ${install_bindir}
	${INSTALL_PROGRAM} -s $(MAIN1) ${install_bindir}
	${INSTALL_PROGRAM} -s $(MAIN2) ${install_bindir}
	${INSTALL_PROGRAM} -s $(MAIN3) ${install_bindir}
	${INSTALL_PROGRAM} -s $(MAIN4) ${install_bindir}
	${INSTALL_PROGRAM} -s $(LLL) ${install_bindir}

clean: 
	rm -f *.o *~  $(MAIN1) $(MAIN2) $(MAIN3) $(MAIN4) $(LLL) si_gcc_v.h

depend:
	@echo "No make depend available!"

distclean: clean
	-rm -f ${bindir}/$(MAIN1)
	-rm -f ${bindir}/$(MAIN2)
	-rm -f ${bindir}/$(MAIN3)
	-rm -f ${bindir}/$(MAIN4)
	-rm -f ${bindir}/$(LLL)

si_gcc_v.h:
	./gccversion.sh

$(MAIN1): term_ordering.o binomial.o list.o BigInt.o LLL.o matrix.o \
	ideal.o \
	Buchberger.o ideal_stuff.o IP_algorithms.o testdata.o \
	$(OBJECTS1)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(MAIN2): term_ordering.o binomial.o list.o BigInt.o LLL.o matrix.o \
	ideal.o \
	Buchberger.o ideal_stuff.o IP_algorithms.o testdata.o  \
	$(OBJECTS2)
	$(CXX)  $^ -o $@ $(LDFLAGS)

$(MAIN3): term_ordering.o binomial.o list.o BigInt.o LLL.o matrix.o \
	ideal.o \
	Buchberger.o ideal_stuff.o IP_algorithms.o testdata.o \
	$(OBJECTS3)
	$(CXX)  $^ -o $@ $(LDFLAGS)

$(MAIN4): term_ordering.o binomial.o list.o BigInt.o LLL.o matrix.o \
	ideal.o \
	Buchberger.o ideal_stuff.o IP_algorithms.o testdata.o \
	$(OBJECTS4)
	$(CXX)  $^ -o $@ $(LDFLAGS)

$(LLL): $(OBJECTS_LLL)
	$(CXX)  $^ -o $@ $(LDFLAGS)

Makefile: Makefile.in 
	cd ..; 	CONFIG_FILES="IntegerProgramming/Makefile" CONFIG_HEADERS= ./config.status

