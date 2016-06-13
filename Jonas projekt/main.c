#include <ez8.h>
#include <sio.h>
#include "tri.h"
#include "ansi.h"
#include "styring.h"

void main() {
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


	do {} while(1);
}

