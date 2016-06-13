#include "ansi.h"
#include "tri.h"
#include "LUT.h"
#include "board.h"
#include "charset.h"
#include "fixpoint.h"

#ifndef styring_h
#define styring_h


void reflectBallWall(struct Tvector *vector);
void startBall();
void moveBall(struct Tvector *vector);
void printBall(struct Tvector vector);

#endif	// styring_h
