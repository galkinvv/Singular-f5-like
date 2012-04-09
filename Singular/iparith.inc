/****************************************
*  Computer Algebra System SINGULAR     *
****************************************/

// syntax table for Singular
//
// - search for an exact match of the argument types
// - otherwise search for the first possibility
//   with converted types of the arguments
// - otherwise report an error
//
// operation: ++ (identifier)  ->  nothing
// operation: -- (identifier)  ->  nothing
// operation: - (int)  ->  int
// operation: - (bigint)  ->  bigint
// operation: - (number)  ->  number
// operation: - (poly)  ->  poly
// operation: - (vector)  ->  vector
// operation: - (matrix)  ->  matrix
// operation: - (intvec)  ->  intvec
// operation: - (intmat)  ->  intmat
// operation: ( (proc)  ->  any_type
// operation: attrib (def)  ->  nothing
// operation: bareiss (module)  ->  list
// operation: betti (list)  ->  intmat
// operation: betti (resolution)  ->  intmat
// operation: betti (ideal)  ->  intmat
// operation: betti (module)  ->  intmat
// operation: bigint (bigint)  ->  bigint
// operation: bigint (number)  ->  bigint
// operation: bigint (poly)  ->  bigint
// operation: char (ring)  ->  int
// operation: char (qring)  ->  int
// operation: char_series (ideal)  ->  matrix
// operation: charstr (ring)  ->  string
// operation: charstr (qring)  ->  string
// operation: close (link)  ->  nothing
// operation: ncols (matrix)  ->  int
// operation: ncols (ideal)  ->  int
// operation: ncols (module)  ->  int
// operation: ncols (intmat)  ->  int
// DUMMY // operation: ncols (intvec)  ->  $INVALID$
// operation: cleardenom (poly)  ->  poly
// operation: cleardenom (vector)  ->  vector
// operation: size (bigint)  ->  int
// operation: size (number)  ->  int
// operation: size (resolution)  ->  int
// operation: size (string)  ->  int
// operation: size (poly)  ->  int
// operation: size (vector)  ->  int
// operation: size (ideal)  ->  int
// operation: size (module)  ->  int
// operation: size (matrix)  ->  int
// operation: size (intvec)  ->  int
// operation: size (intmat)  ->  int
// operation: size (list)  ->  int
// operation: size (ring)  ->  int
// operation: def (int)  ->  def
// DUMMY // operation: def (any_type)  ->  $INVALID$
// operation: deg (poly)  ->  int
// operation: deg (vector)  ->  int
// operation: deg (matrix)  ->  int
// operation: degree (ideal)  ->  string
// operation: degree (module)  ->  string
// operation: defined (def)  ->  int
// operation: det (intmat)  ->  int
// operation: det (matrix)  ->  poly
// operation: det (module)  ->  poly
// operation: dim (ideal)  ->  int
// operation: dim (module)  ->  int
// operation: dim (resolution)  ->  int
// operation: dump (link)  ->  nothing
// operation: gen (int)  ->  vector
// operation: execute (string)  ->  nothing
// operation: ERROR (string)  ->  nothing
// operation: factorize (poly)  ->  list
// operation: finduni (ideal)  ->  ideal
// operation: freemodule (int)  ->  module
// operation: facstd (ideal)  ->  list
// operation: getdump (link)  ->  nothing
// operation: highcorner (ideal)  ->  poly
// operation: highcorner (module)  ->  vector
// operation: hilb (ideal)  ->  nothing
// operation: hilb (module)  ->  nothing
// operation: hilb (intvec)  ->  intvec
// operation: homog (ideal)  ->  int
// operation: homog (module)  ->  int
// operation: ideal (ideal)  ->  ideal
// operation: ideal (vector)  ->  ideal
// operation: ideal (matrix)  ->  ideal
// operation: ideal (qring)  ->  ideal
// operation: ideal (ring)  ->  ideal
// operation: ideal (map)  ->  ideal
// operation: impart (number)  ->  number
// operation: indepSet (ideal)  ->  intvec
// operation: int (int)  ->  int
// operation: int (bigint)  ->  int
// operation: int (number)  ->  int
// operation: int (poly)  ->  int
// operation: interred (ideal)  ->  ideal
// operation: interred (module)  ->  module
// operation: intmat (intmat)  ->  intmat
// operation: intvec (intmat)  ->  intvec
// operation: intvec (intvec)  ->  intvec
// operation: rvar (poly)  ->  int
// operation: rvar (string)  ->  int
// operation: rvar (any_type)  ->  int
// operation: jacob (poly)  ->  ideal
// operation: jacob (ideal)  ->  matrix
// operation: jacob (module)  ->  module
// operation: janet (ideal)  ->  ideal
// operation: kbase (ideal)  ->  ideal
// operation: kbase (module)  ->  module
// operation: ludecomp (matrix)  ->  list
// operation: primefactors (bigint)  ->  list
// operation: primefactors (number)  ->  list
// operation: killattrib (identifier)  ->  nothing
// operation: lead (poly)  ->  poly
// operation: lead (ideal)  ->  ideal
// operation: lead (vector)  ->  vector
// operation: lead (module)  ->  module
// operation: leadcoef (poly)  ->  number
// operation: leadcoef (vector)  ->  number
// operation: leadexp (poly)  ->  intvec
// operation: leadexp (vector)  ->  intvec
// operation: leadmonom (poly)  ->  poly
// operation: leadmonom (vector)  ->  vector
// operation: link (link)  ->  link
// operation: list (def)  ->  list
// DUMMY // operation: map (any_type)  ->  $INVALID$
// operation: matrix (matrix)  ->  matrix
// operation: maxideal (int)  ->  ideal
// operation: memory (int)  ->  bigint
// operation: minbase (ideal)  ->  ideal
// operation: minbase (module)  ->  module
// operation: minres (list)  ->  list
// operation: minres (resolution)  ->  resolution
// operation: module (module)  ->  module
// operation: monitor (link)  ->  nothing
// operation: monomial (intvec)  ->  poly
// operation: mult (ideal)  ->  int
// operation: mult (module)  ->  int
// operation: mstd (ideal)  ->  list
// operation: mstd (module)  ->  list
// operation: nameof (any_type)  ->  string
// operation: names (int)  ->  list
// operation: names (package)  ->  list
// operation: names (ring)  ->  list
// operation: names (qring)  ->  list
// operation: number (number)  ->  number
// operation: number (poly)  ->  number
// operation: number (bigint)  ->  number
// operation: npars (ring)  ->  int
// operation: npars (qring)  ->  int
// operation: nvars (ring)  ->  int
// operation: nvars (qring)  ->  int
// operation: open (link)  ->  nothing
// operation: ord (poly)  ->  int
// operation: ord (vector)  ->  int
// operation: ordstr (ring)  ->  string
// operation: ordstr (qring)  ->  string
// operation: par (int)  ->  number
// operation: pardeg (number)  ->  int
// operation: parstr (int)  ->  string
// operation: parstr (ring)  ->  string
// operation: parstr (qring)  ->  string
// operation: poly (poly)  ->  poly
// operation: poly (bigint)  ->  poly
// operation: preimage (map)  ->  ring
// operation: prime (int)  ->  int
// operation: print (list)  ->  string
// operation: print (def)  ->  string
// operation: proc (proc)  ->  proc
// operation: prune (module)  ->  module
// operation: qhweight (ideal)  ->  intvec
// operation: qhweight (module)  ->  intvec
// DUMMY // operation: qring (any_type)  ->  $INVALID$
// operation: rank (matrix)  ->  int
// operation: read (link)  ->  string
// operation: regularity (list)  ->  int
// operation: repart (number)  ->  number
// operation: reservedName (string)  ->  int
// operation: resolution (list)  ->  resolution
// operation: resolution (resolution)  ->  resolution
// operation: ringlist (ring)  ->  list
// operation: ringlist (qring)  ->  list
// operation: ring (ring)  ->  ring
// operation: ring (list)  ->  ring
// operation: nrows (vector)  ->  int
// operation: nrows (module)  ->  int
// operation: nrows (matrix)  ->  int
// operation: nrows (intmat)  ->  int
// operation: nrows (intvec)  ->  int
// operation: sba (ideal)  ->  ideal
// operation: sba (module)  ->  module
// operation: slimgb (ideal)  ->  ideal
// operation: slimgb (module)  ->  module
// operation: sortvec (ideal)  ->  intvec
// operation: sortvec (module)  ->  intvec
// operation: sqrfree (poly)  ->  list
// operation: std (ideal)  ->  ideal
// operation: std (module)  ->  module
// operation: string (string)  ->  string
// operation: syz (ideal)  ->  module
// operation: syz (module)  ->  module
// operation: envelope (ring)  ->  ring
// operation: envelope (qring)  ->  qring
// operation: opposite (ring)  ->  ring
// operation: opposite (qring)  ->  qring
// operation: twostd (ideal)  ->  ideal
// DUMMY // operation: trace (intvec)  ->  $INVALID$
// DUMMY // operation: trace (ideal)  ->  $INVALID$
// operation: trace (intmat)  ->  int
// operation: trace (matrix)  ->  poly
// operation: transpose (intvec)  ->  intmat
// operation: transpose (intmat)  ->  intmat
// operation: transpose (matrix)  ->  matrix
// operation: transpose (module)  ->  module
// operation: typeof (any_type)  ->  string
// operation: univariate (poly)  ->  int
// operation: variables (poly)  ->  ideal
// operation: variables (ideal)  ->  ideal
// operation: variables (matrix)  ->  ideal
// operation: vector (vector)  ->  vector
// operation: vdim (ideal)  ->  int
// operation: vdim (module)  ->  int
// operation: var (int)  ->  poly
// operation: varstr (int)  ->  string
// operation: varstr (ring)  ->  string
// operation: varstr (qring)  ->  string
// operation: weight (ideal)  ->  intvec
// operation: weight (module)  ->  intvec
// operation: load (string)  ->  nothing
// operation: convhull (ideal)  ->  ideal
// operation: waitfirst (list)  ->  int
// operation: waitall (list)  ->  int
/*---------------------------------------------*/
// operation: :: (def, def)  ->  any_type
// operation: + (int, int)  ->  int
// operation: + (bigint, bigint)  ->  bigint
// operation: + (number, number)  ->  number
// operation: + (poly, poly)  ->  poly
// operation: + (vector, vector)  ->  vector
// operation: + (ideal, ideal)  ->  ideal
// operation: + (module, module)  ->  module
// operation: + (poly, matrix)  ->  matrix
// operation: + (matrix, poly)  ->  matrix
// operation: + (matrix, matrix)  ->  matrix
// operation: + (string, string)  ->  string
// operation: + (intvec, int)  ->  intvec
// operation: + (int, intvec)  ->  intvec
// operation: + (intmat, int)  ->  intmat
// operation: + (int, intmat)  ->  intmat
// operation: + (intvec, intvec)  ->  intvec
// operation: + (intmat, intmat)  ->  intmat
// operation: + (list, list)  ->  list
// operation: + (ring, ring)  ->  ring
// operation: + (qring, ring)  ->  qring
// operation: + (ring, qring)  ->  qring
// operation: + (qring, qring)  ->  qring
// operation: - (int, int)  ->  int
// operation: - (bigint, bigint)  ->  bigint
// operation: - (number, number)  ->  number
// operation: - (poly, poly)  ->  poly
// operation: - (vector, vector)  ->  vector
// operation: - (matrix, poly)  ->  matrix
// operation: - (matrix, matrix)  ->  matrix
// operation: - (intvec, int)  ->  intvec
// operation: - (intmat, int)  ->  intmat
// operation: - (intvec, intvec)  ->  intvec
// operation: - (intmat, intmat)  ->  intmat
// DUMMY // operation: - (ideal, ideal)  ->  nothing
// DUMMY // operation: - (module, module)  ->  nothing
// operation: * (int, int)  ->  int
// operation: * (bigint, bigint)  ->  bigint
// operation: * (number, number)  ->  number
// operation: * (poly, poly)  ->  poly
// operation: * (poly, vector)  ->  vector
// operation: * (vector, poly)  ->  vector
// operation: * (ideal, poly)  ->  ideal
// operation: * (poly, ideal)  ->  ideal
// operation: * (module, poly)  ->  module
// operation: * (poly, module)  ->  module
// operation: * (ideal, ideal)  ->  ideal
// operation: * (ideal, vector)  ->  module
// operation: * (vector, ideal)  ->  module
// operation: * (ideal, module)  ->  module
// operation: * (module, ideal)  ->  module
// operation: * (matrix, poly)  ->  matrix
// operation: * (poly, matrix)  ->  matrix
// operation: * (matrix, number)  ->  matrix
// operation: * (number, matrix)  ->  matrix
// operation: * (matrix, int)  ->  matrix
// operation: * (int, matrix)  ->  matrix
// operation: * (matrix, matrix)  ->  matrix
// operation: * (matrix, bigint)  ->  matrix
// operation: * (bigint, matrix)  ->  matrix
// operation: * (intvec, int)  ->  intvec
// operation: * (int, intvec)  ->  intvec
// operation: * (intmat, int)  ->  intmat
// operation: * (int, intmat)  ->  intmat
// operation: * (intmat, intvec)  ->  intvec
// operation: * (intmat, intmat)  ->  intmat
// operation: * (intvec, intmat)  ->  intmat
// operation: / (number, number)  ->  number
// operation: / (poly, poly)  ->  poly
// operation: / (vector, poly)  ->  vector
// operation: / (matrix, poly)  ->  matrix
// operation: / (int, int)  ->  int
// operation: / (bigint, bigint)  ->  bigint
// operation: / (intvec, int)  ->  intvec
// operation: / (intmat, int)  ->  intmat
// operation: div (int, int)  ->  int
// operation: div (bigint, bigint)  ->  bigint
// operation: div (intvec, int)  ->  intvec
// operation: div (intmat, int)  ->  intmat
// operation: % (int, int)  ->  int
// operation: % (bigint, bigint)  ->  bigint
// operation: % (intvec, int)  ->  intvec
// operation: % (intmat, int)  ->  intmat
// operation: % (number, number)  ->  number
// operation: mod (int, int)  ->  int
// operation: mod (bigint, bigint)  ->  bigint
// operation: mod (intvec, int)  ->  intvec
// operation: mod (intmat, int)  ->  intmat
// operation: mod (number, number)  ->  number
// operation: ^ (int, int)  ->  int
// operation: ^ (bigint, int)  ->  bigint
// operation: ^ (number, int)  ->  number
// operation: ^ (poly, int)  ->  poly
// operation: ^ (ideal, int)  ->  ideal
// operation: <= (int, int)  ->  int
// operation: <= (bigint, bigint)  ->  int
// operation: <= (number, number)  ->  int
// operation: <= (string, string)  ->  int
// operation: <= (intvec, int)  ->  int
// operation: <= (intvec, intvec)  ->  int
// operation: <= (poly, poly)  ->  int
// operation: <= (vector, vector)  ->  int
// operation: < (int, int)  ->  int
// operation: < (bigint, bigint)  ->  int
// operation: < (number, number)  ->  int
// operation: < (intvec, int)  ->  int
// operation: < (intvec, intvec)  ->  int
// operation: < (string, string)  ->  int
// operation: < (poly, poly)  ->  int
// operation: < (vector, vector)  ->  int
// operation: >= (int, int)  ->  int
// operation: >= (bigint, bigint)  ->  int
// operation: >= (number, number)  ->  int
// operation: >= (string, string)  ->  int
// operation: >= (intvec, int)  ->  int
// operation: >= (intvec, intvec)  ->  int
// operation: >= (poly, poly)  ->  int
// operation: >= (vector, vector)  ->  int
// operation: > (int, int)  ->  int
// operation: > (bigint, bigint)  ->  int
// operation: > (number, number)  ->  int
// operation: > (string, string)  ->  int
// operation: > (intvec, int)  ->  int
// operation: > (intvec, intvec)  ->  int
// operation: > (poly, poly)  ->  int
// operation: > (vector, vector)  ->  int
// operation: and (int, int)  ->  int
// operation: or (int, int)  ->  int
// operation: == (int, int)  ->  int
// operation: == (bigint, bigint)  ->  int
// operation: == (number, number)  ->  int
// operation: == (string, string)  ->  int
// operation: == (poly, poly)  ->  int
// operation: == (vector, vector)  ->  int
// operation: == (intvec, int)  ->  int
// operation: == (intvec, intvec)  ->  int
// operation: == (intmat, intmat)  ->  int
// operation: == (matrix, matrix)  ->  int
// DUMMY // operation: == (ideal, ideal)  ->  $INVALID$
// DUMMY // operation: == (module, module)  ->  $INVALID$
// DUMMY // operation: == (ideal, module)  ->  $INVALID$
// DUMMY // operation: == (module, ideal)  ->  $INVALID$
// operation: <> (int, int)  ->  int
// operation: <> (bigint, bigint)  ->  int
// operation: <> (number, number)  ->  int
// operation: <> (string, string)  ->  int
// operation: <> (poly, poly)  ->  int
// operation: <> (vector, vector)  ->  int
// operation: <> (intvec, intvec)  ->  int
// operation: <> (intmat, intmat)  ->  int
// operation: <> (matrix, matrix)  ->  int
// DUMMY // operation: <> (ideal, ideal)  ->  $INVALID$
// DUMMY // operation: <> (module, module)  ->  $INVALID$
// DUMMY // operation: <> (ideal, module)  ->  $INVALID$
// DUMMY // operation: <> (module, ideal)  ->  $INVALID$
// operation: .. (int, int)  ->  intvec
// operation: [ (intvec, int)  ->  int
// operation: [ (intvec, intvec)  ->  int
// operation: [ (ideal, int)  ->  poly
// operation: [ (map, int)  ->  poly
// operation: [ (ideal, intvec)  ->  poly
// operation: [ (module, int)  ->  vector
// operation: [ (module, intvec)  ->  vector
// operation: [ (string, int)  ->  string
// operation: [ (string, intvec)  ->  string
// operation: [ (list, int)  ->  any_type
// operation: [ (list, intvec)  ->  any_type
// operation: [ (poly, int)  ->  poly
// operation: [ (poly, intvec)  ->  poly
// operation: [ (vector, int)  ->  poly
// operation: [ (vector, intvec)  ->  vector
// operation: ( (proc, def)  ->  any_type
// operation: ( (map, def)  ->  any_type
// operation: ( (LIB, string)  ->  nothing
// operation: ( (any_type, int)  ->  any_type
// operation: ( (any_type, intvec)  ->  any_type
// operation: : (int, int)  ->  intvec
// operation: attrib (def, string)  ->  nothing
// operation: betti (list, int)  ->  intmat
// operation: betti (resolution, int)  ->  intmat
// operation: betti (ideal, int)  ->  intmat
// operation: betti (module, int)  ->  intmat
// operation: bracket (poly, poly)  ->  poly
// operation: chinrem (intvec, intvec)  ->  bigint
// operation: chinrem (list, intvec)  ->  any_type
// operation: chinrem (list, list)  ->  any_type
// operation: coef (poly, poly)  ->  matrix
// operation: coeffs (ideal, poly)  ->  matrix
// operation: coeffs (module, poly)  ->  matrix
// operation: coeffs (ideal, ideal)  ->  matrix
// operation: coeffs (module, module)  ->  matrix
// operation: contract (ideal, ideal)  ->  matrix
// operation: deg (poly, intvec)  ->  int
// operation: deg (vector, intvec)  ->  int
// operation: deg (matrix, intvec)  ->  int
// operation: delete (list, int)  ->  list
// operation: diff (poly, poly)  ->  poly
// operation: diff (vector, poly)  ->  vector
// operation: diff (ideal, poly)  ->  ideal
// operation: diff (ideal, ideal)  ->  matrix
// operation: diff (module, poly)  ->  module
// operation: diff (matrix, poly)  ->  matrix
// operation: dim (ideal, ideal)  ->  int
// operation: dim (module, ideal)  ->  int
// operation: division (ideal, ideal)  ->  list
// operation: division (module, module)  ->  list
// operation: eliminate (ideal, poly)  ->  ideal
// operation: eliminate (module, poly)  ->  module
// operation: eliminate (ideal, intvec)  ->  ideal
// operation: eliminate (module, intvec)  ->  module
// operation: exportto (package, identifier)  ->  nothing
// operation: extgcd (int, int)  ->  list
// operation: extgcd (poly, poly)  ->  list
// operation: factorize (poly, int)  ->  ideal
// operation: facstd (ideal, ideal)  ->  list
// operation: farey (bigint, bigint)  ->  number
// operation: farey (ideal, bigint)  ->  any_type
// operation: farey (module, bigint)  ->  any_type
// operation: farey (matrix, bigint)  ->  any_type
// operation: fetch (ring, any_type)  ->  any_type
// operation: fetch (qring, any_type)  ->  any_type
// operation: fglm (ring, def)  ->  ideal
// operation: fglm (qring, def)  ->  ideal
// operation: fglmquot (ideal, poly)  ->  ideal
// operation: find (string, string)  ->  int
// operation: frwalk (ring, def)  ->  ideal
// operation: gcd (int, int)  ->  int
// operation: gcd (number, number)  ->  number
// operation: gcd (bigint, bigint)  ->  bigint
// operation: gcd (poly, poly)  ->  poly
// operation: hilb (ideal, int)  ->  intvec
// operation: hilb (module, int)  ->  intvec
// operation: homog (ideal, intvec)  ->  int
// operation: homog (module, intvec)  ->  int
// operation: homog (poly, poly)  ->  poly
// operation: homog (vector, poly)  ->  vector
// operation: homog (ideal, poly)  ->  ideal
// operation: homog (module, poly)  ->  module
// operation: hres (ideal, int)  ->  resolution
// operation: imap (ring, any_type)  ->  any_type
// operation: imap (qring, any_type)  ->  any_type
// operation: importfrom (package, any_type)  ->  nothing
// operation: indepSet (ideal, int)  ->  list
// operation: insert (list, def)  ->  list
// operation: interpolation (list, intvec)  ->  ideal
// operation: intersect (ideal, ideal)  ->  ideal
// operation: intersect (module, module)  ->  module
// operation: janet (ideal, int)  ->  ideal
// operation: jet (poly, int)  ->  poly
// operation: jet (ideal, int)  ->  ideal
// operation: jet (vector, int)  ->  vector
// operation: jet (module, int)  ->  module
// operation: jet (matrix, int)  ->  matrix
// operation: kbase (ideal, int)  ->  ideal
// operation: kbase (module, int)  ->  module
// operation: kernel (ring, any_type)  ->  ideal
// operation: kernel (qring, any_type)  ->  ideal
// operation: killattrib (identifier, string)  ->  nothing
// operation: koszul (int, int)  ->  matrix
// operation: koszul (int, ideal)  ->  matrix
// operation: kres (ideal, int)  ->  resolution
// operation: lift (ideal, ideal)  ->  matrix
// operation: lift (module, module)  ->  matrix
// operation: liftstd (ideal, matrix)  ->  ideal
// operation: liftstd (module, matrix)  ->  module
// operation: load (string, string)  ->  nothing
// operation: lres (ideal, int)  ->  resolution
// operation: modulo (ideal, ideal)  ->  module
// operation: modulo (module, module)  ->  module
// operation: monitor (link, string)  ->  nothing
// operation: mpresmat (ideal, int)  ->  module
// operation: newstruct (string, string)  ->  nothing
// operation: mres (ideal, int)  ->  resolution
// operation: mres (module, int)  ->  resolution
// operation: primefactors (bigint, bigint)  ->  list
// operation: primefactors (number, bigint)  ->  list
// operation: primefactors (bigint, number)  ->  list
// operation: primefactors (number, number)  ->  list
// operation: $INVALID$ (poly, poly)  ->  nothing
// operation: $INVALID$ (poly, matrix)  ->  nothing
// operation: $INVALID$ (matrix, poly)  ->  nothing
// operation: $INVALID$ (matrix, matrix)  ->  nothing
// operation: nc_algebra (poly, poly)  ->  ring
// operation: nc_algebra (poly, matrix)  ->  ring
// operation: nc_algebra (matrix, poly)  ->  ring
// operation: nc_algebra (matrix, matrix)  ->  ring
// operation: oppose (ring, def)  ->  any_type
// operation: oppose (qring, def)  ->  any_type
// operation: parstr (ring, int)  ->  string
// operation: parstr (qring, int)  ->  string
// operation: print (def, string)  ->  string
// operation: quotient (ideal, ideal)  ->  ideal
// operation: quotient (module, ideal)  ->  module
// operation: quotient (module, module)  ->  ideal
// operation: random (int, int)  ->  int
// operation: rank (matrix, int)  ->  int
// operation: read (link, string)  ->  string
// operation: reduce (poly, ideal)  ->  poly
// operation: reduce (vector, ideal)  ->  vector
// operation: reduce (vector, module)  ->  vector
// operation: reduce (ideal, ideal)  ->  ideal
// operation: reduce (module, module)  ->  module
// operation: reduce (module, ideal)  ->  module
// operation: nres (ideal, int)  ->  resolution
// operation: nres (module, int)  ->  resolution
// operation: sqrfree (poly, int)  ->  ideal
// operation: status (link, string)  ->  string
// operation: status (list, int)  ->  int
// operation: simplify (poly, int)  ->  poly
// operation: simplify (vector, int)  ->  vector
// operation: simplify (ideal, int)  ->  ideal
// operation: simplify (module, int)  ->  module
// operation: sres (ideal, int)  ->  resolution
// operation: sres (module, int)  ->  resolution
// operation: sba (ideal, int)  ->  ideal
// operation: sba (module, int)  ->  module
// operation: std (ideal, poly)  ->  ideal
// operation: std (module, vector)  ->  module
// operation: std (ideal, ideal)  ->  ideal
// operation: std (module, module)  ->  module
// operation: std (ideal, intvec)  ->  ideal
// operation: std (module, intvec)  ->  module
// operation: varstr (ring, int)  ->  string
// operation: varstr (qring, int)  ->  string
// operation: waitfirst (list, int)  ->  int
// operation: waitall (list, int)  ->  int
// operation: wedge (matrix, int)  ->  matrix
/*---------------------------------------------*/
// operation: [ (string, int, int)  ->  string
// operation: [ (intmat, int, int)  ->  int
// operation: [ (intmat, int, intvec)  ->  int
// operation: [ (intmat, intvec, int)  ->  int
// operation: [ (intmat, intvec, intvec)  ->  int
// operation: [ (matrix, int, int)  ->  poly
// operation: [ (matrix, int, intvec)  ->  poly
// operation: [ (matrix, intvec, int)  ->  poly
// operation: [ (matrix, intvec, intvec)  ->  poly
// operation: ( (proc, def, def)  ->  any_type
// operation: attrib (identifier, string, def)  ->  nothing
// operation: bareiss (module, int, int)  ->  list
// operation: coeffs (poly, poly, matrix)  ->  matrix
// operation: coeffs (vector, poly, matrix)  ->  matrix
// operation: coeffs (ideal, poly, matrix)  ->  matrix
// operation: coeffs (module, poly, matrix)  ->  matrix
// operation: coeffs (ideal, ideal, poly)  ->  matrix
// operation: coeffs (module, module, poly)  ->  matrix
// operation: eliminate (ideal, poly, intvec)  ->  ideal
// operation: eliminate (module, poly, intvec)  ->  module
// operation: find (string, string, int)  ->  int
// operation: frwalk (ring, def, int)  ->  ideal
// operation: hilb (ideal, int, intvec)  ->  intvec
// operation: hilb (module, int, intvec)  ->  intvec
// operation: homog (poly, poly, intvec)  ->  poly
// operation: homog (vector, poly, intvec)  ->  vector
// operation: homog (ideal, poly, intvec)  ->  ideal
// operation: homog (module, poly, intvec)  ->  module
// operation: insert (list, def, int)  ->  list
// operation: intmat (intmat, int, int)  ->  intmat
// operation: jet (poly, int, intvec)  ->  poly
// operation: jet (ideal, int, intvec)  ->  ideal
// operation: jet (vector, int, intvec)  ->  vector
// operation: jet (module, int, intvec)  ->  module
// operation: jet (poly, poly, int)  ->  poly
// operation: jet (vector, poly, int)  ->  vector
// operation: jet (ideal, matrix, int)  ->  ideal
// operation: jet (module, matrix, int)  ->  module
// DUMMY // operation: jet (poly, int, int)  ->  poly
// operation: koszul (int, int, ideal)  ->  matrix
// operation: lift (ideal, ideal, matrix)  ->  matrix
// operation: lift (module, module, matrix)  ->  matrix
// operation: liftstd (ideal, matrix, module)  ->  ideal
// operation: liftstd (module, matrix, module)  ->  module
// operation: matrix (ideal, int, int)  ->  matrix
// operation: matrix (module, int, int)  ->  matrix
// operation: matrix (matrix, int, int)  ->  matrix
// operation: newstruct (string, string, string)  ->  nothing
// operation: preimage (ring, any_type, any_type)  ->  ideal
// operation: preimage (qring, any_type, any_type)  ->  ideal
// operation: random (int, int, int)  ->  intmat
// operation: reduce (poly, ideal, int)  ->  poly
// operation: reduce (vector, ideal, int)  ->  vector
// operation: reduce (vector, module, int)  ->  vector
// operation: reduce (ideal, ideal, int)  ->  ideal
// operation: reduce (module, module, int)  ->  module
// operation: reduce (module, ideal, int)  ->  module
// operation: reduce (poly, poly, ideal)  ->  poly
// operation: reduce (vector, poly, module)  ->  vector
// operation: reduce (ideal, ideal, matrix)  ->  ideal
// operation: reduce (module, module, matrix)  ->  module
// operation: resultant (poly, poly, poly)  ->  poly
// operation: ring (def, def, def)  ->  ring
// operation: sba (ideal, int, int)  ->  ideal
// operation: sba (module, int, int)  ->  module
// operation: status (link, string, string)  ->  int
// operation: std (ideal, intvec, intvec)  ->  ideal
// operation: std (module, intvec, intvec)  ->  module
// operation: subst (poly, poly, poly)  ->  poly
// operation: subst (poly, poly, poly)  ->  poly
// operation: subst (vector, poly, poly)  ->  vector
// operation: subst (ideal, poly, poly)  ->  ideal
// operation: subst (module, poly, poly)  ->  module
// operation: subst (matrix, poly, poly)  ->  matrix
// operation: subst (matrix, poly, int)  ->  matrix
// operation: subst (matrix, poly, number)  ->  matrix
// operation: laguerre (poly, int, int)  ->  list
// operation: vandermonde (ideal, ideal, int)  ->  poly
/*---------------------------------------------*/
// operation: ( (...)  ->  any_type ( number of arguments >0 )
// operation: breakpoint (...)  ->  nothing ( 0 arguments )
// operation: breakpoint (...)  ->  nothing ( number of arguments >0 )
// operation: coef (...)  ->  matrix ( 2 arguments )
// operation: coef (...)  ->  nothing ( 4 arguments )
// operation: division (...)  ->  any_type ( 2 arguments )
// operation: division (...)  ->  any_type ( 3 arguments )
// operation: division (...)  ->  any_type ( 4 arguments )
// operation: dbprint (...)  ->  nothing ( number of arguments >0 )
// operation: ideal (...)  ->  ideal ( 1 arguments )
// operation: ideal (...)  ->  ideal ( any number of arguments )
// operation: intersect (...)  ->  ideal ( 2 arguments )
// operation: intersect (...)  ->  ideal ( number of arguments >0 )
// operation: intvec (...)  ->  intvec ( 1 arguments )
// operation: intvec (...)  ->  intvec ( number of arguments >0 )
// operation: jet (...)  ->  poly ( 2 arguments )
// operation: jet (...)  ->  poly ( 3 arguments )
// operation: jet (...)  ->  poly ( 4 arguments )
// operation: LIB (...)  ->  nothing ( 1 arguments )
// operation: list (...)  ->  list ( any number of arguments )
// operation: luinverse (...)  ->  list ( number of arguments >0 )
// operation: lusolve (...)  ->  list ( number of arguments >0 )
// operation: minor (...)  ->  nothing ( 1 arguments )
// operation: minor (...)  ->  ideal ( number of arguments >0 )
// operation: module (...)  ->  module ( 1 arguments )
// operation: module (...)  ->  module ( any number of arguments )
// operation: names (...)  ->  list ( 1 arguments )
// operation: names (...)  ->  list ( 0 arguments )
// operation: option (...)  ->  string ( any number of arguments )
// operation: reduce (...)  ->  ideal ( 2 arguments )
// operation: reduce (...)  ->  ideal ( 3 arguments )
// operation: reduce (...)  ->  ideal ( 4 arguments )
// operation: reduce (...)  ->  ideal ( 5 arguments )
// operation: reservedName (...)  ->  int ( 1 arguments )
// operation: reservedName (...)  ->  nothing ( 0 arguments )
// operation: string (...)  ->  string ( any number of arguments )
// operation: subst (...)  ->  nothing ( 3 arguments )
// operation: subst (...)  ->  nothing ( number of arguments >0 )
// operation: system (...)  ->  nothing ( number of arguments >0 )
// operation: test (...)  ->  nothing ( number of arguments >0 )
// operation: write (...)  ->  nothing ( number of arguments >0 )
// operation: status (...)  ->  string ( 2 arguments )
// operation: status (...)  ->  int ( 3 arguments )
// operation: status (...)  ->  int ( 4 arguments )
// operation: simplex (...)  ->  list ( 6 arguments )
// operation: uressolve (...)  ->  list ( 4 arguments )
// operation: sba (...)  ->  ideal ( 1 arguments )
// operation: sba (...)  ->  ideal ( 2 arguments )
// operation: sba (...)  ->  ideal ( 3 arguments )
// operation: std (...)  ->  ideal ( 1 arguments )
// operation: std (...)  ->  ideal ( 2 arguments )
// operation: std (...)  ->  ideal ( 3 arguments )
// operation: std (...)  ->  ideal ( 4 arguments )
// operation: qrds (...)  ->  list ( 4 arguments )
// operation: factmodd (...)  ->  list ( number of arguments >0 )
/*---------------------------------------------*/
// assign: ideal =  ideal
// assign: ideal =  matrix
// assign: resolution =  resolution
// assign: int =  int
// assign: int =  intmat
// assign: matrix =  matrix
// assign: map =  ideal
// assign: map =  map
// assign: module =  module
// assign: module =  poly
// assign: poly =  poly
// assign: poly =  matrix
// assign: qring =  ideal
// assign: ring =  ring
// assign: qring =  qring
// assign: string =  string
// assign: proc =  string
// assign: proc =  proc
// assign: vector =  vector
// assign: intvec =  intvec
// assign: intmat =  intmat
// assign: number =  number
// assign: bigint =  bigint
// assign: list =  resolution
// assign: list =  list
// assign: link =  string
// assign: link =  link
// assign: package =  package
// assign: def =  def
/*---------------------------------------------*/
// convert intvec -> intmat
// convert poly -> ideal
// convert bigint -> ideal
// convert int -> ideal
// convert intmat -> matrix
// convert ideal -> matrix
// convert module -> matrix
// convert number -> matrix
// convert poly -> matrix
// convert vector -> matrix
// convert bigint -> matrix
// convert int -> matrix
// convert intvec -> matrix
// convert ideal -> module
// convert matrix -> module
// convert vector -> module
// convert bigint -> number
// convert int -> number
// convert number -> poly
// convert bigint -> poly
// convert int -> poly
// convert list -> resolution
// convert poly -> vector
// convert bigint -> vector
// convert int -> vector
// convert int -> bigint
// convert int -> intvec
// convert string -> link
// convert resolution -> list
/*---------------------------------------------*/
// token 61 : =
// token 62 : >
// token 60 : <
// token 43 : +
// token 42 : *
// token 47 : /
// token 91 : [
// token 46 : .
// token 94 : ^
// token 44 : ,
// token 37 : %
// token 40 : (
// token 59 : ;
// token 258 : ..
// token 259 : ==
// token 260 : >=
// token 261 : <=
// token 262 : --
// token 263 : not
// token 264 : <>
// token 265 : ++
// token 266 : ::
// token 269 : intmat
// token 270 : proc
// token 271 : ring
// token 273 : ideal
// token 274 : map
// token 275 : matrix
// token 276 : module
// token 277 : number
// token 278 : poly
// token 279 : resolution
// token 280 : vector
// token 281 : betti
// token 282 : coeffs
// token 283 : coef
// token 284 : contract
// token 285 : degree
// token 286 : deg
// token 287 : diff
// token 288 : dim
// token 289 : division
// token 290 : eliminate
// token 291 : gen
// token 292 : farey
// token 293 : fetch
// token 294 : freemodule
// token 295 : keepring
// token 296 : hilb
// token 297 : homog
// token 298 : imap
// token 299 : indepSet
// token 300 : interred
// token 301 : intersect
// token 302 : jacob
// token 303 : jet
// token 304 : kbase
// token 305 : koszul
// token 306 : leadcoef
// token 307 : leadexp
// token 308 : lead
// token 309 : leadmonom
// token 310 : liftstd
// token 311 : lift
// token 312 : maxideal
// token 313 : minbase
// token 314 : minor
// token 315 : minres
// token 316 : modulo
// token 317 : monomial
// token 318 : mres
// token 319 : mult
// token 320 : ord
// token 321 : par
// token 322 : pardeg
// token 323 : preimage
// token 324 : quotient
// token 325 : qhweight
// token 326 : reduce
// token 327 : regularity
// token 328 : nres
// token 329 : simplify
// token 330 : sortvec
// token 331 : sres
// token 332 : std
// token 333 : subst
// token 334 : syz
// token 335 : var
// token 336 : vdim
// token 337 : wedge
// token 338 : weight
// token 340 : degBound
// token 341 : multBound
// token 342 : noether
// token 343 : minpoly
// token 344 : nothing
// token 357 : example
// token 358 : export
// token 360 : kill
// token 361 : LIB
// token 362 : listvar
// token 363 : setring
// token 364 : type
// token 371 : break
// token 372 : continue
// token 373 : else
// token 374 : eval
// token 375 : quote
// token 377 : forif
// token 380 : return
// token 381 : parameter
// token 384 : sba
// token 385 : command
// token 386 : any_type
// token 387 : identifier
// token 398 : alias
// token 399 : attrib
// token 400 : bareiss
// token 401 : bigint
// token 402 : bracket
// token 403 : breakpoint
// token 404 : char
// token 405 : charstr
// token 406 : char_series
// token 407 : chinrem
// token 408 : close
// token 409 : ncols
// token 410 : cleardenom
// token 411 : size
// token 412 : dbprint
// token 413 : def
// token 414 : defined
// token 415 : delete
// token 416 : det
// token 417 : dump
// token 418 : RETURN
// token 419 : envelope
// token 420 : ERROR
// token 421 : execute
// token 422 : exportto
// token 423 : extgcd
// token 424 : factorize
// token 425 : find
// token 426 : facstd
// token 427 : factmodd
// token 428 : frwalk
// token 429 : fglm
// token 430 : fglmquot
// token 431 : finduni
// token 432 : gcd
// token 433 : getdump
// token 434 : highcorner
// token 435 : hres
// token 436 : impart
// token 437 : importfrom
// token 438 : insert
// token 439 : int
// token 440 : div
// token 441 : interpolation
// token 442 : mod
// token 443 : intvec
// token 444 : rvar
// token 445 : janet
// token 446 : kernel
// token 447 : killattrib
// token 448 : kres
// token 449 : laguerre
// token 450 : link
// token 451 : list
// token 452 : load
// token 453 : lres
// token 454 : ludecomp
// token 455 : luinverse
// token 456 : lusolve
// token 457 : memory
// token 458 : monitor
// token 459 : mpresmat
// token 460 : mstd
// token 461 : nameof
// token 462 : names
// token 463 : newstruct
// token 465 : nc_algebra
// token 466 : convhull
// token 467 : npars
// token 468 : nvars
// token 469 : open
// token 470 : oppose
// token 471 : opposite
// token 472 : option
// token 473 : ordstr
// token 474 : package
// token 475 : parstr
// token 476 : primefactors
// token 478 : prime
// token 479 : print
// token 480 : prune
// token 481 : qring
// token 482 : qrds
// token 483 : random
// token 484 : rank
// token 485 : read
// token 486 : repart
// token 487 : reservedName
// token 488 : resultant
// token 489 : ringlist
// token 490 : nrows
// token 491 : simplex
// token 492 : slimgb
// token 493 : sqrfree
// token 494 : status
// token 495 : string
// token 496 : system
// token 497 : test
// token 498 : transpose
// token 499 : trace
// token 500 : twostd
// token 501 : typeof
// token 502 : univariate
// token 504 : uressolve
// token 505 : vandermonde
// token 506 : variables
// token 507 : varstr
// token 508 : waitfirst
// token 509 : waitall
// token 510 : write
// token 511 : echo
// token 512 : pagewidth
// token 513 : timer
// token 514 : rtimer
// token 515 : TRACE
// token 516 : voice
// token 517 : short
// token 518 : printlevel
/*--max. token: 519, gr: 383 --*/
/*---------------------------------------------*/
struct sValCmdTab dArithTab1[]=
{
 { 40,10 },
 { 45,2 },
 { 262,1 },
 { 265,0 },
 { 269,90 },
 { 270,161 },
 { 271,175 },
 { 273,76 },
 { 274,118 },
 { 275,119 },
 { 276,126 },
 { 277,138 },
 { 278,155 },
 { 279,171 },
 { 280,212 },
 { 281,13 },
 { 285,51 },
 { 286,48 },
 { 288,57 },
 { 291,61 },
 { 294,66 },
 { 296,71 },
 { 297,74 },
 { 299,83 },
 { 300,88 },
 { 302,96 },
 { 304,100 },
 { 306,110 },
 { 307,112 },
 { 308,106 },
 { 309,114 },
 { 312,120 },
 { 313,122 },
 { 315,124 },
 { 317,128 },
 { 319,129 },
 { 320,146 },
 { 321,150 },
 { 322,151 },
 { 323,157 },
 { 325,163 },
 { 327,168 },
 { 330,186 },
 { 332,189 },
 { 334,192 },
 { 335,215 },
 { 336,213 },
 { 338,219 },
 { 384,182 },
 { 399,11 },
 { 400,12 },
 { 401,17 },
 { 404,20 },
 { 405,23 },
 { 406,22 },
 { 408,25 },
 { 409,26 },
 { 410,31 },
 { 411,33 },
 { 413,46 },
 { 414,53 },
 { 416,54 },
 { 417,60 },
 { 419,194 },
 { 420,63 },
 { 421,62 },
 { 424,64 },
 { 426,67 },
 { 431,65 },
 { 433,68 },
 { 434,69 },
 { 436,82 },
 { 439,84 },
 { 443,91 },
 { 444,93 },
 { 445,99 },
 { 447,105 },
 { 450,116 },
 { 451,117 },
 { 452,221 },
 { 454,102 },
 { 457,121 },
 { 458,127 },
 { 460,131 },
 { 461,133 },
 { 462,134 },
 { 466,222 },
 { 467,141 },
 { 468,143 },
 { 469,145 },
 { 471,196 },
 { 473,148 },
 { 475,152 },
 { 476,103 },
 { 478,158 },
 { 479,159 },
 { 480,162 },
 { 481,165 },
 { 484,166 },
 { 485,167 },
 { 486,169 },
 { 487,170 },
 { 489,173 },
 { 490,177 },
 { 492,184 },
 { 493,188 },
 { 495,191 },
 { 498,203 },
 { 499,199 },
 { 500,198 },
 { 501,207 },
 { 502,208 },
 { 506,209 },
 { 507,216 },
 { 508,223 },
 { 509,224 },
 { 10000,0 }
};
#define JJTAB1LEN 116
struct sValCmdTab dArithTab2[]=
{
 { 37,79 },
 { 38,126 },
 { 40,171 },
 { 42,36 },
 { 43,1 },
 { 45,23 },
 { 47,67 },
 { 58,176 },
 { 60,102 },
 { 62,118 },
 { 91,156 },
 { 94,89 },
 { 124,127 },
 { 258,155 },
 { 259,128 },
 { 260,110 },
 { 261,94 },
 { 264,142 },
 { 266,0 },
 { 281,178 },
 { 282,187 },
 { 283,186 },
 { 284,191 },
 { 286,192 },
 { 287,196 },
 { 288,202 },
 { 289,204 },
 { 290,206 },
 { 292,215 },
 { 293,219 },
 { 296,230 },
 { 297,232 },
 { 298,239 },
 { 299,242 },
 { 301,245 },
 { 303,248 },
 { 304,253 },
 { 305,258 },
 { 310,263 },
 { 311,261 },
 { 316,267 },
 { 318,272 },
 { 324,291 },
 { 326,297 },
 { 328,303 },
 { 329,308 },
 { 331,312 },
 { 332,316 },
 { 337,326 },
 { 384,314 },
 { 399,177 },
 { 402,182 },
 { 407,183 },
 { 415,195 },
 { 422,210 },
 { 423,211 },
 { 424,213 },
 { 425,224 },
 { 426,214 },
 { 428,225 },
 { 429,221 },
 { 430,223 },
 { 432,226 },
 { 435,238 },
 { 437,241 },
 { 438,243 },
 { 440,75 },
 { 441,244 },
 { 442,84 },
 { 445,247 },
 { 446,255 },
 { 447,257 },
 { 448,260 },
 { 452,265 },
 { 453,266 },
 { 458,269 },
 { 459,270 },
 { 463,271 },
 { 464,278 },
 { 465,282 },
 { 470,286 },
 { 475,288 },
 { 476,274 },
 { 479,290 },
 { 483,294 },
 { 484,295 },
 { 485,296 },
 { 493,305 },
 { 494,306 },
 { 507,322 },
 { 508,324 },
 { 509,325 },
 { 10000,0 }
};
#define JJTAB2LEN 92
/****************************************
*  Computer Algebra System SINGULAR     *
****************************************/

