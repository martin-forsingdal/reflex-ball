#ifndef tiles_h
#define tiles_h

void initTileArray(unsigned char tilesNumber[11][24]);
void levelOne(unsigned char tilesOne[11][24]);
void levelTwo(char tilesTwo[11][24]);
void levelThree(unsigned char tilesThree[11][24]);
void printLevel(unsigned char levelArray[11][24]);
void tileCheck(unsigned char levelArray[11][24], struct TVector *vector);
void tileUpdate(unsigned char levelArray[11][24], int y, int x);


#endif	// tiles_h
