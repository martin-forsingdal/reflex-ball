#include "LUT.h"
#include "fixpoint.h"

//Struktur til vektorer
struct TVector {
	long x,y;
};

//Initialiserer en vektor til (10,20)
void initVector(struct TVector *v) {
	v->x = 10 << 14;
	v->y = 20 << 14;
}

//Printer en vektor på formatet "V=(x,y)
void printV(struct TVector *v) {
	printf("V=(");
	printFix(expand(v->x));
	printf(",");
	printFix(expand(v->y));
	printf(")\n");
}

//returns a sin value for theta
long sin(int theta) {
	theta = ~theta + 0x0001;
	theta += 0x0100;
	return SIN[theta & 0x01ff];
}

//returns a cos value for theta 
long cos(int theta) {
	return SIN[(theta +128) & 0x01ff];
}

//rotates a vector "v" with "theta" degrees.
void rotate(struct TVector *v, int theta) {
	long temp = v->x;
	v->x = (v->x*(cos(theta)>>14))-(v->y*(sin(theta)>>14));
	v->y = (temp*(sin(theta)>>14))+(v->y*(cos(theta)>>14));
}


