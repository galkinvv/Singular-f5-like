/*****************************************************************************\
 * Computer Algebra System SINGULAR    
\*****************************************************************************/
/** @file lineareAlgebra.cc
 *
 * This file implements basic linear algebra functionality.
 *
 * For more general information, see the documentation in
 * lineareAlgebra.h.
 *
 * @author Frank Seelisch
 *
 * @internal @version \$Id$
 *
 **/
/*****************************************************************************/

// include header files
#include "mod2.h"
#include "structs.h"
#include "polys.h"
#include "ideals.h"
#include "numbers.h"
#include "matpol.h"
#include "linearAlgebra.h"

/**
 * The returned score is based on the implementation of 'nSize' for
 * numbers (, see numbers.h): nSize(n) provides a measure for the
 * complexity of n. Thus, less complex pivot elements will be
 * prefered, and get therefore a smaller pivot score. Consequently,
 * we simply return the value of nSize.
 * An exception to this rule are the ground fields R, long R, and
 * long C: In these, the result of nSize relates to |n|. And since
 * a larger modulus of the pivot element ensures a numerically more
 * stable Gauss elimination, we would like to have a smaller score
 * for larger values of |n|. Therefore, in R, long R, and long C,
 * the negative of nSize will be returned.
 **/
int pivotScore(number n)
{
  int s = nSize(n);
  if (rField_is_long_C(currRing) ||
      rField_is_long_R(currRing) ||
      rField_is_R(currRing))
    return -s;
  else
    return s;
}

/**
 * This code computes a score for each non-zero matrix entry in
 * aMat[r1..r2, c1..c2]. If all entries are zero, false is returned,
 * otherwise true. In the latter case, the minimum of all scores
 * is sought, and the row and column indices of the corresponding
 * matrix entry are stored in bestR and bestC.
 **/
bool pivot(const matrix aMat, const int r1, const int r2, const int c1,
           const int c2, int* bestR, int* bestC)
{
  int bestScore; int score; bool foundBestScore = false; poly matEntry;

  for (int c = c1; c <= c2; c++)
  {
    for (int r = r1; r <= r2; r++)
    {
      matEntry = MATELEM(aMat, r, c);
      if (matEntry != NULL)
      {
        score = pivotScore(pGetCoeff(matEntry));
        if ((!foundBestScore) || (score < bestScore))
        {
          bestScore = score;
          *bestR = r;
          *bestC = c;
        }
        foundBestScore = true;
      }
    }
  }

  return foundBestScore;
}

void luDecomp(const matrix aMat, matrix &pMat, matrix &lMat, matrix &uMat)
{
  int rr = aMat->rows();
  int cc = aMat->cols();
  pMat = mpNew(rr, rr);
  lMat = mpNew(rr, rr);
  uMat = mpNew(rr, cc);
  /* copy aMat into uMat: */
  for (int r = 1; r <= rr; r++)
    for (int c = 1; c <= cc; c++)
      MATELEM(uMat, r, c) = pCopy(aMat->m[c - 1 + (r - 1) * cc]);

  /* we use an int array to store all row permutations;
     note that we only make use of the entries [1..rr] */
  int* permut = new int[rr + 1];
  for (int i = 1; i <= rr; i++) permut[i] = i;
  
  /* fill lMat with the (rr x rr) unit matrix */
  for (int r = 1; r <= rr; r++) MATELEM(lMat, r, r) = pOne();

  int bestR; int bestC; int intSwap; poly pSwap;
  for (int r = 1; r < rr; r++)
  {
    if ((r <= cc) && (pivot(uMat, r, rr, r, r, &bestR, &bestC)))
    {
      /* swap rows with indices r and bestR in permut */
      intSwap = permut[r];
      permut[r] = permut[bestR];
      permut[bestR] = intSwap;

      /* swap rows with indices r and bestR in uMat;
         it is sufficient to do this for columns >= r */
      for (int c = r; c <= cc; c++)
      {
        pSwap = MATELEM(uMat, r, c);
        MATELEM(uMat, r, c) = MATELEM(uMat, bestR, c);
        MATELEM(uMat, bestR, c) = pSwap;
      }

      /* swap rows with indices r and bestR in lMat;
         we must do this only for columns < r */
      for (int c = 1; c < r; c++)
      {
        pSwap = MATELEM(lMat, r, c);
        MATELEM(lMat, r, c) = MATELEM(lMat, bestR, c);
        MATELEM(lMat, bestR, c) = pSwap;
      }

      /* perform next Gauss elimination step, i.e., below the
         row with index r;
         we need to adjust lMat and uMat;
         we are certain that the matrix entry at [r, r] is non-zero: */
      number pivotElement = pGetCoeff(MATELEM(uMat, r, r));
      poly p; number n;
      for (int rGauss = r + 1; rGauss <= rr; rGauss++)
      {
        p = MATELEM(uMat, rGauss, r);
        if (p != NULL)
        {
          n = nDiv(pGetCoeff(p), pivotElement);

          /* filling lMat;
             old entry was zero, so no need to call pDelete(.) */
          MATELEM(lMat, rGauss, r) = pNSet(nCopy(n));

          /* adjusting uMat: */
          MATELEM(uMat, rGauss, r) = NULL; pDelete(&p);
          n = nNeg(n);
          for (int cGauss = r + 1; cGauss <= cc; cGauss++)
            MATELEM(uMat, rGauss, cGauss)
              = pAdd(MATELEM(uMat, rGauss, cGauss),
                     ppMult_nn(MATELEM(uMat, r, cGauss), n));

          nDelete(&n); /* clean up n */
        }
      }
    }
  }

  /* building the permutation matrix from 'permut' */
  for (int r = 1; r <= rr; r++)
    MATELEM(pMat, r, permut[r]) = pOne();
  delete[] permut;

  return;
}

