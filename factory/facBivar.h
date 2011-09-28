/*****************************************************************************\
 * Computer Algebra System SINGULAR
\*****************************************************************************/
/** @file facBivar.h
 *
 * bivariate factorization over Q(a)
 *
 * @author Martin Lee
 *
 * @internal @version \$Id$
 *
 **/
/*****************************************************************************/

#ifndef FAC_BIVAR_H
#define FAC_BIVAR_H

#include <config.h>

#include "assert.h"

#include "facFqBivarUtil.h"
#include "DegreePattern.h"
#include "cf_util.h"
#include "facFqSquarefree.h"
#include "cf_map.h"
#include "cfNewtonPolygon.h"
#include "algext.h"

/// @return @a biFactorize returns a list of factors of F. If F is not monic
///         its leading coefficient is not outputted.
CFList
biFactorize (const CanonicalForm& F,       ///< [in] a bivariate poly
             const Variable& v             ///< [in] some algebraic variable
            );

/// factorize a squarefree bivariate polynomial over \f$ Q(\alpha) \f$.
///
/// @ return @a ratBiSqrfFactorize returns a list of monic factors, the first
///         element is the leading coefficient.
inline
CFList ratBiSqrfFactorize (const CanonicalForm & G, ///< [in] a bivariate poly
                           const Variable& v= Variable (1)
                         )
{
  CFMap N;
  CanonicalForm F= compress (G, N);
  CanonicalForm contentX= content (F, 1);
  CanonicalForm contentY= content (F, 2);
  F /= (contentX*contentY);
  CFFList contentXFactors, contentYFactors;
  if (v.level() != 1)
  {
    contentXFactors= factorize (contentX, v);
    contentYFactors= factorize (contentY, v);
  }
  else
  {
    contentXFactors= factorize (contentX);
    contentYFactors= factorize (contentY);
  }
  if (contentXFactors.getFirst().factor().inCoeffDomain())
    contentXFactors.removeFirst();
  if (contentYFactors.getFirst().factor().inCoeffDomain())
    contentYFactors.removeFirst();
  if (F.inCoeffDomain())
  {
    CFList result;
    for (CFFListIterator i= contentXFactors; i.hasItem(); i++)
      result.append (N (i.getItem().factor()));
    for (CFFListIterator i= contentYFactors; i.hasItem(); i++)
      result.append (N (i.getItem().factor()));
    if (isOn (SW_RATIONAL))
    {
      normalize (result);
      result.insert (Lc (G));
    }
    return result;
  }
  mat_ZZ M;
  vec_ZZ S;
  cout << "before compress" << "\n";
  F= compress (F, M, S);
  cout << "after compress" << "\n";
  CFList result= biFactorize (F, v);
  for (CFListIterator i= result; i.hasItem(); i++)
    i.getItem()= N (decompress (i.getItem(), M, S));
  for (CFFListIterator i= contentXFactors; i.hasItem(); i++)
    result.append (N(i.getItem().factor()));
  for (CFFListIterator i= contentYFactors; i.hasItem(); i++)
    result.append (N (i.getItem().factor()));
  if (isOn (SW_RATIONAL))
  {
    normalize (result);
    result.insert (Lc (G));
  }
  return result;
}

