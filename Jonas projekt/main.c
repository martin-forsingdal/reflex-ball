#include "tiles.h"

void initTileArray(char tilesNumber[11][24]) {
	char i,j;
	for(i = 0x00; i < 11; i++) {
		for(j = 0x00; j < 24; j++) {
			tilesNumber[i][j] = '\0';
		}
	}
}

void main() {
	
	char tilesOne[11][24];
	initTileArray(tilesOne);
	levelOne(tilesOne);
	printf("%c",tilesOne[2][3]);
	do {} while (1);

}

