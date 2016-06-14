#include "ansi.h";
#include "LUT.h";
#include "fixpoint.h";
#include "tri.h";
#include "board.h";
#include "charset.h";
#include "styring.h";
#include "tiles.h";

int t_1;
int t_2;

#pragma interrupt
void timer0int() {
	if(t_1 > 19) {
		t_1 = 0;
	}else
	t_1++;
	if(t_2>39) {
		t_2=0;
	}else
	t_2++;
}

void main() {
	long striker = 57;
	struct TVector v;
	char tilearray[11][24];
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);

	initTimer(0x09, 0x00);
	initConsole(5,7);
	initButton();
	levelThree(tilearray);
	
	SET_VECTOR(TIMER0, timer0int);
	EI();
	window(1,1,122,40);
	initStriker(striker);
	startBall(&v);
	printLevel(tilearray);
	while(1) {
		if(t_1==20) {
			DI();
			updateStriker(readKey(),&striker);
			EI();
		}
		if(t_2==40) {
			DI();
			
			if(v.a==2<<14 || v.a==119<<14 || v.b ==2<<14) {
				reflectBallWall(&v); 
			}else if(v.a>=striker<<14 && v.a<striker+9<<14 && v.b==39<<14 && v.y>0) {
				reflectStriker(&v);
			}
			moveBall(&v);
			EI();
		}
   }
   

	do {} while (1);
}
