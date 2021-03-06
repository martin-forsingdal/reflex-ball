#include "LUT.h"
#include "fixpoint.h"

#ifndef tri_h
#define tri_h

struct TVector {
	long x,y;
	long a,b;
	unsigned int angle;
};

long sin(int theta);
long cos(int theta);
void initVector(struct TVector *v, int theta, long startA, long startB, char level);
void rotate(struct TVector *v,int theta);

#endif //tri_h
