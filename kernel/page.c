#include <kernel/mod2.h>
#ifdef PAGE_TEST
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/times.h>
#include <kernel/tok.h>
#include <kernel/page.h>

unsigned long mmPage_tab[MAX_PAGE_TAB];
char          mmUse_tab [MAX_PAGE_TAB];
int           mmPage_tab_ind=0;
int           mmPage_tab_acc=0;
static caddr_t  startAddr = (caddr_t) 0;

#ifndef  PROT_NONE
#define  PROT_NONE  0
#endif

#if ( !defined(MAP_ANONYMOUS) && defined(MAP_ANON) )
#define  MAP_ANONYMOUS  MAP_ANON
#endif


extern int  sys_nerr;
extern char *  sys_errlist[];

static const char * mmStringErrorReport(void)
{
  if ( errno > 0 && errno < sys_nerr )
    return sys_errlist[errno];
  else
    return "Unknown error.\n";
}

/*
 * Create memory.
 */
#if defined(MAP_ANONYMOUS)
void *
mmPage_Create(size_t size)
{
  caddr_t    allocation;

  /*
   * In this version, "startAddr" is a _hint_, not a demand.
   * When the memory I map here is contiguous with other
   * mappings, the allocator can coalesce the memory from two
   * or more mappings into one large contiguous chunk, and thus
   * might be able to find a fit that would not otherwise have
   * been possible. I could _force_ it to be contiguous by using
   * the MMAP_FIXED flag, but I don't want to stomp on memory mappings
   * generated by other software, etc.
   */
  allocation = (caddr_t) mmap(
   startAddr
  ,(int)size
  ,PROT_READ|PROT_WRITE
  ,MAP_PRIVATE|MAP_ANONYMOUS
  ,-1
  ,0);

  /*
   * Set the "address hint" for the next mmap() so that it will abut
   * the mapping we just created.
   *
   * HP/UX 9.01 has a kernel bug that makes mmap() fail sometimes
   * when given a non-zero address hint, so we'll leave the hint set
   * to zero on that system. HP recently told me this is now fixed.
   * Someone please tell me when it is probable to assume that most
   * of those systems that were running 9.01 have been upgraded.
   */
  startAddr = allocation + size;

  if ( allocation == (caddr_t)-1 )
    printf("mmap() failed: %s", mmStringErrorReport());

  if (mmPage_tab_ind<MAX_PAGE_TAB)
  {
    mmPage_tab[mmPage_tab_ind]=(long)allocation;
    if (mmPage_tab_ind==0)
    {
      memset(mmUse_tab,'0',MAX_PAGE_TAB);
    }
    mmPage_tab_ind++;
  }
  return (void *)allocation;
}
#else
void * mmPage_Create(size_t size)
{
  static int  devZeroFd = -1;
  caddr_t    allocation;

  if ( devZeroFd == -1 )
  {
    devZeroFd = open("/dev/zero", O_RDWR);
    if ( devZeroFd < 0 )
      printf( "open() on /dev/zero failed: %s",mmStringErrorReport());
  }

  /*
   * In this version, "startAddr" is a _hint_, not a demand.
   * When the memory I map here is contiguous with other
   * mappings, the allocator can coalesce the memory from two
   * or more mappings into one large contiguous chunk, and thus
   * might be able to find a fit that would not otherwise have
   * been possible. I could _force_ it to be contiguous by using
   * the MMAP_FIXED flag, but I don't want to stomp on memory mappings
   * generated by other software, etc.
   */
  allocation = (caddr_t) mmap(
   startAddr
  ,(int)size
  ,PROT_READ|PROT_WRITE
  ,MAP_PRIVATE
  ,devZeroFd
  ,0);

  startAddr = allocation + size;

  if ( allocation == (caddr_t)-1 )
    printf("mmap() failed: %s", mmStringErrorReport());

  if (mmPage_tab_ind<MAX_PAGE_TAB)
  {
    mmPage_tab[mmPage_tab_ind]=allocation;
    if (mmPage_tab_ind==0)
    {
      memset(mmUse_tab,'0',MAX_PAGE_TAB);
    }
    mmPage_tab_ind++;
  }
  return (void *)allocation;
}
#endif

void mmPage_AllowAccess(void * address)
{
  if ( mprotect((caddr_t)address, 4096, PROT_READ|PROT_WRITE) < 0 )
    printf("mprotect(READ|WRITE) failed: %s", mmStringErrorReport());
}

void mmPage_DenyAccess(void * address)
{
  if ( mprotect((caddr_t)address, 4096, PROT_NONE) < 0 )
    printf("mprotect(NONE) failed: %s", mmStringErrorReport());
}

void mmPage_Delete(void * address)
{
  if ( munmap((caddr_t)address, 4096) < 0 )
    mmPage_DenyAccess(address);
}

FILE *mmStatFile=NULL;
unsigned mmStatLines=0;
void mmWriteStat()
{
  int i,l,start;
  if (mmStatFile==NULL)
  {
    mmStatFile=fopen(MM_STAT_FILE,"w");
#if 0    
    fprintf(mmStatFile,"P1\n%d ???\n",MAX_PAGE_TAB);
#endif
  } 
  if ((mmUse_tab[MAX_PAGE_TAB-1]=='0')
   || (mmUse_tab[MAX_PAGE_TAB-1]=='1'))
  {
    mmStatLines++;
    l=MAX_PAGE_TAB;
    start=0;
    fprintf(mmStatFile,"%d\n",mmPage_tab_acc);
    /* fwrite("#\n", 2, 1, mmStatFile);*/
#if 0
    fflush(mmStatFile);
#endif
    /* fwrite("#\n", 2, 1, mmStatFile);*/
#if 0
    do
    {
      i=min(70,l);
      fwrite(&(mmUse_tab[start]), i, 1, mmStatFile);
      fwrite("\n", 1, 1, mmStatFile);
      start+=i;
      l-=i;
    } while (l>0);
#endif
  }
  memset(mmUse_tab,'0',MAX_PAGE_TAB);
  mmPage_tab_acc=0;
}

void mmEndStat()
{
  if (mmStatFile!=NULL)
  {
    mmWriteStat();
#if 0
    fprintf(mmStatFile,"# %d %d\n",MAX_PAGE_TAB,mmStatLines);
#endif
    fclose(mmStatFile);
  }
}
#endif
