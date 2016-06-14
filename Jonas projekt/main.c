#include "tiles.h"

void main() {
	
	char tilesOne[11][24];
	initTileArray(tilesOne);
	levelOne(tilesOne);
	printf("Række 0: %c\n",tilesOne[0][3]);
	printf("Række 1: %c\n",tilesOne[1][3]);
	printf("Række 2: %c\n",tilesOne[2][3]);
	printf("Række 3: %c\n",tilesOne[3][3]);
	do {} while (1);

}

