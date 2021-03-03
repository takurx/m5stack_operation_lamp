// Ref. https://raspberrypi.mongonta.com/howto-start-m5stack-core2arduinoide/
#include <M5Core2.h>

void setup() {
  M5.begin(true, true, true, true);
  M5.Lcd.setTextSize(3);
  M5.Lcd.print("Hello World");
}

void loop() {

}
