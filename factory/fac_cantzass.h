/* emacs edit mode for this file is -*- C++ -*- */
/* $Id: fac_cantzass.h 12231 2009-11-02 10:12:22Z hannes $ */

#ifndef INCL_FAC_CANTZASS_H
#define INCL_FAC_CANTZASS_H

#include <config.h>

#include "variable.h"
#include "canonicalform.h"

CFFList FpFactorizeUnivariateCZ( const CanonicalForm& f, bool issqrfree, int numext, const Variable alpha, const Variable beta );

//CFFList FpFactorizeUnivariateCZ( const CanonicalForm& f );

#endif /* ! INCL_FAC_CANTZASS_H */
