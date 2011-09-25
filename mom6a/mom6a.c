/*
*
*	RTK - Applikation
*	"Pre-emptive scheduling"
*
*/

#include <_startup.h>		// för '_outchar'
#include <_rtk.h>

// Definitioner

#define	TIMESLICE 	100
#define PROCESS		void
#define DO_FOREVER	while(1)
#define S1		1
#define S2		2
#define S3		3
#define S4		4

void	AtInterrupt(void);
PROCESS	P1(void);
PROCESS	P2(void);
PROCESS	P3(void);
PROCESS	P4(void);

main(void)
{

    InitKernel(TIMESLICE, AtInterrupt);
    
    if( CreateProcess("P1", P1) == -1)
    {
	// Fel, ingen process skapades
	ExitKernel();
    }
    
    if( CreateProcess("P2", P2) == -1)
    {
	// Fel, ingen process skapades
	ExitKernel();
    }

    if( CreateProcess("P3", P3) == -1)
    {
	// Fel, ingen process skapades
	ExitKernel();
    }
    
    if( CreateProcess("P4", P4) == -1)
    {
	// Fel, ingen process skapades
	ExitKernel();
    }

//	Init Semaforer

    initsem(S1,1);
    initsem(S2,0);
    initsem(S3,0);
    initsem(S4,0);
        
//    StartKernel();
    StartKernelForSim();
}

//Applikationprocesser

PROCESS P1(void)
{
    DO_FOREVER
    {
	waitsem(S1);
	_outchar('1');
	signalsem(S2);
    }	
}

PROCESS P2(void)
{
    DO_FOREVER
    {
	waitsem(S2);
	_outchar('2');
	signalsem(S3);
    }
	
  }

  
  PROCESS P3(void)
{
    DO_FOREVER
    {
	waitsem(S3);
	_outchar('3');
	signalsem(S4);
    }
	
  }

  PROCESS P4(void)
{
    DO_FOREVER
    {
	waitsem(S4);
	_outchar('4');
	signalsem(S1);
    }
	
  }

  
// Avbrottshantering
 
 void AtInterrupt(void)
 {
    
    insert_last(Running, &ReadyQ);
    Running = remque(&ReadyQ);
    
 }
 