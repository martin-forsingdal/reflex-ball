#include <eZ8.h>
#include <sio.h>


#ifndef led_h
#define led_h

void LEDsetString(char string[], char videoBuffer[5][6]);
void LEDupdate(char videoBuffer[5][6], char *flag);
void LEDmoveString(char *string, char n, char m, char videoBuffer[5][6]);


#endif	// led_h
