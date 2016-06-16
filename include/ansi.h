#include <eZ8.h>
#include <sio.h>

#ifndef _ANSI_H_
#define _ANSI_H_

#define ESC 0x1B
void fgcolor(int foreground);
void bgcolor(int background);
void color(int foreground, int background);
void resetbgcolor();
void clrscr();
void clreol();
void gotoxy(int x, int y);
void underline(char on);
void blink(char on);
void reverse(char on);
void window(int x1, int y1, int x2, int y2);
void menu();

#endif // _ANSI_H_
