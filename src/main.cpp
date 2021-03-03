#include <Arduino.h>
#include <M5Core2.h>

void setup() {
  //M5.begin();
  //M5.Power.begin();
  //M5.Lcd.print("Hello, World");
  M5.begin(true, true, true, true);
  M5.Lcd.setTextSize(3);
  M5.Lcd.print("Hello World!!");
}

void loop() {
  // put your main code here, to run repeatedly:
}