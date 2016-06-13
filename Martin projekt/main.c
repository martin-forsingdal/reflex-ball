#include "ansi.h";
#include "LUT.h";
#include "fixpoint.h";
#include "tri.h";
#include "board.h";
#include "charset.h";
#include "styring.h";

char flag;

#pragma interrupt
void timer0int() {
	flag=0x01;
}

void main() {
	long temp = 10;
	struct TVector v;
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);

	initTimer(0x04, 0x80);
	initConsole(2,0);
	
	SET_VECTOR(TIMER0, timer0int);
	EI();
	startBall(&v);
	printBall(&v);

	do {} while (1);
}