/**
 * This code first computes the LU-decomposition of aMat,
 * and then calls the method for inverting a matrix which
 * is given by its LU-decomposition.
 **/
bool luInverse(const matrix aMat, matrix &iMat)
{ /* aMat is guaranteed to be an (n x n)-matrix */
  int d = aMat->rows();

  matrix pMat;
  matrix lMat;
  matrix uMat;
  luDecomp(aMat, pMat, lMat, uMat);
  bool result = luInverseFromLUDecomp(pMat, lMat, uMat, iMat);

  /* clean-up */
  idDelete((ideal*)&pMat);
  idDelete((ideal*)&lMat);
  idDelete((ideal*)&uMat);

  return result;
}

bool upperRightTriangleInverse(const matrix uMat, matrix &iMat,
                               bool diagonalIsOne)
{
  int d = uMat->rows();
  poly p; poly q;

  /* check whether uMat is invertible */
  bool invertible = diagonalIsOne;
  if (!invertible)
  {
    invertible = true;
    for (int r = 1; r <= d; r++)
    {
      if (MATELEM(uMat, r, r) == NULL)
      {
        invertible = false;
        break;
      }
    }
  }

  if (invertible)
  {
    iMat = mpNew(d, d);
    for (int r = d; r >= 1; r--)
    {
      if (diagonalIsOne)
        MATELEM(iMat, r, r) = pOne();
      else
        MATELEM(iMat, r, r) = pNSet(nInvers(pGetCoeff(MATELEM(uMat, r, r))));
      for (int c = r + 1; c <= d; c++)
      {
        p = NULL;
        for (int k = r + 1; k <= c; k++)
        {
          q = ppMult_qq(MATELEM(uMat, r, k), MATELEM(iMat, k, c));
          p = pAdd(p, q);
        }
        p = pNeg(p);
        p = pMult(p, pCopy(MATELEM(iMat, r, r)));
        MATELEM(iMat, r, c) = p;
      }
    }
  }

  return invertible;
}

bool lowerLeftTriangleInverse(const matrix lMat, matrix &iMat,
                              bool diagonalIsOne)
{
  int d = lMat->rows(); poly p; poly q;

  /* check whether lMat is invertible */
  bool invertible = diagonalIsOne;
  if (!invertible)
  {
    invertible = true;
    for (int r = 1; r <= d; r++)
    {
      if (MATELEM(lMat, r, r) == NULL)
      {
        invertible = false;
        break;
      }
    }
  }

  if (invertible)
  {
    iMat = mpNew(d, d);
    for (int c = d; c >= 1; c--)
    {
      if (diagonalIsOne)
        MATELEM(iMat, c, c) = pOne();
      else
        MATELEM(iMat, c, c) = pNSet(nInvers(pGetCoeff(MATELEM(lMat, c, c))));
      for (int r = c + 1; r <= d; r++)
      {
        p = NULL;
        for (int k = c; k <= r - 1; k++)
        {
          q = ppMult_qq(MATELEM(lMat, r, k), MATELEM(iMat, k, c));
          p = pAdd(p, q);
        }
        p = pNeg(p);
        p = pMult(p, pCopy(MATELEM(iMat, c, c)));
        MATELEM(iMat, r, c) = p;
      }
    }
  }

  return invertible;
}

/**
 * This code computes the inverse by inverting lMat and uMat, and
 * then performing two matrix multiplications.
 **/
bool luInverseFromLUDecomp(const matrix pMat, const matrix lMat,
                           const matrix uMat, matrix &iMat)
{ /* uMat is guaranteed to be quadratic */
  int d = uMat->rows();

  matrix lMatInverse; /* for storing the inverse of lMat;
                         this inversion will always work                */
  matrix uMatInverse; /* for storing the inverse of uMat, if invertible */

  bool result = upperRightTriangleInverse(uMat, uMatInverse, false);
  if (result)
  {
    /* next will always work, since lMat is known to have all diagonal
       entries equal to 1 */
    lowerLeftTriangleInverse(lMat, lMatInverse, true);
    iMat = mpMult(mpMult(uMatInverse, lMatInverse), pMat);
    
    /* clean-up */
    idDelete((ideal*)&lMatInverse);
    idDelete((ideal*)&uMatInverse);
  }

  return result;
}