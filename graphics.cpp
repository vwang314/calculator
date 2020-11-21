#include "graphics.h"

void print_status_bar(Adafruit_ILI9486_Teensy tft){
    tft.fillRect(0,0,480,10,BLUE);
}

void print_char(Adafruit_ILI9486_Teensy tft, char c, int pos_x, int pos_y){
    tft.setCursor(pos_x*12, (pos_y+1)*12);
    tft.print(c);
}

void print_result(Adafruit_ILI9486_Teensy tft, String res, int pos_y){
    tft.setCursor(450-(res.length()*12), (pos_y+2)*12);
    tft.print("= " + res);
    tft.drawFastHLine(0, (pos_y+3.5)*12, 480, BLACK);
}
