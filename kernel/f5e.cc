/****************************************
*  Computer Algebra System SINGULAR     *
****************************************/
/* $Id$ */
/*
* ABSTRACT:
*/

// TODO: why the following is here instead of mod2.h???

// define if tailrings should be used
#define HAVE_TAIL_RING

// define if buckets should be used
#define MORA_USE_BUCKETS

#include <kernel/mod2.h>
#include <omalloc/omalloc.h>

#ifndef NDEBUG
# define MYTEST 0
#else /* ifndef NDEBUG */
# define MYTEST 0
#endif /* ifndef NDEBUG */

#if MYTEST
#ifdef HAVE_TAIL_RING
#undef HAVE_TAIL_RING
#endif /* ifdef HAVE_TAIL_RING */
#endif /* if MYTEST */

#include <kernel/options.h>
#include <kernel/kutil.h>
#include <kernel/kInline.cc>
#include <kernel/polys.h>
#include <kernel/febase.h>
#include <kernel/kstd1.h>
#include <kernel/khstd.h>
#include <kernel/stairc.h>
#include <kernel/weight.h>
//#include "cntrlc.h"
#include <kernel/intvec.h>
#include <kernel/ideals.h>
//#include "../Singular/ipid.h"
#include <kernel/timer.h>

//#include "ipprint.h"

#ifdef HAVE_PLURAL
#include <kernel/sca.h>
#endif


ideal f5e(ideal F, ideal Q, tHomog h,intvec ** w, intvec *hilb,int syzComp,
          int newIdeal, intvec *vw)
{
  if(idIs0(F))
    return idInit(1,F->rank);

  ideal r;
  BOOLEAN b=pLexOrder,toReset=FALSE;
  BOOLEAN delete_w=(w==NULL);
  kStrategy strat=new skStrategy;

  if(!TEST_OPT_RETURN_SB)
    strat->syzComp = syzComp;
  if (TEST_OPT_SB_1)
    strat->newIdeal = newIdeal;
  if (rField_has_simple_inverse())
    strat->LazyPass=20;
  else
    strat->LazyPass=2;
  strat->LazyDegree = 1;
  strat->enterOnePair=enterOnePairNormal;
  strat->chainCrit=chainCritNormal;
  strat->ak = idRankFreeModule(F);
  strat->kModW=kModW=NULL;
  strat->kHomW=kHomW=NULL;
  if (vw != NULL)
  {
    pLexOrder=FALSE;
    strat->kHomW=kHomW=vw;
    pFDegOld = pFDeg;
    pLDegOld = pLDeg;
    pSetDegProcs(kHomModDeg);
    toReset = TRUE;
  }
  if (h==testHomog)
  {
    if (strat->ak == 0)
    {
      h = (tHomog)idHomIdeal(F,Q);
      w=NULL;
    }
    else if (!TEST_OPT_DEGBOUND)
    {
      h = (tHomog)idHomModule(F,Q,w);
    }
  }
  pLexOrder=b;
  if (h==isHomog)
  {
    if (strat->ak > 0 && (w!=NULL) && (*w!=NULL))
    {
      strat->kModW = kModW = *w;
      if (vw == NULL)
      {
        pFDegOld = pFDeg;
        pLDegOld = pLDeg;
        pSetDegProcs(kModDeg);
        toReset = TRUE;
      }
    }
    pLexOrder = TRUE;
    if (hilb==NULL) strat->LazyPass*=2;
  }
  strat->homog=h;
#ifdef KDEBUG
  idTest(F);
  idTest(Q);

#if MYTEST
  if (TEST_OPT_DEBUG)
  {
    PrintS("// kSTD: currRing: ");
    rWrite(currRing);
  }
#endif

#endif
#ifdef HAVE_PLURAL
  if (rIsPluralRing(currRing))
  {
    const BOOLEAN bIsSCA  = rIsSCA(currRing) && strat->z2homog; // for Z_2 prod-crit
    strat->no_prod_crit   = ! bIsSCA;
    if (w!=NULL)
      r = nc_GB(F, Q, *w, hilb, strat);
    else
      r = nc_GB(F, Q, NULL, hilb, strat);
  }
  else
#endif
#ifdef HAVE_RINGS
  if (rField_is_Ring(currRing))
    r=bba(F,Q,NULL,hilb,strat);
  else
#endif
  {
    if (pOrdSgn==-1)
    {
      if (w!=NULL)
        r=mora(F,Q,*w,hilb,strat);
      else
        r=mora(F,Q,NULL,hilb,strat);
    }
    else
    {
      if (w!=NULL)
        r=bba(F,Q,*w,hilb,strat);
      else
        r=bba(F,Q,NULL,hilb,strat);
    }
  }
#ifdef KDEBUG
  idTest(r);
#endif
  if (toReset)
  {
    kModW = NULL;
    pRestoreDegProcs(pFDegOld, pLDegOld);
  }
  pLexOrder = b;
//Print("%d reductions canceled \n",strat->cel);
  HCord=strat->HCord;
  delete(strat);
  if ((delete_w)&&(w!=NULL)&&(*w!=NULL)) delete *w;
  return r;
}
