/* auxiliary.h.  Generated from auxiliary.h.in by configure.  */
/*****************************************************************************\
 * Computer Algebra System SINGULAR    
\*****************************************************************************/
/** @file auxiliary.h
 * 
 * All the auxiliary stuff.
 *
 * ABSTRACT: we shall put here everything that does not have its own place.
 *
 * @author Oleksandr Motsak
 *
 * @internal @version \$Id$
 *
 **/
/*****************************************************************************/

#ifndef MISC_AUXILIARY_H
#define MISC_AUXILIARY_H
     
// -----------------  configure stuff

/* CPU type: i[3456]86: */
#define SI_CPU_I386 1
/* CPU type: sparc: */
/* #undef SI_CPU_SPARC */
/* CPU type: ppc: */
/* #undef SI_CPU_PPC */
/* CPU type: IA64: */
/* #undef SI_CPU_IA64 */
/* CPU type: x86_64: */
/* #undef SI_CPU_X86_64 */

// ----------------- end of configure stuff

// BOOLEAN

#if (SIZEOF_LONG == 8)
typedef int BOOLEAN;
/* testet on x86_64, gcc 3.4.6: 2 % */
/* testet on IA64, gcc 3.4.6: 1 % */
#else
/* testet on athlon, gcc 2.95.4: 1 % */
typedef short BOOLEAN;
#endif

#ifndef FALSE
#define FALSE       0
#endif

#ifndef TRUE
#define TRUE        1
#endif

#ifndef NULL
#define NULL        (0)
#endif

// #ifdef _TRY
#ifndef ABS
#define ABS(x) ((x)<0?(-(x)):(x))
#endif
// #endif

static const int MAX_INT_LEN= 11;
typedef void* ADDRESS;

#define loop for(;;)

static inline int si_max(const int a, const int b)  { return (a>b) ? a : b; }


#if defined(SI_CPU_I386) || defined(SI_CPU_X86_64)
  // the following settings seems to be better on i386 and x86_64 processors
  // define if a*b is with mod instead of tables
#define HAVE_MULT_MOD
  // #define HAVE_GENERIC_ADD
  // #ifdef HAVE_MULT_MOD
  // #define HAVE_DIV_MOD
  // #endif
#elif defined(SI_CPU_IA64)
  // the following settings seems to be better on itanium processors
  // #define HAVE_MULT_MOD
#define HAVE_GENERIC_ADD
  // #ifdef HAVE_MULT_MOD
  // #define HAVE_DIV_MOD
  // #endif
#elif defined(SI_CPU_SPARC)
  // #define HAVE_GENERIC_ADD
#define HAVE_MULT_MOD
#ifdef HAVE_MULT_MOD
#define HAVE_DIV_MOD
#endif
#elif defined(SI_CPU_PPC)
  // the following settings seems to be better on ppc processors
  // testet on: ppc_Linux, 740/750 PowerMac G3, 512k L2 cache
#define HAVE_MULT_MOD
  // #ifdef HAVE_MULT_MOD
  // #define HAVE_DIV_MOD
  // #endif
#endif


#endif
/* _MISC_AUXILIARY_H */
