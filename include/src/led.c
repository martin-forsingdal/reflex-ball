#include "ansi.h";
#include "LUT.h";
#include "fixpoint.h";
#include "tri.h";
#include "board.h";
#include "charset.h";

void LEDsetString(char string[], char videoBuffer[5][6]) {
	char i, j;
	for(i=0; i < 6; i++) {
		for(j=0; j < 6; j++) {	
			videoBuffer[i][j]=character_data[string[i]-0x20][j];
		}
		videoBuffer[i][5]=0x00;
	}
}

void LEDupdate(char videoBuffer[5][6], char *flag) {
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
			if(*flag==0x01) {
				switch(j) {
					case 0 :
						PGOUT=videoBuffer[j][i];
						PEOUT|=0x80;
						*flag=0x00;
						break;
					case 1 :
						PGOUT=videoBuffer[j][i];
						PGOUT|=0x80;
						*flag=0x00;
						break;
					case 2 :
						PGOUT=videoBuffer[j][i];
						PEOUT|=0x20;
						*flag=0x00;
						break;
					case 3 :
						PGOUT=videoBuffer[j][i];
						PEOUT|=0x40;
						*flag=0x00;
						break;
					}
					PEOUT&=0x1F;
					PGOUT&=0x7F;
					j++;
				}
			}
		}
}


void LEDmoveString(char *string, char n, char m, char videoBuffer[5][6]) {
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

//void LEDupdateString
