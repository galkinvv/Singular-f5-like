/* emacs edit mode for this file is -*- C++ -*- */
/* $Id: gf_tabutil.h 12231 2009-11-02 10:12:22Z hannes $ */

#ifndef INCL_GF_TABUTIL_H
#define INCL_GF_TABUTIL_H

#include <config.h>

int gf_tab_numdigits62 ( int q );

char conv62 ( int i );

void convert62 ( int i, int n, char * p );

int convback62 ( char c );

int convertback62 ( char * p, int n );

#endif /* ! INCL_GF_TABUTIL_H */
