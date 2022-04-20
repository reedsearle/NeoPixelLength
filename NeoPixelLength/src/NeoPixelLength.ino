/*
 * Project       NeoPixelLength
 * Description:  Determine the length of a NeoPixel string in real time
 * Author:       Reed Searle  
 * Date:         13 April 2022
 */


SYSTEM_MODE(SEMI_AUTOMATIC);
#include "NeoPixel.h"

const int PIXELOUTPIN = D6;     //  Output to start of NeoPixel string
const int PIXELINPIN  = A0;     //  Return from last NeoPixel DataOut pin
int i;
int pixelNum          = 1;      //  Initial pixel number
bool pixelMaxFlag     = false;

Adafruit_NeoPixel pixelRing(pixelNum, PIXELOUTPIN, WS2812B);


void setup() {
  Serial.begin(9600);
  delay(5000);
  Serial.printf("Serial begin\n");
  pinMode(PIXELINPIN, INPUT);
  attachInterrupt(PIXELINPIN, pixelInt, CHANGE);
  pixelRing.begin();
  pixelRing.clear();
  pixelRing.show();
}



void loop() {
  for(i=0; i<=pixelNum; i++) {
    pixelRing.setPixelColor(i, 0xFF0000);
  }
  pixelRing.show();

  if(!pixelMaxFlag) {
    Serial.printf("Pixel number incremented\n");
    pixelNum++;
    pixelRing.updateLength(pixelNum);
  } else {
    Serial.printf("There are %i Neopixel in this string\n", pixelNum);
    while(1) {noTone(A1);}
  }
}

void pixelInt() {
  pixelMaxFlag = true;
}