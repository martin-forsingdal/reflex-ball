#include <eZ8.h>
#include <sio.h>
#include "ascii.h"

void initButton() {
	//Der vælges at PF7 og PF6 er input
	PFADDR = 0x01;
	PFCTL = 0xC0;
	PFADDR = 0;
	
	//Der vælges at PD3 er input
	PDADDR = 0x01;
	PDCTL = 0x08;
	PDADDR = 0;
}

//returns a char corresponding to the buttons pressed
char readKey() {
	return ((~PFIN) & 0x80)>>7 | ((~PFIN) & 0x40)>>5 |((~PDIN) & 0x08)>>1;
}

void initTimer(char h, char l) {
	
	//T0 disables og preskala og mode vælges
	T0CTL=0x19;

	//T0H og T0L nulstilles
	T0H=0x00;
	T0L=0x01;

	//T0RH og T0RL sættes til 23 040 samlet set ((18.432/2^3)/100)
	T0RH=h;
	T0RL=l;
	
	//IRQ0 enable 5th bit
	IRQ0ENH &= 0xDF;
	IRQ0ENL |= 0x20;

	//Timer startes
	T0CTL=0x99;
}

//Konsollen initialiseres til foreground color "f" og background color "b"
void initConsole(int f, int b) {
	fgcolor(f);
	bgcolor(b);
	clrscr();
	gotoxy(1,1);
}

void LEDinit() {
	//Der vælges at PE0 til PE7 er output
	PEADDR = 0x01;
	PECTL = 0x00;
	PEADDR = 0;

	//Der vælges at PG0 til PG7 er output
	PGADDR = 0x01;
	PGCTL = 0x00;
	PGADDR = 0;

	//Der skrives til PE og PG og led'er vælges
	PEOUT = 0x1F;
	PGOUT = 0x00;
}
