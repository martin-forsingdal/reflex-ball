#include "ansi.h"
#include "tri.h"
#include "LUT.h"
#include "board.h"
#include "charset.h"
#include "fixpoint.h"

#ifndef styring_h
#define styring_h


void reflectBallWall(struct TVector *vector);
void startBall(struct TVector *vector);
void moveBall(struct TVector *vector);
void updateStriker(char readKey, char *striker);
void initStriker(char striker);

#endif	// styring_h
