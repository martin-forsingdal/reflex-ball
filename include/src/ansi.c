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

// Printer titlen "TILE CRASH"
void title() {
	bgcolor(7);
	fgcolor(1);
	gotoxy(12,5);
	printf(" ______  ");
	gotoxy(12,6);	
	printf("/\__  _\ ");
	gotoxy(12,7);
	printf("\/_/\ \/ ");
	gotoxy(12,8);
	printf("   \ \_\ ");
	gotoxy(12,9);
	printf("    \/_/ ");
	gotoxy(21,5);
	fgcolor(2);
	printf(" __    ");
	gotoxy(21,6);
	printf("/\ \   ");
	gotoxy(21,7);
	printf("\ \ \  ");
	gotoxy(21,8);
	printf(" \ \_\ ");
	gotoxy(21,9);
	printf("  \/_/ ");
	gotoxy(28,5);
	fgcolor(4);
	printf(" __        ");
	gotoxy(28,6);
	printf("/\ \       ");
	gotoxy(28,7);
	printf("\ \ \____  ");
	gotoxy(28,8);
	printf(" \ \_____\ ");
	gotoxy(28,9);
	printf("  \/_____/ ");
	gotoxy(39,5);
	fgcolor(5);
	printf(" ______    ");
	gotoxy(39,6);
	printf("/\  ___\   ");
	gotoxy(39,7);
	printf("\ \  __\   ");
	gotoxy(39,8);
	printf(" \ \_____\ ");
	gotoxy(39,9);
	printf("  \/_____/ ");
	gotoxy(53,5);
	fgcolor(8);
	printf(" ______    ");
	gotoxy(53,6);
	printf("/\  ___\   ");
	gotoxy(53,7);
	printf("\ \ \____  ");
	gotoxy(53,8);
	printf(" \ \_____\ ");
	gotoxy(53,9);
	printf("  \/_____/ ");
	fgcolor(1);
	gotoxy(64,5);
	printf(" ______    ");
	gotoxy(64,6);
	printf("/\  == \   ");
	gotoxy(64,7);
	printf("\ \  __<   ");
	gotoxy(64,8);
	printf(" \ \_\ \_\ ");
	gotoxy(64,9);
	printf("  \/_/ /_/ ");
	gotoxy(75,5);
	fgcolor(2);
	printf(" ______    ");
	gotoxy(75,6);
	printf("/\  __ \   ");
	gotoxy(75,7);
	printf("\ \  __ \  ");
	gotoxy(75,8);
	printf(" \ \_\ \_\ ");
	gotoxy(75,9);
	printf("  \/_/\/_/ ");
	gotoxy(86,5);
	fgcolor(4);
	printf(" ______    ");
	gotoxy(86,6);
	printf("/\  ___\   ");
	gotoxy(86,7);
	printf("\ \___  \  ");
	gotoxy(86,8);
	printf(" \/\_____\ ");
	gotoxy(86,9);
	printf("  \/_____/ ");
	gotoxy(97,5);
	fgcolor(5);
	printf(" __  __    \n");
	gotoxy(97,6);
	printf("/\ \_\ \   \n");
	gotoxy(97,7);
	printf("\ \  __ \  \n");
	gotoxy(97,8);
	printf(" \ \_\ \_\ \n");
	gotoxy(97,9);
	printf("  \/_/\/_/ \n");
	fgcolor(8);
	reverse('1');
	gotoxy(57,20);
	printf("Level 1");
	reverse('0');
	gotoxy(57,25);
	printf("Level 2");
	gotoxy(57,30);
	printf("Level 3");
	gotoxy(85,20);
	printf("%c%c%c%c%c = Unbreakable",219,219,219,219,219);
	gotoxy(85,23);
	fgcolor(2);
	printf("%c%c%c%c%c = 3 Health",178,178,178,178,178);
	gotoxy(85,26);
	fgcolor(3);
	printf("%c%c%c%c%c = 2 Health",177,177,177,177,177);
	fgcolor(9);
	gotoxy(85,29);
	printf("%c%c%c%c%c = 1 Health",176,176,176,176,176);
	fgcolor(0);
	gotoxy(9,33);
	printf("Button 3");
	gotoxy(19,33);
	printf("Button 2");
	gotoxy(29,33);
	printf("Button 1");
	fgcolor(1);
	gotoxy(10,35);
	printf("%c%c%c%c%c%c",220,219,219,219,219,220);
	gotoxy(10,36);
	printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(10,37);
	printf("%c%c%c%c%c%c",223,219,219,219,219,223);
	gotoxy(20,35);
	printf("%c%c%c%c%c%c",220,219,219,219,219,220);
	gotoxy(20,36);
	printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(20,37);
	printf("%c%c%c%c%c%c",223,219,219,219,219,223);
	gotoxy(30,35);
	printf("%c%c%c%c%c%c",220,219,219,219,219,220);
	gotoxy(30,36);
	printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(30,37);
	printf("%c%c%c%c%c%c",223,219,219,219,219,223);
	fgcolor(3);
	gotoxy(14,25);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);
	fgcolor(0);
	gotoxy(9,20);
	printf("Button 2");
	gotoxy(12,21);
	printf("%c",220);
	gotoxy(10,22);
	printf("%c%c%c%c%c%c%c",254,219,219,219,219,219,219);
	gotoxy(12,23);
	printf("%c",223);
	gotoxy(29,20);
	printf("Button 1");
	gotoxy(33,21);
	printf("%c",220);
	gotoxy(29,22);
	printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,254);
	gotoxy(33,23);
	printf("%c",223);
	gotoxy(85,35);
	printf("%c Button 3 is used to",219);
	gotoxy(85,36);
	printf("%c select or proceed",254);
}

