#include "ansi.h"
#include "tri.h"
#include "LUT.h"
#include "board.h"
#include "fixpoint.h"

void startBall(struct TVector *vector){
	initVector(vector,0xffffffff,0xffffffff,30,15); 
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

