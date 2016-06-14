#ifndef tiles_h
#define tiles_h

void initTileArray(char tilesNumber[11][24]);
void levelOne(char tilesOne[11][24]);
void levelTwo(char tilesTwo[11][24]);
void levelThree(char tilesThree[11][24]);
void printLevel(char levelArray[11][24]);
void tileCheck(char levelArray[11][24], struct TVector *vector);
void tileUpdate(char levelArray[11][24], int x, int y);


#endif	// tiles_h
