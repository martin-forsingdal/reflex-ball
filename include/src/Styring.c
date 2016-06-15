#include "ansi.h"
#include "tri.h"
#include "LUT.h"
#include "board.h"
#include "fixpoint.h"

//initialiserer en vektor for bolden, med retning og hastighed.

void startBall(struct TVector *vector){
	initVector(vector,0xea,0x68,61,37);
}

/*flytter bolden med vektorens koordinater. laegger hastighedsvektoren sammen med stedvektoren. Derefter afrunder den og printer bolden. Inden da printes et
mellemrum på boldens tidligere position.*/

void moveBall(struct TVector *vector){
  	int x,y;
	gotoxy(2,2);
	printf("%d",vector->b>>14);
	gotoxy(vector->a+0x2000>>14,vector->b+0x2000>>14);
	printf("%c",' ');
	vector->a=vector->a+vector->x;
  	vector->b=vector->b+vector->y;
	x=(int) ((vector->a+0x2000)>>14);
	y=(int) ((vector->b+0x2000)>>14);
	gotoxy(x,y);
	printf("%c", 'o');
  	}
  
/*reflekterer bolden når den rammer murene. Hvis y koordinaten er større end 2 har den ramt en af siderne, ellers har den ramt toppen. 
Derefter inverteres enten x- eller y-koordinaten.*/

void reflectBallWall(struct TVector *vector){
 	if((vector->b)>(2<<14)){
    	(vector->x)=(~(vector->x)+1);
  	}
  	else
    	(vector->y)=(~(vector->y)+1);
}

void updateStriker(char c, long *striker) {
	if(c==0x01 && *striker < 113) {
		gotoxy(*striker,40);
		printf("%c",' ');
		*striker = *striker + 1;
		gotoxy(*striker+8,40);
		printf("%c",223);
	} else if(c==0x02 && *striker > 2) {
		gotoxy(*striker+8,40);
		printf("%c",' ');
		*striker = *striker -1;
		gotoxy(*striker,40);
		printf("%c",223);
	}
}

void initStriker(long striker) {
	char i;
	gotoxy(striker,40);
	for(i=0;i<9;i++) {
		printf("%c",223);
	}
}

void reflectStriker(struct TVector *vector, long striker) {
	//if(vector->a==striker+3 || vector->a==striker+4) {
		(vector->y)=(~(vector->y)+1);
	//}
}
