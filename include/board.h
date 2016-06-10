#include <eZ8.h>
#include <sio.h>

#ifndef board_h
#define board_h

void initButton();
char readKey();
void initTimer(char h, char l);
void initConsole(int f, int b);
void LEDinit();

#endif // board_h

