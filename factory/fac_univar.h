/* emacs edit mode for this file is -*- C++ -*- */
/* $Id: fac_univar.h 12231 2009-11-02 10:12:22Z hannes $ */

#ifndef INCL_FAC_UNIVAR_H
#define INCL_FAC_UNIVAR_H

#include <config.h>

#include "canonicalform.h"
#include "fac_util.h"

CFFList ZFactorizeUnivariate( const CanonicalForm& ff, bool issqrfree = false );

modpk getZFacModulus();

#endif /* ! INCL_FAC_UNIVAR_H */
