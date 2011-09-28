/* emacs edit mode for this file is -*- C++ -*- */
/* $Id: fac_berlekamp.h 12231 2009-11-02 10:12:22Z hannes $ */

#ifndef INCL_FAC_BERLEKAMP_H
#define INCL_FAC_BERLEKAMP_H

#include <config.h>

#include "canonicalform.h"

CFFList FpFactorizeUnivariateB ( const CanonicalForm & f, bool issqrfree = false );

#endif /* ! INCL_FAC_BERLEKAMP_H */
