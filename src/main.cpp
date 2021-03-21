// Ref1. https://raspberrypi.mongonta.com/howto-start-m5stack-core2arduinoide/
// Ref2. https://note.com/katsushun89/n/nd2cbcb9d88a3
// Ref3. https://github.com/m5stack/m5-docs/blob/master/docs/ja/api/button.md

#include <Arduino.h>
#include <M5Core2.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

/*
#include <map>
#include <Fonts/EVA_20px.h>
#include <stdio.h>

enum {
  small = 0,
  midium,
  large,
  radius_threshold,
};

enum {
  black = 0,
  white,
  red,
  green,
  blue,
  yellow,
  purple,
  pink,
  color_threshold,
};

std::map<int, uint32_t> colorMap{
   {black, BLACK},
   {white, WHITE},
   {red, RED},
   {green, GREEN},
   {blue, BLUE},
   {yellow, YELLOW},
   {purple, PURPLE},
   {pink, PINK},
};

std::map<int, uint32_t> radiusMap{
   {small, 10},
   {midium, 15},
   {large, 25},
};

uint32_t color = red;
uint32_t radius = midium;
*/

void setup() {
  //M5.begin(true, true, true, true);
  M5.begin(true, false, false, false);
  M5.Lcd.setTextSize(2);
  //M5.Lcd.print("Hello World!!");
}

void loop() {
  M5.update();
  //TouchPoint_t pos = M5.Touch.getPressPoint();
  //static bool isPressed = false;

  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("Button A Status: ");
  M5.Lcd.println(M5.BtnA.isPressed());
  M5.Lcd.print("Button B Status: ");
  M5.Lcd.println(M5.BtnB.isPressed());
  M5.Lcd.print("Button C Status: ");
  M5.Lcd.println(M5.BtnC.isPressed());
  M5.Lcd.print("Touch Panel Status: ");
  M5.Lcd.println(M5.Touch.ispressed());     //include button A/B/C

  //isPressed = false;
  /*
  if(pos.y > 1 && pos.x > 1){
    //M5.Lcd.fillCircle(pos.x, pos.y, radiusMap[radius], colorMap[color]);
    M5.Lcd.println("1");
  }
  else
  {
    M5.Lcd.println("0");
  }
  */

/*
  if(!isPressed){
    if(pos.y > 240){
      if(pos.x < 120){//btnA
        isPressed = true;
      }
      else if(pos.x > 240){ //btnC
        isPressed = true;
      }
      else if(pos.x >= 180 && pos.x <= 210){ //btnB
        isPressed = true;
      }
    }
  }
  delay(10);
*/
}