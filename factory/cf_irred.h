/* emacs edit mode for this file is -*- C++ -*- */
/* $Id: cf_irred.h 12231 2009-11-02 10:12:22Z hannes $ */

#ifndef INCL_CF_IRRED_H
#define INCL_CF_IRRED_H

#include <config.h>

#include "canonicalform.h"
#include "cf_random.h"

/*BEGINPUBLIC*/

CanonicalForm find_irreducible ( int deg, CFRandom & gen, const Variable & x );

/*ENDPUBLIC*/

#endif /* ! INCL_CF_IRRED_H */
