#include <SPI.h>
#include "Adafruit_ILI9486_Teensy.h"
#include <XPT2046_Touchscreen.h>
#include "graphics.h"
#include "graphing.h"
#include "rgb.h"
#include "sci_calc.h"
#include "systems_solver.h"
#include "table.h"


//Touchscreen pins
#define TS_CS_PIN  4        //chip select      Teensy4 - lcd26
#define TS_IRQ_PIN  3       //interrupt        Teensy3 - lcd11
//TFT LCD pins, defined in Adafruit_ILI9486_Teensy
//#define TFT_RST_PIN 8     //reset            Teensy8 - lcd22
//#define TFT_RS_PIN  9     //register select  Teensy9 - lcd18
//#define TFT_CS_PIN  10    //chip select      Teensy10 - lcd24
//#define TFT_MOSI_PIN 11   //MOSI             Teensy11 - lcd19
//#define TFT_MISO_PIN 12   //MISO             Teensy12 - lcd21
//#define TFT_SCLK_PIN 13   //SCLK             Teensy13 - lcd 23
//buttons
#define LBO_pin 1
#define LED1_pin 7
#define LED2_pin 5
#define LED3_pin 6
#define LED4_pin 2
#define KEY_shift 14
#define KEY_menu 15
#define KEY_root 16
#define KEY_clear 17
#define KEY_exp 18
#define KEY_lparenth 19
#define KEY_rparenth 20
#define KEY_div 21
#define KEY_7 22
#define KEY_8 23
#define KEY_9 28
#define KEY_mult 29
#define KEY_4 30
#define KEY_5 31
#define KEY_6 32
#define KEY_sub 33
#define KEY_1 34
#define KEY_2 35
#define KEY_3 36
#define KEY_add 37
#define KEY_0 38
#define KEY_dec 39
#define KEY_neg 40
#define KEY_eq 41
#define MENU 0
#define SCI_CALC 1
#define TABLE 2
#define GRAPHING 3
#define RGB 4
#define SYSTEMS_SOLVER 5


XPT2046_Touchscreen ts(TS_CS_PIN, TS_IRQ_PIN);
Adafruit_ILI9486_Teensy tft;
int entries = 0;
int char_index = 1;
int mode = SCI_CALC;


void setup() {

  Serial.begin(38400);
  SPI.begin();
  //Declare pins
  pinMode(TS_IRQ_PIN, INPUT);
  pinMode(TS_CS_PIN, OUTPUT);
  pinMode(LBO_pin, INPUT);
  pinMode(KEY_shift, INPUT_PULLUP);
  pinMode(KEY_menu, INPUT_PULLUP);
  pinMode(KEY_root, INPUT_PULLUP);
  pinMode(KEY_clear, INPUT_PULLUP);
  pinMode(KEY_exp, INPUT_PULLUP);
  pinMode(KEY_lparenth, INPUT_PULLUP);
  pinMode(KEY_rparenth, INPUT_PULLUP);
  pinMode(KEY_div, INPUT_PULLUP);
  pinMode(KEY_7, INPUT_PULLUP);
  pinMode(KEY_8, INPUT_PULLUP);
  pinMode(KEY_9, INPUT_PULLUP);
  pinMode(KEY_mult, INPUT_PULLUP);
  pinMode(KEY_4, INPUT_PULLUP);
  pinMode(KEY_5, INPUT_PULLUP);
  pinMode(KEY_6, INPUT_PULLUP);
  pinMode(KEY_sub, INPUT_PULLUP);
  pinMode(KEY_1, INPUT_PULLUP);
  pinMode(KEY_2, INPUT_PULLUP);
  pinMode(KEY_3, INPUT_PULLUP);
  pinMode(KEY_add, INPUT_PULLUP);
  pinMode(KEY_0, INPUT_PULLUP);
  pinMode(KEY_dec, INPUT_PULLUP);
  pinMode(KEY_neg, INPUT_PULLUP);
  pinMode(KEY_eq, INPUT_PULLUP);


  ts.begin();
  ts.setRotation(1);
  
  tft.begin();
  tft.setRotation( 3 );
  tft.fillScreen(WHITE);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  print_status_bar(tft);

  //tft.setCursor(10, 100);
  //tft.print("Output to Serial Monitor");
  delay(1000);

}

void loop() {  
  if(!digitalRead(LBO_pin)){
    //Low battery
  }

  switch(mode){
    case MENU:
    case SCI_CALC:
      mainloop(tft);
  }

  
  
}
