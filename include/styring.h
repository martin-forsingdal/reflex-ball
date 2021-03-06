#include "ansi.h"
#include "tri.h"
#include "LUT.h"
#include "board.h"
#include "fixpoint.h"

#ifndef styring_h
#define styring_h

void levelControl(char readKey, char *level);
void reflectBallWall(struct TVector *vector);
void startBall(struct TVector *vector, char level);
void moveBall(struct TVector *vector);
void removeBall(struct TVector *vector);
void updateStriker(char readKey, long *striker);
void initStriker(long *striker);
void reflectStriker(struct TVector *vector, long striker, char level);

#endif	// styring_h
