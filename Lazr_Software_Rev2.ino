/*
LAZr Universal Remote Glove
Designed by Om Anavekar
OMNi Technologies
1/17/19
*/

#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <Wire.h>  
#include "SSD1306Wire.h"

const int MUX_A = D5;
const int MUX_B = D6;
const int MUX_C = D7;

//Each value signifies a finger
int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;
int value5 = 0;


const int ANALOG_INPUT = A0;

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.

// PASTE DATA HERE
uint16_t powerOn[95] = {366, 1638,  368, 624,  388, 620,  366, 630,  350, 650,  388, 612,  362, 634,  366, 1634,  388, 612,  362, 1634,  362, 638,  362, 638,  362, 634,  362, 1634,  366, 638,  362, 47858,  362, 1642,  368, 634,  362, 638,  362, 634,  362, 638,  362, 1634,  362, 1634,  366, 638,  362, 1634,  362, 638,  368, 1630,  364, 1638,  366, 1630,  362, 638,  388, 1608,  362, 43728,  362, 1640,  362, 638,  362, 638,  362, 638,  358, 638,  362, 638,  366, 634,  362, 1634,  392, 608,  362, 1640,  362, 632,  388, 612,  362, 638,  362, 1634,  394, 606,  362}; 
uint16_t volumeUp[95] = {362, 1642,  362, 632,  372, 632,  364, 636,  362, 638,  358, 1638,  362, 638,  358, 1642,  360, 640,  358, 1642,  358, 636,  358, 642,  358, 642,  358, 1638,  358, 642,  358, 46866,  358, 1646,  358, 642,  358, 642,  358, 638,  362, 642,  358, 638,  358, 1642,  358, 640,  364, 1634,  358, 642,  358, 1638,  362, 1638,  362, 1640,  358, 636,  364, 1638,  362, 44728,  362, 1642,  362, 642,  362, 632,  362, 638,  358, 642,  358, 1638,  362, 642,  358, 1638,  362, 638,  358, 1638,  362, 638,  362, 636,  362, 638,  358, 1638,  368, 632,  362};
//Feel free to add as many data sets as you want. Just remember to give each data set a different name.

void setup() {
  //Deifne output pins for Mux
  pinMode(MUX_A, OUTPUT);
  pinMode(MUX_B, OUTPUT);     
  pinMode(MUX_C, OUTPUT);
  
  irsend.begin();
  Serial.begin(115200);
}

void changeMux(int c, int b, int a) {
  digitalWrite(MUX_A, a);
  digitalWrite(MUX_B, b);
  digitalWrite(MUX_C, c);
}

void loop() {
  changeMux(HIGH, LOW, LOW);
  value1 = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 0 pin of Mux
  Serial.print("F1: "); Serial.print(value1); Serial.print(" ");

  changeMux(LOW, LOW, HIGH);
  value2 = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 1 pin of Mux
  Serial.print("F2: "); Serial.print(value2); Serial.print(" ");

  changeMux(LOW, HIGH, LOW);
  value3 = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 2 pin of Mux
  Serial.print("F3: "); Serial.print(value3); Serial.print(" ");

  changeMux(LOW, HIGH, HIGH);
  value4 = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 3 pin of Mux
  Serial.print("F4: "); Serial.print(value4); Serial.print(" ");

  changeMux(LOW, LOW, LOW);
  value5 = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 4 pin of Mux
  Serial.print("F5: "); Serial.print(value5); Serial.println(" ");

  delay(200);

//You can make as many of the functions below as you like. 
  
//DISPLAY POWER
  if(value5 >= 310) {
    irsend.sendRaw(powerOn, 95, 38);  // Send a raw data capture at 38kHz.
    delay(100);
  }

//DISPLAY VOLUME UP
    if(value2 >= 310) {
    irsend.sendRaw(volumeUp, 95, 38);  // Send a raw data capture at 38kHz.
    delay(100);
  }
  

    
  
}
