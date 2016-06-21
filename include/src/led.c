#include "charset.h"
#include "board.h"

void LEDsetString(char string[], char videoBuffer[5][6]) {
	char i, j;
	for(i=0; i < 5; i++) {
		for(j=0; j < 6; j++) {	
			videoBuffer[i][j]=character_data[string[i]-0x20][j];
		}
		videoBuffer[i][5]=0x00;
	}
}

void LEDupdate(char videoBuffer[5][6], char *i, char *j, char *p) {
	switch(*i) {
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
			(*p)++;
			break;
		default :
			break;
	}
		switch(*j) {
		case 0 :
			PGOUT=videoBuffer[*j][*i];
			PEOUT|=0x80;
			(*j)++;
			break;
		case 1 :
			PGOUT=videoBuffer[*j][*i];
			PGOUT|=0x80;
			(*j)++;
			break;
		case 2 :
			PGOUT=videoBuffer[*j][*i];
			PEOUT|=0x20;
			(*j)++;
			break;
		case 3 :
			PGOUT=videoBuffer[*j][*i];
			PEOUT|=0x40;
			*j = 0x00;
			(*i)++;				 
			break;
	}
	if(*p == 4) {
		*i = 0;
		*p = 0;
	}
	//printf("i = %d og j = %d\n",*i,*j);
	PEOUT&=0x1F;
	PGOUT&=0x7F;		
}


void LEDmoveString(char *string, char n, char m, char videoBuffer[5][6]) {
	char i,j;
	if(n==6) {
		for(i=0;i<5;i++) {
			videoBuffer[4][i]=character_data[string[m]-0x20][i];
		}
		videoBuffer[4][5]=0x00;
	}
	for(i=0;i<5;i++) {
		for(j=0;j<6;j++) {
			videoBuffer[i][j]=videoBuffer[i][j+1];
		}
   	}
}

void LEDupdateLife(char *string, char life) {
	string[4] = life;
}

void LEDupdateLevel(char *string, char level) {
	string[12] = level;
}

void LEDupdatePoints(char *string, int points) {
	string[21]=points/1000 + 0x30;
	string[22]=(points%1000)/100 + 0x30;
	string[23]=(points%100)/10 + 0x30;
	string[24]=points%10 + 0x30;
}
