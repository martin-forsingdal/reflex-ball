#include "ansi.h"
#include "tri.h"
#include "LUT.h"
#include "board.h"
#include "charset.h"
#include "fixpoint.h"

void startBall(){
  Tvector vector={1,1,25<<14,47<<14}; //virker måske 
  void initVector(&vector);
  }
  
void moveBall(*Tvector vector){
  vector->a=vector->a+vector->x;
  vector->b=vector->b+vector->y;
  }
  
void reflectBallWall(*Tvector vector){
  if(vector->b>1){
    vector->x=~vector->x+1;
  }
  else
    vector->y=~vector->y+1;
}

void printBall(Tvector vector){
  int x,y;
  x=(int) ((vector->a+0x800)>>14);
  y=(int) ((vector->b+0x800)>>14);
  goto(x,y);
  printf("%c", 'o');
}
