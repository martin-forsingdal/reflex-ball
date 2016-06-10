#include "ansi.h";
#include "LUT.h";
#include "fixpoint.h";
#include "tri.h";
#include "board.h";
#include "charset.h";

extern char character_data[95][5];
char videoBuffer[5][6];
char flag;

#pragma interrupt
void timer0int() {
	flag=0x01;
}

void main() {
	
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);

	initTimer(0x04, 0x80);
	initConsole(15,4);
	
	SET_VECTOR(TIMER0, timer0int);
	EI();
	
	window(1,1,60,20);

	
	DI();
	

	do {} while (1);
}
