#include "LUT.h"
#include "fixpoint.h"

#ifndef tri_h
#define tri_h

struct TVector {
	long x,y;
	long a,b;
};

//long sin(int theta);
long cos(int theta);
void initVector(struct TVector *v, int theta, long startA, long startB);
void printV(struct TVector *v);
void rotate(struct TVector *v,int theta);

#endif //tri_h
