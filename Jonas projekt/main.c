#include "tiles.h"

void main() {
	
	char tilesOne[11][24];
	initTileArray(tilesOne);
	levelOne(tilesOne);
	printf("R�kke 0: %c\n",tilesOne[0][3]);
	printf("R�kke 1: %c\n",tilesOne[1][3]);
	printf("R�kke 2: %c\n",tilesOne[2][3]);
	printf("R�kke 3: %c\n",tilesOne[3][3]);
	do {} while (1);

}

