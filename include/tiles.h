#ifndef tiles_h
#define tiles_h

void initTileArray(unsigned char tilesNumber[11][15]);
void levelOne(unsigned char tilesOne[11][15]);
void levelTwo(unsigned char tilesTwo[11][15]);
void levelThree(unsigned char tilesThree[11][15]);
void levelChoose(unsigned char levelArray[11][15], char level);
void printLevel(unsigned char levelArray[11][15]);
void tileCheck(unsigned char levelArray[11][15], struct TVector *vector, int *points);
void tileUpdate(unsigned char levelArray[11][15], int y, int x, int *points);
void printTileArray(unsigned char levelArray[11][15]);


#endif	// tiles_h
