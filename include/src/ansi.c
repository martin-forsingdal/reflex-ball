#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines

#define ESC 0x1B

void fgcolor(int foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  int type = 22;             // normal text
	if (foreground > 7) {
	 	type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(int background) {
/*
    Value      Color      
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(int foreground, int background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  int type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);  
}

//clears the entire console screen
void clrscr() {
	printf("%c[2J",ESC);
}

//clears one line in the console
void clreol() {
	printf("%c[K",ESC);
}

//goes to the "x" column and "y" row
void gotoxy(int x, int y) {
	printf("%c[%d;%dH",ESC,y,x);
}

//enables underline in console
void underline(char on) {
	if(on=='1')
		printf("%c[%dm",ESC,04);
	else if(on=='0')
		printf("%c[%dm",ESC,24);
}

//enables blink in console
void blink(char on) {
	if(on=='1')
		printf("%c[%dm",ESC,05);
	else if(on=='0')
		printf("%c[%dm",ESC,25);
}

//enables reverse in console
void reverse(char on) {
	if(on=='1')
		printf("%c[%dm",ESC,07);
	else if(on=='0')
		printf("%c[%dm",ESC,27);
}

//draws a window starting at "x1,y1" to "x2,y2" with a specific style and a string in the window title
void window(int x1, int y1, int x2, int y2,int style, char *str) {
	int i, j, k=0, n=0;
	char array[2][8] = {	{201,187,200,188,205,186,185,204},
						{218,191,192,217,196,179,180,195}	};
	while(1) {
		if(str[k]=='\0')
			break;
		n++;
		k++;
	}
	gotoxy(x1,y1);
	printf("%c",array[style][0]);
	gotoxy(x2,y1);
	printf("%c",array[style][1]);
	gotoxy(x1,y2);
	printf("%c",array[style][2]);
	gotoxy(x2,y2);
	printf("%c",array[style][3]);
	gotoxy(x1+1,y1);
	printf("%c",array[style][6]);
	gotoxy(x1+2+n,y1);
	printf("%c",array[style][7]);
	reverse('1');
	gotoxy(x1+2,y1);
	printf("%s",str);
	reverse('0');
	for(i=x1+1; i<x2; i++) {
		gotoxy(i,y1);
		if(i>x1+2+n)
		printf("%c",array[style][4]);
		gotoxy(i,y2);
		printf("%c",array[style][4]);
	}
	for(j=y1+1; j<y2; j++) {
		gotoxy(x1,j);
		printf("%c",array[style][5]);
		gotoxy(x2,j);
		printf("%c",array[style][5]);
	}
}
