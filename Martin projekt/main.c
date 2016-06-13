#include "ansi.h";
#include "LUT.h";
#include "fixpoint.h";
#include "tri.h";
#include "board.h";
#include "charset.h";
#include "styring.h";

int t_m;
int t_s;

#pragma interrupt
void timer0int() {
	if(t_m > 999) {
		t_m = 0;
		t_s++;
	}else
	t_m++;
}

void main() {
	char striker = 10;
	struct TVector v;
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);

	initTimer(0x09, 0x00);
	initConsole(2,0);
	initButton();
	
	SET_VECTOR(TIMER0, timer0int);
	EI();
	window(1,1,122,39);
	startBall(&v);
	while(1) {
		if(100%t_m==0) {
			DI();
			moveBall(&v);
			if(v.a==2<<14 || v.a==119<<14 || v.b ==2<<14)
				reflectBallWall(&v); 
			EI();
			while(100%t_m==0) {
				2+2;
		   	}
		}
   }
   

	do {} while (1);
}