// identifier table for Singular
//
#ifdef MODULE_GENERATOR
#define omAlloc0(A) malloc(A)
#endif
void iiInitCmdName()
{
  sArithBase.nCmdUsed      = 0;
  sArithBase.nCmdAllocated = 226;
  sArithBase.sCmds = (cmdnames*)omAlloc0(sArithBase.nCmdAllocated*sizeof(cmdnames));

  // name-string                   alias  tokval toktype index
  iiArithAddCmd("$INVALID$",           0,  -1, 0, 0);
  iiArithAddCmd("ERROR",               0, 420, CMD_1, 1);
  iiArithAddCmd("GCD",                 2, 432, CMD_2, 2);
  iiArithAddCmd("IN",                  1, 308, CMD_1, 3);
  iiArithAddCmd("LIB",                 0, 361, SYSVAR, 4);
  iiArithAddCmd("NF",                  1, 326, CMD_M, 5);
  iiArithAddCmd("RETURN",              0, 418, 380, 6);
  iiArithAddCmd("TRACE",               0, 515, SYSVAR, 7);
  iiArithAddCmd("alias",               0, 398, 381, 8);
  iiArithAddCmd("and",                 0,  38, '&', 9);
  iiArithAddCmd("attrib",              0, 399, CMD_123, 10);
  iiArithAddCmd("bareiss",             0, 400, 349, 11);
  iiArithAddCmd("betti",               0, 281, CMD_12, 12);
  iiArithAddCmd("bigint",              0, 401, ROOT_DECL, 13);
  iiArithAddCmd("bracket",             0, 402, CMD_2, 14);
  iiArithAddCmd("break",               0, 371, 371, 15);
  iiArithAddCmd("breakpoint",          0, 403, CMD_M, 16);
  iiArithAddCmd("char",                0, 404, CMD_1, 17);
  iiArithAddCmd("char_series",         0, 406, CMD_1, 18);
  iiArithAddCmd("charstr",             0, 405, CMD_1, 19);
  iiArithAddCmd("chinrem",             0, 407, CMD_2, 20);
  iiArithAddCmd("cleardenom",          0, 410, CMD_1, 21);
  iiArithAddCmd("close",               0, 408, CMD_1, 22);
  iiArithAddCmd("coef",                0, 283, CMD_M, 23);
  iiArithAddCmd("coeffs",              0, 282, CMD_23, 24);
  iiArithAddCmd("continue",            0, 372, 372, 25);
  iiArithAddCmd("contract",            0, 284, CMD_2, 26);
  iiArithAddCmd("convhull",            0, 466, CMD_1, 27);
  iiArithAddCmd("dbprint",             0, 412, CMD_M, 28);
  iiArithAddCmd("def",                 0, 413, ROOT_DECL, 29);
  iiArithAddCmd("defined",             0, 414, CMD_1, 30);
  iiArithAddCmd("deg",                 0, 286, CMD_12, 31);
  iiArithAddCmd("degBound",            0, 340, SYSVAR, 32);
  iiArithAddCmd("degree",              0, 285, CMD_1, 33);
  iiArithAddCmd("delete",              0, 415, CMD_2, 34);
  iiArithAddCmd("det",                 0, 416, CMD_1, 35);
  iiArithAddCmd("diff",                0, 287, CMD_2, 36);
  iiArithAddCmd("dim",                 0, 288, CMD_1, 37);
  iiArithAddCmd("div",                 0, 440, '/', 38);
  iiArithAddCmd("division",            0, 289, CMD_M, 39);
  iiArithAddCmd("dump",                0, 417, CMD_1, 40);
  iiArithAddCmd("echo",                0, 511, SYSVAR, 41);
  iiArithAddCmd("eliminate",           0, 290, CMD_23, 42);
  iiArithAddCmd("else",                0, 373, 373, 43);
  iiArithAddCmd("envelope",            0, 419, CMD_1, 44);
  iiArithAddCmd("eval",                0, 374, 374, 45);
  iiArithAddCmd("example",             0, 357, 357, 46);
  iiArithAddCmd("execute",             0, 421, CMD_1, 47);
  iiArithAddCmd("export",              0, 358, 358, 48);
  iiArithAddCmd("exportto",            0, 422, CMD_2, 49);
  iiArithAddCmd("extgcd",              0, 423, CMD_2, 50);
  iiArithAddCmd("facstd",              0, 426, CMD_12, 51);
  iiArithAddCmd("factmodd",            0, 427, CMD_M, 52);
  iiArithAddCmd("factorize",           0, 424, CMD_12, 53);
  iiArithAddCmd("farey",               0, 292, CMD_2, 54);
  iiArithAddCmd("fetch",               0, 293, CMD_2, 55);
  iiArithAddCmd("fglm",                0, 429, CMD_2, 56);
  iiArithAddCmd("fglmquot",            0, 430, CMD_2, 57);
  iiArithAddCmd("find",                0, 425, CMD_23, 58);
  iiArithAddCmd("finduni",             0, 431, CMD_1, 59);
  iiArithAddCmd("forif",               0, 377, 377, 60);
  iiArithAddCmd("freemodule",          0, 294, CMD_1, 61);
  iiArithAddCmd("frwalk",              0, 428, CMD_23, 62);
  iiArithAddCmd("gcd",                 0, 432, CMD_2, 63);
  iiArithAddCmd("gen",                 0, 291, CMD_1, 64);
  iiArithAddCmd("getdump",             0, 433, CMD_1, 65);
  iiArithAddCmd("highcorner",          0, 434, CMD_1, 66);
  iiArithAddCmd("hilb",                0, 296, CMD_123, 67);
  iiArithAddCmd("homog",               0, 297, CMD_123, 68);
  iiArithAddCmd("hres",                0, 435, CMD_2, 69);
  iiArithAddCmd("ideal",               0, 273, 356, 70);
  iiArithAddCmd("if",                  0, 377, 377, 71);
  iiArithAddCmd("imap",                0, 298, CMD_2, 72);
  iiArithAddCmd("impart",              0, 436, CMD_1, 73);
  iiArithAddCmd("importfrom",          0, 437, CMD_2, 74);
  iiArithAddCmd("indepSet",            0, 299, CMD_12, 75);
  iiArithAddCmd("insert",              0, 438, CMD_23, 76);
  iiArithAddCmd("int",                 0, 439, ROOT_DECL, 77);
  iiArithAddCmd("interpolation",       0, 441, CMD_2, 78);
  iiArithAddCmd("interred",            0, 300, CMD_1, 79);
  iiArithAddCmd("intersect",           0, 301, CMD_M, 80);
  iiArithAddCmd("intmat",              0, 269, 269, 81);
  iiArithAddCmd("intvec",              0, 443, ROOT_DECL_LIST, 82);
  iiArithAddCmd("jacob",               0, 302, CMD_1, 83);
  iiArithAddCmd("janet",               0, 445, CMD_12, 84);
  iiArithAddCmd("jet",                 0, 303, CMD_M, 85);
  iiArithAddCmd("kbase",               0, 304, CMD_12, 86);
  iiArithAddCmd("keepring",            0, 295, 295, 87);
  iiArithAddCmd("kernel",              0, 446, CMD_2, 88);
  iiArithAddCmd("kill",                0, 360, 360, 89);
  iiArithAddCmd("killattrib",          0, 447, CMD_12, 90);
  iiArithAddCmd("koszul",              0, 305, CMD_23, 91);
  iiArithAddCmd("kres",                0, 448, CMD_2, 92);
  iiArithAddCmd("laguerre",            0, 449, CMD_3, 93);
  iiArithAddCmd("lead",                0, 308, CMD_1, 94);
  iiArithAddCmd("leadcoef",            0, 306, CMD_1, 95);
  iiArithAddCmd("leadexp",             0, 307, CMD_1, 96);
  iiArithAddCmd("leadmonom",           0, 309, CMD_1, 97);
  iiArithAddCmd("lift",                0, 311, CMD_23, 98);
  iiArithAddCmd("liftstd",             0, 310, CMD_23, 99);
  iiArithAddCmd("link",                0, 450, ROOT_DECL, 100);
  iiArithAddCmd("list",                0, 451, ROOT_DECL_LIST, 101);
  iiArithAddCmd("listvar",             0, 362, 362, 102);
  iiArithAddCmd("load",                0, 452, CMD_12, 103);
  iiArithAddCmd("lres",                0, 453, CMD_2, 104);
  iiArithAddCmd("ludecomp",            0, 454, CMD_1, 105);
  iiArithAddCmd("luinverse",           0, 455, CMD_M, 106);
  iiArithAddCmd("lusolve",             0, 456, CMD_M, 107);
  iiArithAddCmd("map",                 0, 274, RING_DECL, 108);
  iiArithAddCmd("matrix",              0, 275, 275, 109);
  iiArithAddCmd("maxideal",            0, 312, CMD_1, 110);
  iiArithAddCmd("memory",              0, 457, CMD_1, 111);
  iiArithAddCmd("minbase",             0, 313, CMD_1, 112);
  iiArithAddCmd("minor",               0, 314, CMD_M, 113);
  iiArithAddCmd("minpoly",             0, 343, SYSVAR, 114);
  iiArithAddCmd("minres",              0, 315, CMD_1, 115);
  iiArithAddCmd("mod",                 0, 442, '/', 116);
  iiArithAddCmd("module",              0, 276, 356, 117);
  iiArithAddCmd("modulo",              0, 316, CMD_2, 118);
  iiArithAddCmd("monitor",             0, 458, CMD_12, 119);
  iiArithAddCmd("monomial",            0, 317, CMD_1, 120);
  iiArithAddCmd("mpresmat",            0, 459, CMD_2, 121);
  iiArithAddCmd("mres",                0, 318, CMD_2, 122);
  iiArithAddCmd("mstd",                0, 460, CMD_1, 123);
  iiArithAddCmd("mult",                0, 319, CMD_1, 124);
  iiArithAddCmd("multBound",           0, 341, SYSVAR, 125);
  iiArithAddCmd("multiplicity",        1, 319, CMD_1, 126);
  iiArithAddCmd("nameof",              0, 461, CMD_1, 127);
  iiArithAddCmd("names",               0, 462, CMD_M, 128);
  iiArithAddCmd("nc_algebra",          0, 465, CMD_2, 129);
  iiArithAddCmd("ncalgebra",           2, 464, CMD_2, 130);
  iiArithAddCmd("ncols",               0, 409, CMD_1, 131);
  iiArithAddCmd("newstruct",           0, 463, CMD_23, 132);
  iiArithAddCmd("noether",             0, 342, SYSVAR, 133);
  iiArithAddCmd("not",                 0, 263, 263, 134);
  iiArithAddCmd("npars",               0, 467, CMD_1, 135);
  iiArithAddCmd("nres",                0, 328, CMD_2, 136);
  iiArithAddCmd("nrows",               0, 490, CMD_1, 137);
  iiArithAddCmd("number",              0, 277, RING_DECL, 138);
  iiArithAddCmd("nvars",               0, 468, CMD_1, 139);
  iiArithAddCmd("open",                0, 469, CMD_1, 140);
  iiArithAddCmd("oppose",              0, 470, CMD_2, 141);
  iiArithAddCmd("opposite",            0, 471, CMD_1, 142);
  iiArithAddCmd("option",              0, 472, CMD_M, 143);
  iiArithAddCmd("or",                  0, 124, '&', 144);
  iiArithAddCmd("ord",                 0, 320, CMD_1, 145);
  iiArithAddCmd("ordstr",              0, 473, CMD_1, 146);
  iiArithAddCmd("package",             0, 474, ROOT_DECL, 147);
  iiArithAddCmd("pagewidth",           0, 512, SYSVAR, 148);
  iiArithAddCmd("par",                 0, 321, CMD_1, 149);
  iiArithAddCmd("parameter",           0, 381, 381, 150);
  iiArithAddCmd("pardeg",              0, 322, CMD_1, 151);
  iiArithAddCmd("parstr",              0, 475, CMD_12, 152);
  iiArithAddCmd("poly",                0, 278, RING_DECL, 153);
  iiArithAddCmd("preimage",            0, 323, 349, 154);
  iiArithAddCmd("prime",               0, 478, CMD_1, 155);
  iiArithAddCmd("primefactors",        0, 476, CMD_12, 156);
  iiArithAddCmd("print",               0, 479, CMD_12, 157);
  iiArithAddCmd("printlevel",          0, 518, SYSVAR, 158);
  iiArithAddCmd("proc",                0, 270, 270, 159);
  iiArithAddCmd("prune",               0, 480, CMD_1, 160);
  iiArithAddCmd("qhweight",            0, 325, CMD_1, 161);
  iiArithAddCmd("qrds",                0, 482, CMD_M, 162);
  iiArithAddCmd("qring",               0, 481, ROOT_DECL, 163);
  iiArithAddCmd("quote",               0, 375, 375, 164);
  iiArithAddCmd("quotient",            0, 324, CMD_2, 165);
  iiArithAddCmd("random",              0, 483, CMD_23, 166);
  iiArithAddCmd("rank",                0, 484, CMD_12, 167);
  iiArithAddCmd("read",                0, 485, CMD_12, 168);
  iiArithAddCmd("reduce",              0, 326, CMD_M, 169);
  iiArithAddCmd("regularity",          0, 327, CMD_1, 170);
  iiArithAddCmd("repart",              0, 486, CMD_1, 171);
  iiArithAddCmd("reservedName",        0, 487, CMD_M, 172);
  iiArithAddCmd("resolution",          0, 279, RING_DECL, 173);
  iiArithAddCmd("resultant",           0, 488, CMD_3, 174);
  iiArithAddCmd("return",              0, 380, 380, 175);
  iiArithAddCmd("ring",                0, 271, 271, 176);
  iiArithAddCmd("ringlist",            0, 489, CMD_1, 177);
  iiArithAddCmd("rtimer",              0, 514, SYSVAR, 178);
  iiArithAddCmd("rvar",                0, 444, CMD_1, 179);
  iiArithAddCmd("sba",                 0, 384, CMD_M, 180);
  iiArithAddCmd("setring",             0, 363, 363, 181);
  iiArithAddCmd("short",               0, 517, SYSVAR, 182);
  iiArithAddCmd("simplex",             0, 491, CMD_M, 183);
  iiArithAddCmd("simplify",            0, 329, CMD_2, 184);
  iiArithAddCmd("size",                0, 411, CMD_1, 185);
  iiArithAddCmd("slimgb",              0, 492, CMD_1, 186);
  iiArithAddCmd("sortvec",             0, 330, CMD_1, 187);
  iiArithAddCmd("sqrfree",             0, 493, CMD_12, 188);
  iiArithAddCmd("sres",                0, 331, CMD_2, 189);
  iiArithAddCmd("status",              0, 494, CMD_M, 190);
  iiArithAddCmd("std",                 0, 332, CMD_M, 191);
  iiArithAddCmd("string",              0, 495, ROOT_DECL_LIST, 192);
  iiArithAddCmd("subst",               0, 333, CMD_M, 193);
  iiArithAddCmd("system",              0, 496, CMD_M, 194);
  iiArithAddCmd("syz",                 0, 334, CMD_1, 195);
  iiArithAddCmd("test",                0, 497, CMD_M, 196);
  iiArithAddCmd("timer",               0, 513, SYSVAR, 197);
  iiArithAddCmd("trace",               0, 499, CMD_1, 198);
  iiArithAddCmd("transpose",           0, 498, CMD_1, 199);
  iiArithAddCmd("twostd",              0, 500, CMD_1, 200);
  iiArithAddCmd("type",                0, 364, 364, 201);
  iiArithAddCmd("typeof",              0, 501, CMD_1, 202);
  iiArithAddCmd("univariate",          0, 502, CMD_1, 203);
  iiArithAddCmd("uressolve",           0, 504, CMD_M, 204);
  iiArithAddCmd("vandermonde",         0, 505, CMD_3, 205);
  iiArithAddCmd("var",                 0, 335, CMD_1, 206);
  iiArithAddCmd("variables",           0, 506, CMD_1, 207);
  iiArithAddCmd("varstr",              0, 507, CMD_12, 208);
  iiArithAddCmd("vdim",                0, 336, CMD_1, 209);
  iiArithAddCmd("vector",              0, 280, RING_DECL, 210);
  iiArithAddCmd("verbose",             2, 472, CMD_M, 211);
  iiArithAddCmd("voice",               0, 516, SYSVAR, 212);
  iiArithAddCmd("waitall",             0, 509, CMD_12, 213);
  iiArithAddCmd("waitfirst",           0, 508, CMD_12, 214);
  iiArithAddCmd("wedge",               0, 337, CMD_2, 215);
  iiArithAddCmd("weight",              0, 338, CMD_1, 216);
  iiArithAddCmd("whileif",             0, 377, 377, 217);
  iiArithAddCmd("write",               0, 510, CMD_M, 218);
  iiArithAddCmd("exit",                0,  -1, 0, 219);
  iiArithAddCmd("for",                 0,  -1, 0, 220);
  iiArithAddCmd("help",                0,  -1, 0, 221);
  iiArithAddCmd("newline",             0,  -1, 0, 222);
  iiArithAddCmd("pause",               2,  -1, 0, 223);
  iiArithAddCmd("quit",                0,  -1, 0, 224);
  iiArithAddCmd("while",               0,  -1, 0, 225);
/* end of list marker */
  sArithBase.nLastIdentifier = 218;
}
#define LAST_IDENTIFIER 218
