#include "ansi.h"
#include "tri.h"
#include "LUT.h"
#include "board.h"
#include "fixpoint.h"

//initialiserer en vektor for bolden, med retning og hastighed.

void startBall(struct TVector *vector){
	initVector(vector,88,33,37);
}

/*flytter bolden med vektorens koordinater. laegger hastighedsvektoren sammen med stedvektoren. Derefter afrunder den og printer bolden. Inden da printes et
mellemrum p� boldens tidligere position.*/

void moveBall(struct TVector *vector){
  	int x,y;
	vector->a=vector->a+vector->x;
  	vector->b=vector->b+vector->y;
	x=(int) ((vector->a+0x2000)>>14);
	y=(int) ((vector->b+0x2000)>>14);
	gotoxy(x,y);
	if(y!=40)
	printf("%c", 'o');
  	}

void removeBall(struct TVector *vector) {
	gotoxy(vector->a+0x2000>>14,vector->b+0x2000>>14);
	if(vector->b+0x2000>>14!=40)
	printf("%c",' ');
}
  
/*reflekterer bolden n�r den rammer murene. Hvis y koordinaten er st�rre end 2 har den ramt en af siderne, ellers har den ramt toppen. 
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

void updateStriker(char c, long *striker) {
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

void initStriker(long striker) {
	char i;
	gotoxy(striker,40);
	for(i=0;i<18;i++) {
		printf("%c",223);
	}
}

void reflectStriker(struct TVector *vector, long striker) {
	long afstand=((vector->a+0x2000)>>14)-striker;
	gotoxy(((vector->a+0x2000)>>14),41);
	if(vector->x<0) {
		if(vector->angle<128) {
			vector->angle=256-vector->angle;
		}
		if(afstand<=4){			
			vector->angle+=(((256-vector->angle)>>4)*(8-afstand));
		}
		else{
			vector->angle-=((14)*(afstand-8));
		}
	}else {
		if((vector->angle)>(128)) {
			vector->angle=256-vector->angle;
		}
		if(afstand<=4){
			vector->angle+=((14)*(8-afstand));
		}
		else{
			vector->angle-=(((vector->angle)>>4)*(afstand-8));
		}
	}
	vector->y=sin(vector->angle+256);
	vector->x=cos(vector->angle);
	gotoxy(2,2);

	printf("%d",vector->angle);

}
