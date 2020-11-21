#include "sci_calc.h"
//#include <iostream>
//#include <string>
//#include "muParser.h"
#include "graphics.h"

void mainloop(Adafruit_ILI9486_Teensy tft){
  print_char(tft, '1', 1, 1);
  String expression_string = "1";
  print_char(tft, '+', 2, 1);
  expression_string += '+';
  print_char(tft, '5', 3, 1);
  expression_string += "5";
  print_char(tft, '*', 4, 1);
  expression_string += '*';
  print_char(tft, '8', 5, 1);
  expression_string += '8';


  print_result(tft, "test", 1);


}
