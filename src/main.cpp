// Ref1. https://raspberrypi.mongonta.com/howto-start-m5stack-core2arduinoide/
// Ref2. https://note.com/katsushun89/n/nd2cbcb9d88a3
// Ref3. https://github.com/m5stack/m5-docs/blob/master/docs/ja/api/button.md
// Ref4. https://www.skyarch.net/blog/?p=18253
// Ref5. https://qiita.com/minwinmin/items/55ba92edac3e1ec9f602
// Ref6. https://garretlab.web.fc2.com/arduino/esp32/examples/WiFiClientSecure/WiFiClientSecure.html

#include <Arduino.h>
#include <M5Core2.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>

#include <wifi_pass.h>
//extern const char* ca;

const char* ca = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIDdzCCAl+gAwIBAgIBADANBgkqhkiG9w0BAQsFADBdMQswCQYDVQQGEwJKUDEl\n" \
"MCMGA1UEChMcU0VDT00gVHJ1c3QgU3lzdGVtcyBDTy4sTFRELjEnMCUGA1UECxMe\n" \
"U2VjdXJpdHkgQ29tbXVuaWNhdGlvbiBSb290Q0EyMB4XDTA5MDUyOTA1MDAzOVoX\n" \
"DTI5MDUyOTA1MDAzOVowXTELMAkGA1UEBhMCSlAxJTAjBgNVBAoTHFNFQ09NIFRy\n" \
"dXN0IFN5c3RlbXMgQ08uLExURC4xJzAlBgNVBAsTHlNlY3VyaXR5IENvbW11bmlj\n" \
"YXRpb24gUm9vdENBMjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBANAV\n" \
"OVKxUrO6xVmCxF1SrjpDZYBLx/KWvNs2l9amZIyoXvDjChz335c9S672XewhtUGr\n" \
"zbl+dp+++T42NKA7wfYxEUV0kz1XgMX5iZnK5atq1LXaQZAQwdbWQonCv/Q4EpVM\n" \
"VAX3NuRFg3sUZdbcDE3R3n4MqzvEFb46VqZab3ZpUql6ucjrappdUtAtCms1FgkQ\n" \
"hNBqyjoGADdH5H5XTz+L62e4iKrFvlNVspHEfbmwhRkGeC7bYRr6hfVKkaHnFtWO\n" \
"ojnflLhwHyg/i/xAXmODPIMqGplrz95Zajv8bxbXH/1KEOtOghY6rCcMU/Gt1SSw\n" \
"awNQwS08Ft1ENCcadfsCAwEAAaNCMEAwHQYDVR0OBBYEFAqFqXdlBZh8QIH4D5cs\n" \
"OPEK7DzPMA4GA1UdDwEB/wQEAwIBBjAPBgNVHRMBAf8EBTADAQH/MA0GCSqGSIb3\n" \
"DQEBCwUAA4IBAQBMOqNErLlFsceTfsgLCkLfZOoc7llsCLqJX2rKSpWeeo8HxdpF\n" \
"coJxDjrSzG+ntKEju/Ykn8sX/oymzsLS28yN/HH8AynBbF0zX2S2ZTuJbxh2ePXc\n" \
"okgfGT+Ok+vx+hfuzU7jBBJV1uXk3fs+BXziHV7Gp7yXT2g69ekuCkO2r1dcYmh8\n" \
"t/2jioSgrGK+KwmHNPBqAbubKVY8/gA3zyNs8U6qtnRGEmyR7jTV7JqR50S+kDFy\n" \
"1UkC9gLl9B/rfNmWVan/7Ir5mUf/NVoCqgTLiluHcSmRvaS0eg29mvVXIwAHIRc/\n" \
"SjnRBUkLp7Y3gaVdjKozXoEofKd9J+sAro03\n" \
"-----END CERTIFICATE-----\n";

void setup() {
  M5.begin(true, false, false, false);
  M5.Lcd.setTextSize(2);
  //M5.Lcd.print("Hello World!!");

  // WifiSetup
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  // wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  M5.Lcd.println("Success wifi connection");
  M5.Lcd.print("Connected to ");
  M5.Lcd.println(WIFI_SSID);
  M5.Lcd.println(WiFi.localIP());

  WiFiClientSecure https;
  https.setCACert(ca);
  //int https_connection_check = https.connect("news.yahoo.co.jp", 443);
  //if(https_connection_check > 0)
  if((https.connect("news.yahoo.co.jp", 443)))
  {
    // HTTP header has been send and Server response header has been handled
    M5.Lcd.printf("[HTTPS] connection success\n");
    String target_page = "/rss/topics/top-picks.xml";
    String str1 = String("GET https://") + String("news.yahoo.co.jp") + target_page + " HTTP/1.1\r\n";
           str1 += "Host: " + String("news.yahoo.co.jp") + "\r\n";
           str1 += "User-Agent: BuildFailureDetectorESP32\r\n";
           str1 += "Connection: close\r\n\r\n"; //closeを使うと、サーバーの応答後に切断される。最後に空行必要
           str1 += "\0";
    https.print(str1); //client.println にしないこと。最後に改行コードをプラスして送ってしまう為
    https.flush(); //client出力が終わるまで待つ
    
    delay(100);

    while (https.connected()) {
      String line = https.readStringUntil('\n');
      if (line == "\r") {
        //Serial.println("headers received");
        M5.Lcd.println("headers received");
        break;
      }
    }
    // if there are incoming bytes available
    // from the server, read them and print them:
    while (https.available()) {
      char c = https.read();
      //Serial.write(c);
      M5.Lcd.print(c);
    }
    https.stop();
  }
  else
  {
    M5.Lcd.printf("[HTTPS] connection failed\n");
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