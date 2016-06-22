#include "ansi.h"
#include "tri.h"

void initTileArray(unsigned char tilesNumber[11][15]){
	char i,j;
	for(i = 0x00; i < 11; i++) {
		for(j = 0x00; j < 15; j++) {
			tilesNumber[i][j] = '\0';
		}
	}
}
void levelOne(unsigned char tilesOne[11][15]){
	char i=0x00;
	char j=0x00;
	char k=0x00;
	initTileArray(tilesOne);
	for(i=0;i<11;i++){
		for(j=0;j<15;j++){
			if(i%2==0 || j%2==0){
				tilesOne[i][j]='\0';
			}
			else{
				tilesOne[i][j]=178-k;
				k++;
				if(k==3){
				k=0;
				}
			}
		}
	}
}

void levelTwo(unsigned char tilesTwo[11][15]) {
	char i=0x00;
	char j=0x00;
	initTileArray(tilesTwo);
	for(i=0;i<10;i++){
		for(j=7-i;j<=8+i;j++){
			if(j==7 || j==8){
				tilesTwo[i][j]=176;
			}
			else{
			tilesTwo[i][j]=178;
		   	}
	    }
	}
	
	for(j=0;j<15;j++){
		if(j!=7 && j!=8){
			tilesTwo[10][j]=219;
		}
	}
}

void levelThree(unsigned char tilesThree[11][15]){
	char i=0x00;
	char j=0x00;
	initTileArray(tilesThree);
	for(i=0;i<10;i++){
		for(j=0;j<15;j++){
			if(j!=6 && j!=7 && j!=8){
				tilesThree[i][j]=178;
			}
		}
	}
	for(j=0;j<15;j++){
		if(j!=6 && j!=7 && j!=8){
			tilesThree[10][j]=219;
		}
	}
	tilesThree[0][7]=177;
	tilesThree[1][7]=219;
}

void levelChoose(unsigned char levelArray[11][15], char level) {
	switch(level) {
		case 1:
			levelOne(levelArray);
			break;
	   	case 2:
			levelTwo(levelArray);
			break;
	   	case 3:
			levelThree(levelArray);
			break;
	}
}


void printLevel(unsigned char levelArray[11][15]){
	int color[4] = {1,2,4,5};
	char i=0x00;
	char j=0x00;
	char k=0x00;
	gotoxy(2,4);
	for(i=0;i<11;i++){
		for(j=0;j<15;j++){
			gotoxy(2+(j<<3),4+i);
			if(levelArray[i][j]=='\0'){
				printf("%c%c%c%c%c%c%c%c", ' ', ' ', ' ', ' ', ' ',' ',' ',' ');
			}
			else{
				switch(levelArray[i][j]) {
					case 219:
 				    	fgcolor(8);
						printf("%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
						break;
					case 178:
						fgcolor(2);
						printf("%c%c%c%c%c%c%c%c", 178, 178, 178, 178, 178, 178, 178, 178);
						break;
					case 177:
						fgcolor(3);
						printf("%c%c%c%c%c%c%c%c", 177, 177, 177, 177, 177, 177, 177, 177);
						break;
					case 176:
						fgcolor(9);
						printf("%c%c%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176, 176, 176);
						break;
				}
			}
		}
	}
}

void tileUpdate(unsigned char levelArray[11][15], int i, int j, int *points){
	switch(levelArray[i][j]){
		case 178:
			(*points)++;
			levelArray[i][j]--;
			fgcolor(3);
			gotoxy((j<<3)+2,i+4);
			printf("%c%c%c%c%c%c%c%c", 177,177,177,177,177, 177, 177, 177);
			break;
		case 177:
			*points+=2;
			levelArray[i][j]--;
			gotoxy((j<<3)+2,i+4);
			fgcolor(9);
			printf("%c%c%c%c%c%c%c%c", 176,176,176,176,176, 176, 176, 176);
			break;
		case 176:
			*points+=5;
			levelArray[i][j]='\0';
			gotoxy((j<<3)+2,i+4);
			printf("%c%c%c%c%c%c%c%c", ' ',' ',' ',' ',' ',' ',' ',' ');
			break;
	    default:
			break;
	}
}

void tileCheck(unsigned char levelArray[11][15], struct TVector *vector, int *points) {
	unsigned char x,y;
	int k, l, m;
	x = (vector->a + 0x2000) >> 14;
	y = (vector->b + 0x2000) >> 14;
	k=(x-2)>>3;
	l=(x-1)>>3;
	m=(x-3)>>3;
	if(y==15){
		if((levelArray[y - 5][k]==176 || levelArray[y - 5][k]==177 || levelArray[y - 5][k]==178 || levelArray[y - 5][k]==219) && (vector->y<0)) {
				(vector->y)=(~(vector->y)+1);
				tileUpdate(levelArray,y-5,k, points);
		}
	}
	else if(y==3){
			if((levelArray[y - 3][k]==176 || levelArray[y - 3][k]==177 || levelArray[y - 3][k]==178 || levelArray[y - 3][k]==219) && (vector->y>0)){
				(vector->y)=(~(vector->y)+1);
				tileUpdate(levelArray,y-3,k, points);
		    }
	}
	else{
		if((levelArray[y - 5][k]==176 || levelArray[y - 5][k]==177 || levelArray[y - 5][k]==178 || levelArray[y - 5][k]==219) && (vector->y<0))  {
				(vector->y)=(~(vector->y)+1);
				tileUpdate(levelArray,y-5,k, points);
		}
		if((levelArray[y - 3][k]==176 || levelArray[y - 3][k]==177 || levelArray[y - 3][k]==178 || levelArray[y - 3][k]==219) && (vector->y>0)){
				(vector->y)=(~(vector->y)+1);
				tileUpdate(levelArray,y-3,k, points);  
		}
		if((levelArray[y - 4][l]==176 || levelArray[y - 4][l]==177 || levelArray[y - 4][l]==178 || levelArray[y - 4][l]==219) && (vector->x>0) && x!=121){
				(vector->x)=(~(vector->x)+1);
				tileUpdate(levelArray,y-4,l, points);
		}

		if((levelArray[y - 4][m]==176 || levelArray[y - 4][m]==177 || levelArray[y - 4][m]==178 || levelArray[y - 4][m]==219) && (vector->x<0) && x!=2){
				(vector->x)=(~(vector->x)+1);
				tileUpdate(levelArray,y-4,m, points);
		}
	}
}

void printTileArray(unsigned char levelArray[11][15]) {
	char i,j;
	for(i=0;i<15;i++) {
		for(j=0;j<11;j++) {
			gotoxy(20+i,20+j);
			if(levelArray[j][i]=='\0') {
				printf(" ");
			} else {
				printf("%c",levelArray[j][i]);
			}
		}
	}	
}






