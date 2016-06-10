#include "ansi.h";
#include "LUT.h";
#include "fixpoint.h";
#include "tri.h";
#include "board.h";
#include "charset.h";
//Fuck dig Martin
extern char character_data[95][5];
char videoBuffer[5][6];
char flag;

#pragma interrupt
void timer0int() {
	flag=0x01;
}

//Hej Henning
void LEDsetString(char string[]) {
	char i, j;
	for(i=0; i < 6; i++) {
		for(j=0; j < 6; j++) {	
			videoBuffer[i][j]=character_data[string[i]-0x20][j];
		}
		videoBuffer[i][5]=0x00;
	}
}

void LEDupdate() {
	char i,j;
	for(i=0;i<5;i++) {
		switch(i) {
			case 0 :
				PEOUT=0x0F;
				break;
			case 1 :
				PEOUT=0x17;
				break;
			case 2 :
				PEOUT=0x1B;
				break;
			case 3 :
				PEOUT=0x1D;
				break;
			case 4 :
				PEOUT=0x1E;
				break;
		}
		for(j=0;j<4;) {
			if(flag==0x01) {
				switch(j) {
					case 0 :
						PGOUT=videoBuffer[j][i];
						PEOUT|=0x80;
						flag=0x00;
						break;
					case 1 :
						PGOUT=videoBuffer[j][i];
						PGOUT|=0x80;
						flag=0x00;
						break;
					case 2 :
						PGOUT=videoBuffer[j][i];
						PEOUT|=0x20;
						flag=0x00;
						break;
					case 3 :
						PGOUT=videoBuffer[j][i];
						PEOUT|=0x40;
						flag=0x00;
						break;
					}
					PEOUT&=0x1F;
					PGOUT&=0x7F;
					j++;
				}
			}
		}
}

void LEDmoveString(char *string, char n, char m) {
	char i,j;
	if(n==6) {
		for(i=0;i<5;i++) {
			videoBuffer[4][i]=character_data[string[m]-0x20][i];
		}
		videoBuffer[4][5]=0x00;
	}
	for(i=0;i<6;i++) {
		for(j=0;j<6;j++) {
			videoBuffer[i][j]=videoBuffer[i][j+1];
		}
   	}
}

void main() {
	char n=0,m=5;
	char s [64]= " Martin søger rimjob-modtager! ";
	int x=0;

	//Båndbredde på mikroprossesoren vælges
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);

	initTimer(0x04, 0x80);
	initConsole(15,4);
	LEDinit();

	SET_VECTOR(TIMER0, timer0int);
	EI();
	
	LEDsetString(s);
	
	while(1) {
		LEDupdate();
		x++;
		if(x==5) {
			LEDmoveString(s,n,m);
			x=0;
			n++;
			if(n>6){
				m++;
				n=0;
				
			}
			if(m==30) {
				m=0;
			}
		}
	}
	DI();

	do {} while (1);
}
