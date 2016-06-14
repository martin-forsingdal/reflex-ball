#include "ansi.h"
#include "tri.h"

void initTileArray(char tilesNumber[11][24]) {
	char i,j;
	for(i = 0x00; i < 11; i++) {
		for(j = 0x00; j < 24; j++) {
			tilesNumber[i][j] = '\0';
		}
	}
}

void levelOne(char tilesOne[11][24]) {
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

void levelTwo(char tilesTwo[11][24]) {
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

void levelThree(char tilesThree[11][24]){
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

void tileUpdate(char levelArray[11][24], int x, int y){
	switch(levelArray[y][x]){
		case 219:
			break;
		case 178:
			levelArray[y][x]--;
			gotoxy(y+4,x*5+2);
			printf("%c%c%c%c%c", 177,177,177,177,177);
			break;
		case 177:
			levelArray[y][x]--;
			gotoxy(y+4,x*5+2);
			printf("%c%c%c%c%c", 176,176,176,176,176);
			break;
		case 176:
			levelArray[y][x]='/0';
			gotoxy(y+4,x*5+2);
			printf("%c%c%c%c%c", ' ',' ',' ',' ',' ');
			break;
	}
}

void tileCheck(char levelArray[11][24], struct TVector *vector) {
	unsigned char x,y;
	int k;
	x = (vector->a + 0x8000) >> 14; //Muligvis behov for char conversion.
	y = (vector->b + 0x8000) >> 14;
	k=x/5;
	if(y==15){
		if(levelArray[y - 5][k-2]!= '/0') {
			(vector->y)=(~(vector->y)+1);
			tileUpdate(levelArray,y-5,k-2);
		}
	else{
		if(levelArray[y - 5][k-2]!= '/0') {
			(vector->y)=(~(vector->y)+1);
			tileUpdate(levelArray,y-5,k-2);
		}
		else if(levelArray[y-3][k-2]!='/0'){
			(vector->y)=(~(vector->y)+1);
			tileUpdate(levelArray,y-3,k-2);
		}
		else if(levelArray[y-4][k-1]!= '/0'){
			(vector->x)=(~(vector->x)+1);
			tileUpdate(levelArray,y-4,k-1);
		}

		else if(levelArray[y-4][k-3]!= '/0'){
			(vector->x)=(~(vector->x)+1);
			tileUpdate(levelArray,y-4,k-3);
		}
	}
}






