

void levelOne(char tilesOne[11][24]) {
	char i = 0x00;
	char j = 0x00;
	char k = 0x00;
	for(i = 0; i < 11; i++) {
		for(j = 0; j< 24; j++) {
			tilesOne[i][j]=178-k;
			}
		k++;
		if(k==3){
			k=0;
		}
	}
	
	
	printf("Række 0: %c",tilesOne[0][5]);
	printf("Række 1: %c",tilesOne[1][5]);
	printf("Række 2: %c",tilesOne[2][5]);

}
