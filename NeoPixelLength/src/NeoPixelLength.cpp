/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/reed_/Documents/IoT/personal_projects/NeoPixelLength/src/NeoPixelLength.ino"
/*
 * Project NeoPixelLength
 * Description:  Determine the length of a NeoPixel string
 * Author:
 * Date:
 */
void setup();
void loop();
void pixelInt();
#line 7 "c:/Users/reed_/Documents/IoT/personal_projects/NeoPixelLength/src/NeoPixelLength.ino"
SYSTEM_MODE(SEMI_AUTOMATIC);
#include "NeoPixel.h"

const int PIXELOUTPIN = D6;
const int PIXELINPIN  = A0;
int i;
int pixelNum  = 1;  //  Initial pixel number
bool pixelMaxFlag = false;

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