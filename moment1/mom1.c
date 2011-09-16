/*
	mom1.c
	Enkel 'producent/konsument'
*/

#include	<_startup.h>	// För '_outchar'

#define BUFSIZE	25+1		// 25 tecken i engelska alfabetet 

char	buffer[BUFSIZE];
int position;


void	producer(void)
{
	char	tecken;
	position = -1;
	tecken = 'a';
	while(1){	// oändlig slinga 
		if(position < BUFSIZE-1){	
			buffer[++position]=tecken;
			if(tecken == 'z')
				tecken = 'a';
			else
				tecken++;
		}
	}
}

void	consumer(void)
{
	char	tecken;
	while(1){	// oändlig slinga 
		if(position >= 0){
			tecken = buffer[position--];
			_outchar( tecken);
		}
	}
}
