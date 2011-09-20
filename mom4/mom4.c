/*
*
*	RTK - Applikation
*	"Non Pre emptive scheduling"
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

//    StartKernel();
    StartKernelForSim();
}

//Applikationprocesser

PROCESS P1(void)
{
    int i;
    for(i=0;i<1000;i++)
    	_outchar('1');
	
    TerminateProcess(0);	
}

PROCESS P2(void)
{
    int i;
    for(i=0;i<1000;i++)
    	_outchar('2');
	
    TerminateProcess(0);	

  }

 // Avbrottshantering
 
 void AtInterrupt(void)
 {
 
	// Vi gör inget
 
 }
 