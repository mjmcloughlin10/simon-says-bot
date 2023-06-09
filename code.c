// generated by mBlock5 for MegaPi
// codes make you happy

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "src/MeSingleLineFollower.h"
#include "src/MeCollisionSensor.h"
#include "src/MeBarrierSensor.h"
#include "src/MeNewRGBLed.h"
#include <MeMegaPi.h>

#define BLUE 0
#define PURPLE 1
#define YELLOW 2
#define ORANGE 3
#define GREEN 4

MeNewRGBLed rgbled_67(67,4);
MeNewRGBLed rgbled_68(68,4);
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeBarrierSensor barrier_60(60);
MeBarrierSensor barrier_61(61);
MeBarrierSensor barrier_62(62);
MeCollisionSensor collision_65(65);
MeCollisionSensor collision_66(66);

int counter = 0;
int colors[100];
int len_colors = 0;
int choices[5] = {BLUE, YELLOW, PURPLE, ORANGE, GREEN};

void show_colors(){
  counter = 0;
  while(!(counter >= len_colors))
  {
    _loop();
    if(colors[counter] == BLUE){
      blue();
    }
    if(colors[counter] == YELLOW){
      yellow();
    }
    if(colors[counter] == PURPLE){
      purple();
    }
    if(colors[counter] == ORANGE){
      orange();
    }
    if(colors[counter] == GREEN){
      green();
    }
    _delay(0.6);
    off();
    _delay(0.4);
    counter ++;

  }

}
void orange(){

  rgbled_67.setColor(0, 255,100,0);
  rgbled_67.show();

  rgbled_68.setColor(0, 255,100,0);
  rgbled_68.show();

}
void purple(){

  rgbled_67.setColor(0, 191,0,255);
  rgbled_67.show();

  rgbled_68.setColor(0, 199,0,255);
  rgbled_68.show();

}
void blue(){

  rgbled_67.setColor(0, 0,157,255);
  rgbled_67.show();

  rgbled_68.setColor(0, 0,157,255);
  rgbled_68.show();

}
void yellow(){

  rgbled_67.setColor(0, 255,255,0);
  rgbled_67.show();

  rgbled_68.setColor(0, 255,255,0);
  rgbled_68.show();

}
void off(){

  rgbled_67.setColor(0, 0,0,0);
  rgbled_67.show();

  rgbled_68.setColor(0, 0,0,0);
  rgbled_68.show();

}
void green(){

  rgbled_67.setColor(0, 126,211,33);
  rgbled_67.show();

  rgbled_68.setColor(0, 126,211,33);
  rgbled_68.show();

}
void red(){

  rgbled_67.setColor(0, 255,0,0);
  rgbled_67.show();

  rgbled_68.setColor(0, 255,0,0);
  rgbled_68.show();

}
void check_colors(){
  counter = 0;
  while(!(counter >= len_colors))
  {
    _loop();
    while(!(((barrier_60.isBarried())  ||  (barrier_61.isBarried()))  ||  ((barrier_62.isBarried())  ||  ((collision_65.isCollision())  ||  (collision_66.isCollision())))))
    {
      _loop();
    }
    if(colors[counter] == BLUE){
      if(barrier_60.isBarried()){
        blue();

      }else{
        red();

      }

    }
    if(colors[counter] == YELLOW){
      if(barrier_61.isBarried()){
        yellow();

      }else{
        red();

      }

    }
    if(colors[counter] == PURPLE){
      if(barrier_62.isBarried()){
        purple();

      }else{
        red();

      }

    }
    if(colors[counter] == ORANGE){
      if(collision_65.isCollision()){
        orange();

      }else{
        red();

      }

    }
    if(colors[counter] == GREEN){
      if(collision_65.isCollision()){
        green();

      }else{
        red();

      }

    }
    _delay(0.6);
    off();
    _delay(0.4);
    counter += 1;

  }

}
void add_random_color(){
  // To be defined
   randomSeed(millis());
    int choice = (int) random(5);
    colors[len_colors] = choices[choice];
    len_colors++;
}

void _delay(float seconds) {
  if(seconds < 0.0){
    seconds = 0.0;
  }
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  rgbled_67.fillPixelsBak(0, 2, 1);
  rgbled_68.fillPixelsBak(0, 2, 1);
  TCCR1A = _BV(WGM10);
  TCCR1B = _BV(CS11) | _BV(WGM12);
  TCCR2A = _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS21);
  // To be defined
    len_colors = 0;
    randomSeed(millis());
}

void _loop() {
}

void loop() {
  add_random_color();
  show_colors();
  check_colors();
  _delay(1);

  _loop();
}