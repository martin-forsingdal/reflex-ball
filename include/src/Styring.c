#include "ansi.h"
#include "tri.h"
#include "LUT.h"
#include "board.h"
#include "fixpoint.h"


/* Skifter mellem at markere de tre forskellige level-valg i menuen. 
Knapper styrer om der gŒs op eller ned. */
void levelControl(char readKey, char *level) {
	fgcolor(8);
	switch(readKey) {
		case 0x01 :
			gotoxy(57,15+(5*(*level)));
			printf("Level %d",*level);
			if((*level)==3) {
				*level=1;
			} else {
				(*level)++;
			}
			reverse('1');
			gotoxy(57,15+(5*(*level)));
			printf("Level %d",*level);
			reverse('0');
			break;
		case 0x02 :
			gotoxy(57,15+(5*(*level)));
			printf("Level %d",*level);
			if((*level)==1) {
				*level=3;
			} else {
				(*level)--;
			}
			reverse('1');
			gotoxy(57,15+(5*(*level)));
			printf("Level %d",*level);
			reverse('0');
			break;
		default :
			break;
	}
}

// Initialiserer en vektor for bolden, med retning og hastighed.
void startBall(struct TVector *vector, char level){
	initVector(vector,88,33,39, level);
}

/* Flytter bolden med vektorens koordinater. laegger hastighedsvektoren sammen med
stedvektoren. Derefter afrunder den og printer bolden. Inden da printes et
mellemrum på boldens tidligere position.*/
void moveBall(struct TVector *vector){
  	int x,y;
	vector->a=vector->a+vector->x;
  	vector->b=vector->b+vector->y;
	x=(int) ((vector->a+0x2000)>>14);
	y=(int) ((vector->b+0x2000)>>14);
	gotoxy(x,y);
	fgcolor(0);
	//if(y<=39 && y>=1 && x>=2 && x<=121);
	printf("%c", 'o');
  	}

/* NŒr denne funktion bliver kaldt, overskriver den boldens sidste lokation med et 
mellemrum. Dette g¿res ved at printe et mellemrum pŒ denne plads. */
void removeBall(struct TVector *vector) {
	int x,y;
	x=(int) ((vector->a+0x2000)>>14);
	y=(int) ((vector->b+0x2000)>>14);
	gotoxy(x,y);
	if(y<=39 && y>=2 && x>=2 && x<=121);
	printf("%c",' ');
}
  
/* Reflekterer bolden når den rammer murene. Hvis y koordinaten er st¿rre end 2 
har den ramt en af siderne, ellers har den ramt toppen. 
Derefter inverteres enten x- eller y-koordinaten.*/
void reflectBallWall(struct TVector *vector){
 	if((vector->a)<(2<<14)){
    	(vector->x)=(~(vector->x)+1);
  	} else if((vector->a)>(119<<14)) {
		(vector->x)=(~(vector->x)+1);
	}
  	if((vector->b)<(2<<14)) {
    	(vector->y)=(~(vector->y)+1);
	}
}

/* Denne funktion opdaterer strikeren ved hj¾lp af char'en. Denne er inputtet fra 
en af knapperne. Derved bestemmes hvilke vej strikeren bev¾ger sig */ 
void updateStriker(char c, long *striker) {
	fgcolor(3);
	if(c==0x01 && *striker < 104) {
		gotoxy(*striker,40);
		printf("%c",' ');
		*striker = *striker + 1;
		gotoxy(*striker+17,40);
		printf("%c",223);
	} else if(c==0x02 && *striker > 2) {
		gotoxy(*striker+17,40);
		printf("%c",' ');
		*striker = *striker -1;
		gotoxy(*striker,40);
		printf("%c",223);
	}
}

// Denne funktione initialiserer og printer strikeren
void initStriker(long *striker) {
	char i;
	gotoxy(1,40);
	clreol();
	*striker=32;
	gotoxy(*striker,40);
	fgcolor(3);
	for(i=0;i<18;i++) {
		printf("%c",223);
	}
}

/* Funktionen bliver kun kaldt nŒr bolden befinder sig pŒ linjen over strikeren.
Den vurderer derefter indfaldsvinklen i forhold til den sidste udfaldsvinkel
fra strikeren og reflekterer i forskellige zoner bolden pŒ strikeren.*/
void reflectStriker(struct TVector *vector, long striker, char level) {
	long afstand=((vector->a+0x2000)>>14)-striker;
	if(vector->x<0) {
		if(vector->angle<128) {
			vector->angle=256-vector->angle;
		}
		if(afstand<=8){			
			vector->angle+=(((256-vector->angle)>>4)*(8-afstand));
		}
		else{
			vector->angle-=((14)*(afstand-8));
		}
	}else {
		if((vector->angle)>(128)) {
			vector->angle=256-vector->angle;
		}
		if(afstand<=8){
			vector->angle+=((14)*(8-afstand));
		}
		else{
			vector->angle-=(((vector->angle)>>4)*(afstand-8));
		}
	}
	vector->y=(sin(vector->angle+256)>>1)/(4-level);
	vector->x=(cos(vector->angle)>>1)/(4-level);
}
