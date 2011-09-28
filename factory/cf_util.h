/* emacs edit mode for this file is -*- C++ -*- */
/* $Id: cf_util.h 13618 2010-11-09 11:59:33Z hannes $ */

#ifndef INCL_CF_UTIL_H
#define INCL_CF_UTIL_H

//{{{ docu
//
// cf_util.h - header to cf_util.cc.
//
//}}}

#include <config.h>

int ipower ( int b, int n );
int ilog2 (int a);

/*BEGINPUBLIC*/
void factoryError_intern(const char *s);
extern void (*factoryError)(const char *s);
/*ENDPUBLIC*/


#endif /* ! INCL_CF_UTIL_H */
