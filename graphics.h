#ifndef _graphics
#define _graphics

#include "Adafruit_ILI9486_Teensy.h"

void print_status_bar(Adafruit_ILI9486_Teensy tft);
void print_char(Adafruit_ILI9486_Teensy tft, char c, int pos_x, int pos_y);
void print_result(Adafruit_ILI9486_Teensy tft, String res, int pos_y);

#endif
