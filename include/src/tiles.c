#include "ansi.h"
#include "tri.h"

void initTileArray(unsigned char tilesNumber[11][24]) {
	char i,j;
	for(i = 0x00; i < 11; i++) {
		for(j = 0x00; j < 24; j++) {
			tilesNumber[i][j] = '\0';
		}
	}
}

void levelOne(unsigned char tilesOne[11][24]) {
	char i = 0x00;
	char j = 0x00;
	char k = 0x00;
	initTileArray(tilesOne);
	for(i = 0; i < 11; i++) {
		for(j = 0; j< 24; j++) {
			tilesOne[i][j]=178-k;
			}
		k++;
		if(k==3){
			k=0;
		}
	}
	
}

void levelTwo(unsigned char tilesTwo[11][24]) {
	char i=0x00;
	char j=0x00;
	initTileArray(tilesTwo);
	for(i=0;i<10;i++){
		for(j=11-i;j<=12+i;j++){
			if(j==11 || j==12){
				tilesTwo[i][j]=176;
			}
			else{
			tilesTwo[i][j]=178;
		   	}
	    }
	}
	
	for(j=0;j<24;j++){
		if(j!=11 || j!=12){
			tilesTwo[10][j]=219;
		}
	}
}

void levelThree(unsigned char tilesThree[11][24]){
	char i=0x00;
	char j=0x00;
	initTileArray(tilesThree);
	for(i=0;i<11;i++){
		for(j=0;j<24;j++){
			if(i%2==0 && j%2==0){
				tilesThree[i][j]=219;
			}
			else{
				tilesThree[i][j]=178;
			}
		}
	}
}

void printLevel(unsigned char levelArray[11][24]){
	int color[4] = {1,2,4,5};
	char i=0x00;
	char j=0x00;
	char k=0x00;
	gotoxy(2,4);
	for(i=0;i<11;i++){
		for(j=0;j<24;j++){
			gotoxy(2+5*j,4+i);
			fgcolor(color[k]);
			k++;
			if(k == 4) {
				k = 0;
			}
			if(levelArray[i][j]=='\0'){
				printf("%c%c%c%c%c", ' ', ' ', ' ', ' ', ' ');
			}
			else{
				switch(levelArray[i][j]) {
					case 219:
 				    	fgcolor(8);
						printf("%c%c%c%c%c", 219, 219, 219, 219, 219);
						break;
					case 178:
						printf("%c%c%c%c%c", 178, 178, 178, 178, 178);
						break;
					case 177:
						printf("%c%c%c%c%c", 177, 177, 177, 177, 177);
						break;
					case 176:
						printf("%c%c%c%c%c", 176, 176, 176, 176, 176);
						break;
				}
			}
		}
	}
}

void tileUpdate(unsigned char levelArray[11][24], int i, int j){
	switch(levelArray[i][j]){
		case 178:
			levelArray[i][j]--;
			gotoxy(j*5+2,i+4);
			printf("%c%c%c%c%c", 177,177,177,177,177);
			break;
		case 177:
			levelArray[i][j]--;
			gotoxy(j*5+2,i+4);
			printf("%c%c%c%c%c", 176,176,176,176,176);
			break;
		case 176:
			levelArray[i][j]='\0';
			gotoxy(j*5+2,i+4);
			printf("%c%c%c%c%c", ' ',' ',' ',' ',' ');
			break;
	    default:
			break;
	}
}

void tileCheck(unsigned char levelArray[11][24], struct TVector *vector) {
	unsigned char x,y;
	int k, l, m;
	x = (vector->a + 0x2000) >> 14;
	y = (vector->b + 0x2000) >> 14;
	k=(x-2)/5;
	l=(x-1)/5;
	m=(x-3)/5;
	if(y==15){
		if(levelArray[y - 5][k]!= '\0') {
			(vector->y)=(~(vector->y)+1);
			tileUpdate(levelArray,y-5,k);
		}
	}
	else if(y==3){
			if(levelArray[y-3][k]!='\0'){
			(vector->y)=(~(vector->y)+1);
			tileUpdate(levelArray,y-3,k);
		}
	}
	else{
		if(levelArray[y - 5][k]!= '\0') {
			(vector->y)=(~(vector->y)+1);
			tileUpdate(levelArray,y-5,k);
		}
		else if(levelArray[y-3][k]!='\0'){
			(vector->y)=(~(vector->y)+1);
			tileUpdate(levelArray,y-3,k);
		}
		else if(levelArray[y-4][l]!= '\0'){
			(vector->x)=(~(vector->x)+1);
			tileUpdate(levelArray,y-4,l);
		}

		else if(levelArray[y-4][m]!= '\0'){
			(vector->x)=(~(vector->x)+1);
			tileUpdate(levelArray,y-4,m);
		}
	}
}

void printTileArray(unsigned char levelArray[11][24]) {
	char i,j;
	for(i=0;i<24;i++) {
		for(j=0;j<11;j++) {
			gotoxy(20+i,20+j);
			printf("%c",levelArray[j][i]);
		}
	}	
}






