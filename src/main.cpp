// Ref1. https://raspberrypi.mongonta.com/howto-start-m5stack-core2arduinoide/
// Ref2. https://note.com/katsushun89/n/nd2cbcb9d88a3
// Ref3. https://github.com/m5stack/m5-docs/blob/master/docs/ja/api/button.md

#include <Arduino.h>
#include <M5Core2.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

#include <wifi_pass.h>
//extern const char* ca;

WiFiMulti wifiMulti;
HTTPClient http;

void setup() {
  M5.begin(true, false, false, false);
  M5.Lcd.setTextSize(2);
  //M5.Lcd.print("Hello World!!");

  // WifiSetup
  wifiMulti.addAP(WIFI_SSID, WIFI_PASS);

  // wait for WiFi connection
  if((wifiMulti.run() == WL_CONNECTED)) {
    M5.Lcd.println("Success wifi connection");

    HTTPClient http;
    //HTTPS
    http.begin("http://www.tomorinao.space/");
    //http.begin("https://www.skyarch.net/blog/?feed=rss2", ca);

    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if(httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
       M5.Lcd.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if(httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        M5.Lcd.println(payload);
      }
    }
    else
    {
       M5.Lcd.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }
  // Wait
  delay(100000);
}

void loop() {
  M5.update();
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("Button A Status: ");
  M5.Lcd.println(M5.BtnA.isPressed());
  M5.Lcd.print("Button B Status: ");
  M5.Lcd.println(M5.BtnB.isPressed());
  M5.Lcd.print("Button C Status: ");
  M5.Lcd.println(M5.BtnC.isPressed());
  M5.Lcd.print("Touch Panel Status: ");
  M5.Lcd.println(M5.Touch.ispressed());     //include button A/B/C
}