/// factorize a bivariate polynomial over \f$ Q(\alpha) \f$
///
/// @return @a ratBiFactorize returns a list of monic factors with
///         multiplicity, the first element is the leading coefficient.
inline
CFFList ratBiFactorize (const CanonicalForm & G, ///< [in] a bivariate poly
                        const Variable& v= Variable (1)
                      )
{
  clock_t start= clock();
  CFMap N;
  CanonicalForm F= compress (G, N);
  CanonicalForm LcF= Lc (F);
  if (isOn (SW_RATIONAL))
    F *= bCommonDen (F);
  CanonicalForm contentX= content (F, 1);
  CanonicalForm contentY= content (F, 2);
  F /= (contentX*contentY);
  if (isOn (SW_RATIONAL))
    F *= bCommonDen (F);
  CFFList contentXFactors, contentYFactors;
  if (v.level() != 1)
  {
    contentXFactors= factorize (contentX, v);
    contentYFactors= factorize (contentY, v);
  }
  else
  {
    contentXFactors= factorize (contentX);
    contentYFactors= factorize (contentY);
  }
  if (contentXFactors.getFirst().factor().inCoeffDomain())
    contentXFactors.removeFirst();
  if (contentYFactors.getFirst().factor().inCoeffDomain())
    contentYFactors.removeFirst();
  decompress (contentXFactors, N);
  decompress (contentYFactors, N);
  CFFList result;
  if (F.inCoeffDomain())
  {
    result= Union (contentXFactors, contentYFactors);
    if (isOn (SW_RATIONAL))
    {
      normalize (result);
      result.insert (CFFactor (LcF, 1));
    }
    return result;
  }
  mat_ZZ M;
  vec_ZZ S;
    cout << "degree (F) before= " << degree (F) << "\n";
    cout << "degree (F,1) before= " << degree (F,1) << "\n";
  F= compress (F, M, S);
  cout << "time for stuff before sqrfPart= " << (double) (clock() - start)/CLOCKS_PER_SEC << "\n";
  /*start= clock();
  CanonicalForm sqrfP= sqrfPart (F);
  cout << "time for sqrfPart= " << (double) (clock() - start)/CLOCKS_PER_SEC << "\n";*/

  /*if (v.level() == 1)
  {*/
    cout << "degree (F)= " << degree (F) << "\n";
    cout << "degree (F,1)= " << degree (F,1) << "\n";
    cout << "size (F)= " << size (F) << "\n";
    //cout << "F= " << F << "\n";
      start= clock();
    CFFList sqrfFactors= sqrFree (F);
    cout << "sqrfFactors= " << sqrfFactors << "\n";
    //cout << "F= " << F << "\n";
  //}
  cout << "time for sqrfree= " << (double) (clock() - start)/CLOCKS_PER_SEC << "\n";
  cout << "result= " << result << "\n";
  for (CFFListIterator i= sqrfFactors; i.hasItem(); i++)
  {
    start= clock();
    CFList tmp= ratBiSqrfFactorize (i.getItem().factor(), v);
    cout << "time for sqrfFactorize= " << (double) (clock() - start)/CLOCKS_PER_SEC << "\n";
    cout << "tmp= " << tmp << "\n";
    for (CFListIterator j= tmp; j.hasItem(); j++)
    {
      if (j.getItem().inCoeffDomain()) continue;
      result.append (CFFactor (N (decompress (j.getItem(), M, S)), i.getItem().exp()));
    }
  }
  result= Union (result, contentXFactors);
  result= Union (result, contentYFactors);
  if (isOn (SW_RATIONAL))
  {
    normalize (result);
    result.insert (CFFactor (LcF, 1));
  }
  return result;

  /*//exit (-1);
  start= clock();
  CFList buf;
  buf= biFactorize (sqrfP, v);
  cout << "buf= " << buf << "\n";
  cout << "time for biFactorize= " << (double) (clock() - start)/CLOCKS_PER_SEC << "\n";
  start= clock();
  result= multiplicity (F, buf);
  cout << "time for multiplicity= " << (double) (clock() - start)/CLOCKS_PER_SEC << "\n";
  for (CFFListIterator i= result; i.hasItem(); i++)
    i.getItem()= CFFactor (N (decompress (i.getItem().factor(), M, S)),
                             i.getItem().exp());
  result= Union (result, contentXFactors);
  result= Union (result, contentYFactors);
  if (isOn (SW_RATIONAL))
  {
    normalize (result);
    result.insert (CFFactor (LcF, 1));
  }
  return result;*/
}

/// convert a CFFList to a CFList by dropping the multiplicity
CFList conv (const CFFList& L ///< [in] a CFFList
            );

#endif