// Funktionen printer "GAME OVER" meddelelse når alle liv er tabt
void gameOver(char life) {
	fgcolor(1);
	gotoxy(16,17);
	printf(" ______     ______     __    __     ______        ______     __   __   ______     ______   ");
	gotoxy(16,18);
	printf("/\  ___\   /\  __ \   /\ \"-./  \   /\  ___\      /\  __ \   /\ \ / /  /\  ___\   /\  == \ ");
	gotoxy(16,19);
	printf("\ \ \__ \  \ \  __ \  \ \ \-./\ \  \ \  __\      \ \ \/\ \  \ \ \\'/   \ \  __\   \ \  __<  ");
	gotoxy(16,20);
	printf(" \ \_____\  \ \_\ \_\  \ \_\ \ \_\  \ \_____\     \ \_____\  \ \__|    \ \_____\  \ \_\ \_\ ");
	gotoxy(16,21);
	printf("  \/_____/   \/_/\/_/   \/_/  \/_/   \/_____/      \/_____/   \/_/      \/_____/   \/_/ /_/");
}

// Funktionen printer "VICTORY" meddelelse når alle tiles er ødelagt
void victory(int points, unsigned char life, unsigned char level) {
	int lifeScore;
	life-=0x30;
	level-=0x30;
	lifeScore = (int) life*level*50;
	fgcolor(2);
	gotoxy(22,17);
	printf(" __   __   __     ______     ______   ______     ______     __  __     __");
	gotoxy(22,18);
	printf("/\ \ / /  /\ \   /\  ___\   /\__  _\ /\  __ \   /\  == \   /\ \_\ \   /\ \ ");
	gotoxy(22,19);
	printf("\ \ \\'/   \ \ \  \ \ \____  \/_/\ \/ \ \ \/\ \  \ \  __<   \ \____ \  \ \_\ ");
	gotoxy(22,20);
	printf(" \ \__|    \ \_\  \ \_____\    \ \_\  \ \_____\  \ \_\ \_\  \/\_____\  \/\_\ ");
	gotoxy(22,21);
	printf("  \/_/      \/_/   \/_____/     \/_/   \/_____/   \/_/ /_/   \/_____/   \/_/ ");
	gotoxy(44,24);
	printf("Final score: %04d + %d x %d = %d",points,life,level*50,points+lifeScore);
}

