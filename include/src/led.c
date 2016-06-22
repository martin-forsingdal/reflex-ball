#include "charset.h"
#include "board.h"

void LEDsetString(char string[], char videoBuffer[5][6]) {
	char i, j;
	for(i=0; i < 5; i++) {
		for(j=0; j < 6; j++) {
		// de første fire tegn i strengen indlæses	
			videoBuffer[i][j]=character_data[string[i]-0x20][j];
		}
		// Den 5 kolonne slukkes helt så den fungerer som mellemrum
		videoBuffer[i][5]=0x00;
	}
}

/* Denne funktion opdaterer LED'erne hver gang den kaldes. Den skal kaldes
ialt 20 gange for at alle LED'erne er opdateret */
void LEDupdate(char videoBuffer[5][6], char *i, char *j, char *p) {
	switch(*i) {
		// i switchen afgør hvilken kolonne der er aktiv
		case 0 :
			PEOUT=0x0F;
			break;
		case 1 :
			PEOUT=0x17;
			break;
		case 2 :
			PEOUT=0x1B;
			break;
		case 3 :
			PEOUT=0x1D;
			break;
		case 4 :
			PEOUT=0x1E;
			/* p tæller hvor mange gange den sidste case er gennemkørt. Den 
			skal i alt køres 4 gange*/
			(*p)++;
			break;
		default :
			break;
	}
		// j switchen vælger hvilken LED'blok der skal klokkes
		switch(*j) {
		case 0 :
			PGOUT=videoBuffer[*j][*i];
			PEOUT|=0x80;
			(*j)++;
			break;
		case 1 :
			PGOUT=videoBuffer[*j][*i];
			PGOUT|=0x80;
			(*j)++;
			break;
		case 2 :
			PGOUT=videoBuffer[*j][*i];
			PEOUT|=0x20;
			(*j)++;
			break;
		case 3 :
			PGOUT=videoBuffer[*j][*i];
			PEOUT|=0x40;
			*j = 0x00;
			(*i)++;				 
			break;
	}
	// Når p er 4 skal der startes forfra med opdateringen af LED'erne
	if(*p == 4) {
		*i = 0;
		*p = 0;
	}
	// Latchenes klok sættes til 0 så de er klar til næste opdatering
	PEOUT&=0x1F;
	PGOUT&=0x7F;		
}


void LEDmoveString(char *string, char n, char m, char videoBuffer[5][6]) {
	char i,j;
	/* hvis i = 6 svarende til at karaktererne er rykket 5 gange på displayet
	indlæses den næste karakter på den sidste plads i videobufferen*/
	if(n==6) {
		for(i=0;i<5;i++) {
			videoBuffer[4][i]=character_data[string[m]-0x20][i];
		}
		// Igen sættes den sidste kolonne til et mellemrum
		videoBuffer[4][5]=0x00;
	}
	/* Hver gang LEDmoveString kaldes rykkes hvert element i arrayet
	en plads til venstre */
	for(i=0;i<5;i++) {
		for(j=0;j<6;j++) {
			videoBuffer[i][j]=videoBuffer[i][j+1];
		}
   	}
}

// Opdaterer strengen med det øjeblikkelige antal liv
void LEDupdateLife(char *string, char life) {
	string[4] = life;
}

// Opdaterer strengen med det øjeblikkelige level valg
void LEDupdateLevel(char *string, char level) {
	string[12] = level;
}

// Opdaterer strengen med det øjeblikkelige antal point
void LEDupdatePoints(char *string, int points) {
	string[21]=points/1000 + 0x30;
	string[22]=(points%1000)/100 + 0x30;
	string[23]=(points%100)/10 + 0x30;
	string[24]=points%10 + 0x30;
}
