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

//draws a window starting at "x1,y1" to "x2,y2"
void window(int x1, int y1, int x2, int y2) {
	int i, j;
	char array[8] = {201,187,205,186};																																																	
	gotoxy(x1,y1);
	printf("%c",array[0]);
	gotoxy(x2,y1);
	printf("%c",array[1]);
	gotoxy(x1,y2);
	for(i=x1+1; i<x2; i++) {
		gotoxy(i,y1);
		printf("%c",array[2]);
	}
	for(j=y1+1; j<=y2; j++) {
		gotoxy(x1,j);
		printf("%c",array[3]);
		gotoxy(x2,j);
		printf("%c",array[3]);
	}
}


void menu() {
	bgcolor(7);
	fgcolor(1);
	gotoxy(2,10);
	printf(" ______  ");
	gotoxy(2,11);	
	printf("/\__  _\ ");
	gotoxy(2,12);
	printf("\/_/\ \/ ");
	gotoxy(2,13);
	printf("   \ \_\ ");
	gotoxy(2,14);
	printf("    \/_/ ");
	gotoxy(11,10);
	fgcolor(2);
	printf(" __    ");
	gotoxy(11,11);
	printf("/\ \   ");
	gotoxy(11,12);
	printf("\ \ \  ");
	gotoxy(11,13);
	printf(" \ \_\ ");
	gotoxy(11,14);
	printf("  \/_/ ");
	gotoxy(18,10);
	fgcolor(4);
	printf(" __        ");
	gotoxy(18,11);
	printf("/\ \       ");
	gotoxy(18,12);
	printf("\ \ \____  ");
	gotoxy(18,13);
	printf(" \ \_____\ ");
	gotoxy(18,14);
	printf("  \/_____/ ");
	gotoxy(29,10);
	fgcolor(5);
	printf(" ______    ");
	gotoxy(29,11);
	printf("/\  ___\   ");
	gotoxy(29,12);
	printf("\ \  __\   ");
	gotoxy(29,13);
	printf(" \ \_____\ ");
	gotoxy(29,14);
	printf("  \/_____/ ");
	gotoxy(43,10);
	fgcolor(8);
	printf(" ______    ");
	gotoxy(43,11);
	printf("/\  ___\   ");
	gotoxy(43,12);
	printf("\ \ \____  ");
	gotoxy(43,13);
	printf(" \ \_____\ ");
	gotoxy(43,14);
	printf("  \/_____/ ");
	fgcolor(1);
	gotoxy(54,10);
	printf(" ______    ");
	gotoxy(54,11);
	printf("/\  == \   ");
	gotoxy(54,12);
	printf("\ \  __<   ");
	gotoxy(54,13);
	printf(" \ \_\ \_\ ");
	gotoxy(54,14);
	printf("  \/_/ /_/ ");
	gotoxy(65,10);
	fgcolor(2);
	printf(" ______    ");
	gotoxy(65,11);
	printf("/\  __ \   ");
	gotoxy(65,12);
	printf("\ \  __ \  ");
	gotoxy(65,13);
	printf(" \ \_\ \_\ ");
	gotoxy(65,14);
	printf("  \/_/\/_/ ");
	gotoxy(76,10);
	fgcolor(4);
	printf(" ______    ");
	gotoxy(76,11);
	printf("/\  ___\   ");
	gotoxy(76,12);
	printf("\ \___  \  ");
	gotoxy(76,13);
	printf(" \/\_____\ ");
	gotoxy(76,14);
	printf("  \/_____/ ");
	gotoxy(87,10);
	fgcolor(5);
	printf(" __  __    \n");
	gotoxy(87,11);
	printf("/\ \_\ \   \n");
	gotoxy(87,12);
	printf("\ \  __ \  \n");
	gotoxy(87,13);
	printf(" \ \_\ \_\ \n");
	gotoxy(87,14);
	printf("  \/_/\/_/ \n");	
}
