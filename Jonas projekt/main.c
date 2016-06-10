#include <ez8.h>
#include <sio.h>
#include "tri.h"
#include "ansi.h"

void main() {
	int a = 0xff80;
	struct TVector *v, vector;
	v = &vector;
	
	
	initVector(v, 7,8);
	/*printV(v);
	printFix(expand(sin(128)));
	printf("\n");
	printFix(expand(cos(128)));
	printf("\n");*/
	rotate(v, 128);
	printV(v);
	/*printFix(expand(sin(-128)));
	printf("\n");
	printFix(expand(cos(-128)));
	printf("\n");*/
	rotate(v, 0xff80);
	printV(v);
	
	/*printFix(expand(sin(0)));
	printf("\n");
	printFix(expand(sin(64)));
	printf("\n");
	printFix(expand(sin(-111)));
	printf("\n");
	printFix(expand(sin(923)));
	printf("\n");
	printFix(expand(cos(0)));
	printf("\n");
	printFix(expand(cos(64)));
	printf("\n");
	printFix(expand(cos(-111)));
	printf("\n");
	printFix(expand(cos(923)));
	printf("\n");*/

	do {} while(1);
}

