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

void	AtInterrupt(void);
PROCESS	P1(void);
PROCESS	P2(void);
PROCESS	P3(void);

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
    
//    StartKernel();
    StartKernelForSim();
}

//Applikationprocesser

PROCESS P1(void)
{
    DO_FOREVER
    {
	_outchar('1');
    }	
}

PROCESS P2(void)
{
    DO_FOREVER
    {
	_outchar('2');
    }
	
  }

  
  PROCESS P3(void)
{
    DO_FOREVER
    {
	_outchar('3');
    }
	
  }


// Avbrottshantering
 
 void AtInterrupt(void)
 {
    
    insert_last(Running, &ReadyQ);
    Running = remque(&ReadyQ);
    
 }
 