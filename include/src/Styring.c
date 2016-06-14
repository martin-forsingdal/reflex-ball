#include "ansi.h"
#include "tri.h"
#include "LUT.h"
#include "board.h"
#include "fixpoint.h"

void startBall(struct TVector *vector){
<<<<<<< Updated upstream
	initVector(vector,0xffffffff,0xffffffff,39,7); 
=======
	initVector(vector,0xffffffff,0xffffffff,61,39); 
>>>>>>> Stashed changes
}

void moveBall(struct TVector *vector){
  	int x,y;
	gotoxy(vector->a>>14,vector->b>>14);
	printf("%c",' ');
	vector->a=vector->a+vector->x;
  	vector->b=vector->b+vector->y;
	x=(int) ((vector->a+0x1000)>>14);
	y=(int) ((vector->b+0x1000)>>14);
	gotoxy(x,y);
	printf("%c", 'o');
  	}
  
void reflectBallWall(struct TVector *vector){
  if((vector->b)>(2<<14)){
    (vector->x)=(~(vector->x)+1);
  }
  else
    (vector->y)=(~(vector->y)+1);
}

void updateStriker(char c, char *striker) {
	if(c==0x01) {
		gotoxy(*striker,40);
		printf("%c",' ');
		*striker = *striker + 1;
		gotoxy(*striker+8,40);
		printf("%c",223);
	} else if(c==0x02) {
		gotoxy(*striker+8,40);
		printf("%c",' ');
		*striker = *striker -1;
		gotoxy(*striker,40);
		printf("%c",223);
	}
	gotoxy(2,2);
	printf("%d",*striker);
}

void initStriker(char striker) {
	char i;
	gotoxy(striker,40);
	for(i=0;i<9;i++) {
		printf("%c",223);
	}
}

