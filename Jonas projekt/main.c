#include <ez8.h>
#include <sio.h>
#include "tri.h"
#include "ansi.h"
#include "styring.h"

void main() {
<<<<<<< Updated upstream
	
<<<<<<< Updated upstream
	struct TVector v;
	startBall(&v);
	
	
	
	
=======
	long a,b;
	a = 4 << 14;
	b = 9 << 14;
	
>>>>>>> Stashed changes
	/*initVector(v, 7,8,9,8);
	/*printV(v);
	printFix(expand(sin(128)));
	printf("\n");
	printFix(expand(cos(128)));
	printf("\n");
	rotate(v, 128);
	printV(v);
	printFix(expand(sin(-128)));
	printf("\n");
	printFix(expand(cos(-128)));
	printf("\n");
	rotate(v, 0xff80);
	printV(v);*/
	
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
=======
	char i = 0x00;
	struct TVector v;
	startBall(&v);
	for(i = 0; i < 85; i++) {
		moveBall(&v);
		if(v.a == 2 << 14 || v.a == 59 << 14 || v.b == 2 << 14) {
			reflectBallWall(&v);
		}
		if(i == 30 || i == 54) {
			printf("(%d): V = ([%ld, %ld], [%ld, %ld])\n",i, v.x>>14, v.y>>14, v.a>>14, v.b>>14);
		}
	}
	printf("V = ([%ld, %ld], [%ld, %ld])\n", v.x>>14, v.y>>14, v.a>>14, v.b>>14);

>>>>>>> Stashed changes

	do {} while(1);
}

