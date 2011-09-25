// Moment 7

#include <_startup.h>		// för '_outchar'
#include <_rtk.h>

//Def.

#define DO_FOREVER	while(1)
#define	PROCESS 	void
#define TIMESLICE	100

#define ML13Status 		0xB01
#define ML13Control 		0xB00
#define ML13_IRQ_CONTROL	0xB01

#define readControl 		*((char *)ML13Status)
#define setControl(x) 		*((char *)ML13Control) = x

//Deklareringar

void 	yield ( int dummy);
void 	sleep(int delay);
void	AtInterrupt(void);

PROCESS manage_door();
PROCESS open_door_event();


//MAIN
int isDoorLocked = 1;

int main(void)
{




return(0);

}


void sleep(int delay)
{
int wakeup;
    
    wakeup = get_rtk_time() + delay;
    
    while(1)
    {
    
	if ( wakeup > get_rtk_time() )
		yield(0);
	else
		return;
    }
}

void yield ( int dummy)
{
    DISABLE;
    insert_last(Running, &ReadyQ);
    suspend(Running);
    dispatch();

}
PROCESS manage_door()
{
    DO_FOREVER
    {
	signalsem();
    }

}