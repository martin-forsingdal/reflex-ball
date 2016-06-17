#include <eZ8.h>
#include <sio.h>


#ifndef led_h
#define led_h

void LEDsetString(char string[], char videoBuffer[5][6]);
void LEDupdate(char videoBuffer[5][6], char *i, char *j, char *p);
void LEDmoveString(char *string, char n, char m, char videoBuffer[5][6]);
void LEDupdateString(char *string, char life);


#endif	// led_h
