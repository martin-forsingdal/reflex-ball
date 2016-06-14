

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
	
}

void levelTwo(char tilesTwo[11][24]) {
	char i=0x00;
	char j=0x00;
	for(i=0;i<10;i++){
		for(j=11-i;j<=12+i;j++){
			if(j==11 || j==12){
				tilesTwo[i][j]=176;
			}
			else{
			tilesTwo[i][j]=178;
		   	}
	    }
	}
	
	for(j=0;j<24;j++){
		if(j!=11 || j!=12){
			tilesTwo[10][j]=219;
		}
	}
}

void levelThree


