/*!
 * @file f5c.h
 * @brief Implementation of the variant F5C+ of 
 *        Faugere's F5 algorithm in the SINGULAR kernel
 * Implementation of variant F5C+ of Faugere's
 * F5 algorithm in the SINGULAR kernel. F5C+ reduces the computed Groebner 
 * bases after each iteration step, whereas F5 does not do this.
 *
 * LITERATURE:
 * - F5 Algorithm:  http://www-calfor.lip6.fr/~jcf/Papers/F02a.pdf
 * - F5C Algorithm: http://arxiv.org/abs/0906.2967
 * - F5+ Algorithm: to be confirmed
 */

#ifndef F5C_HEADER
#define F5C_HEADER

#ifdef HAVE_F5C

/** 
 * @struct \c F5Rules
 * @brief \c F5Rules is the structure of a rule checked in the F5 criterion
 * representing a monomial by an integer vector resp. a long (i.e. the short
 * exponent vector)
 */
struct F5Rules {
  int** label;
  long  slabel;
};

/** 
 * @struct \c RewRules
 * @brief \c RewRules is the structure of a rule checked in the Rewritten criterion
 * representing a monomial by an integer vector resp. a long (i.e. the short
 * exponent vector)
 */
struct RewRules {
  RewRules* next;
  int*      label;
  long      slabel;
};

/** 
 * @struct \c Lpoly 
 * @brief \c Lpoly is the structure of a linked list of labeled polynomials, 
 * i.e. elements consisting of a polynomial \c p and a label computed by F5C+ 
 * The label is defined as an integer vector resp. in a short exponent
 * vector form as a long in \c slabel . 
 * \c f5Rules and \c rewRules are an array resp. a list of rules (i.e. int vectors + shortExponentVectors) which are tested by the 
 * criteria of F5 in further computations.
 * \c redundant checks if the element is redundant for the gröbner basis. Note
 * that the elements are still non-redundant for F5C+. 
 */
struct Lpoly {
  Lpoly*          next;
  poly            p;
  int*            label;
  long            slabel;
  // keep this in mind for your idea about improving the check of rules and
  // making it parallizable:
  // The idea is to store for each labeled poly the uniquely defined lists of
  // F5Rules and RewRules where the multiplicities are even cancelled out. Thus
  // we have less checks (no multiples of rules are checked!) and no
  // multiplicities have to be computed when the rule checks are done.
  // -----------------------
  //struct F5Rules  f5Rules;
  //struct RewRules rewRules;
  // -----------------------   
  bool            redundant;
};

/** 
 * @struct \c Cpair 
 * @brief \c Cpair is the structure of the list of critical pairs in F5C+
 * containing the corresponding labeled polynomials \c lpi and the multipliers
 * \c multi (as integer vectors).
 */
struct Cpair {
    int*    mult1;
    Lpoly*  lp1;
    int*    mult2;
    Lpoly*  lp2;
};

/** 
 * @brief \c f5cMain() is the main function of the F5 implementation in the
 * Singular kernel. It starts the computations of a Groebner basis of \c F.
 * This is done iteratively on the generators of \c F and degree-wise in each
 * iteration step. 
 * The implemented version is not the standard F5 Algorithm, but the
 * variant F5C (for using reduced Groebner basis after each iteration step)
 * combined with the variant F5+ (for a guaranteed termination of the
 * algorithm).
 * NOTE that the input must be homogeneous to guarantee termination and
 * correctness.
 *
 * LITERATURE:
 * - F5 Algorithm:  http://www-calfor.lip6.fr/~jcf/Papers/F02a.pdf
 * - F5C Algorithm: http://arxiv.org/abs/0906.2967
 * - F5+ Algorithm: to be confirmed
 * 
 * @param \c F is the ideal for which a Groebner basis shall be computed.
 * @param \c Q is the quotientring.
 * 
 * @return 
 */
ideal f5cMain(ideal F, ideal Q = NULL); 

/** 
 * @brief \c f5cIter() computes a Groebner basis of < \c p , \c redGB > using
 * the criteria of Faugere's F5 Algorithm in the variant F5+.
 * 
 * @param \c p New element from the initial ideal \c F of \c f5cMain() which
 * starts the new iteration step.
 * @param \c redGB Already computed and afterwards reduced Groebner basis of
 * the generators up to element \c p of the input ideal \c F of \c f5cMain() .
 * 
 * @return A (possibly) not reduced Groebner basis of < \c p , \c redGB >.
 */
ideal f5cIter(poly p, ideal redGB); 
#endif
// HAVE_F5C
#endif
// F5C_HEADER
