#include "ansi.h"
#include "tri.h"
#include "LUT.h"
#include "board.h"
#include "fixpoint.h"

void startBall(struct TVector *vector){
	initVector(vector,10,11,12,13); //hej
}
  
void moveBall(struct TVector *vector){
  vector->a=vector->a+vector->x;
  vector->b=vector->b+vector->y;
  }
  
void reflectBallWall(struct TVector *vector){
  if(vector->b>1){
    vector->x=~vector->x+1;
  }
  else
    vector->y=~vector->y+1;
}

void printBall(struct TVector *vector){
  int x,y;
  x=(int) ((vector->a+0x1000)>>14);
  y=(int) ((vector->b+0x1000)>>14);
  printf("V=(%ld,%ld),%d,%d",(vector->a)>>14,(vector->b)>>14,x,y);
  gotoxy(x,y);
  printf("%c", 'o');
}
