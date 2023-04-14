// M5Core2, Bath Bot, display bath status and post to slack
//
// Ref1. https://raspberrypi.mongonta.com/howto-start-m5stack-core2arduinoide/
// Ref2. https://note.com/katsushun89/n/nd2cbcb9d88a3
// Ref3. https://github.com/m5stack/m5-docs/blob/master/docs/ja/api/button.md
// Ref4. https://www.skyarch.net/blog/?p=18253
// Ref5. https://qiita.com/minwinmin/items/55ba92edac3e1ec9f602
// Ref6. https://garretlab.web.fc2.com/arduino/esp32/examples/WiFiClientSecure/WiFiClientSecure.html
// Ref7. https://qiita.com/lumbermill/items/2517c5f130384cced335
// Ref8. https://wak-tech.com/archives/1770
// Ref9. https://wak-tech.com/archives/1906
// Ref10. https://qiita.com/hotchpotch/items/1cab19b6d464672e3a4d
// Ref11. https://software.small-desk.com/diy/2020/03/29/esp8266ota-platformio/
// Ref12. https://www.autumn-color.com/archives/839
// Ref13. https://www.1ft-seabass.jp/memo/2021/02/12/m5stack-basic-and-core2-default-fontsize-maybe-7px-knowledge/
// Ref14. http://moyane.blog25.fc2.com/blog-entry-684.html
// error: 'vector' in namespace 'std' does not name a template type -> add #include <vector>、./m5stack_operation_lamp/.pio/libdeps/m5stack-core-esp32/M5Core2/src/touch.h

#include <Arduino.h>
#include <M5Core2.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoOTA.h>
#include <time.h>

#include <wifi_pass_private.h>

#define JST 3600*9

bool bath_status = false;     // true: in_use, false: available

void post_to_slack(String message)
{
  WiFiClientSecure https;
  https.setCACert(ca);
  if((https.connect(hostname, 443)))
  {
    // HTTP header has been send and Server response header has been handled
    M5.Lcd.printf("[HTTPS] connection success\n");
    //String target_page = "/rss/topics/top-picks.xml";
    String str1 = String("POST https://") + String(hostname) + String(target_page) + " HTTP/1.1\r\n";
           str1 += "Host: " + String(hostname) + "\r\n";
           str1 += "User-Agent: BuildFailureDetectorESP32\r\n";
           str1 += "Content-Type: application/x-www-form-urlencoded\r\n";
           str1 += "Content-Length: "+ String(message.length()) +"\r\n\r\n";
           str1 += message + "\r\n\r\n";
           str1 += "Connection: close\r\n\r\n"; //closeを使うと、サーバーの応答後に切断される。最後に空行必要
           str1 += "\0";
    https.print(str1); //client.println にしないこと。最後に改行コードをプラスして送ってしまう為
    https.flush(); //client出力が終わるまで待つ
    
    delay(100);

    /*
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
    */

    https.stop();
  }
  else
  {
    M5.Lcd.printf("[HTTPS] connection failed\n");
  }
}

void setup() {
  M5.begin(true, false, false, false);
  M5.Lcd.setTextSize(2);

  Serial.begin(115200);
  Serial.print("Bath Bot ");
  Serial.println(BATH_BOT_VERSION);

  M5.Lcd.print("Bath Bot ");
  M5.Lcd.println(BATH_BOT_VERSION);

  // WifiSetup
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  // wait for WiFi connection
  //while (WiFi.status() != WL_CONNECTED) {
  //  Serial.print(".");
  //  delay(500);
  //}
  
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  ArduinoOTA.setHostname("bathbot");

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.begin();

  M5.Lcd.println("Success wifi connection");
  M5.Lcd.print("Connected to ");
  M5.Lcd.println(WIFI_SSID);
  M5.Lcd.println(WiFi.localIP());

  configTime( JST, 0, "ntp.nict.jp", "ntp.jst.mfeed.ad.jp");

  post_to_slack(message_wakeup);
  //String message_ipaddress = "payload={\"channel\": \"C021B98R75E\", \"username\": \"Bath Bot\", \"text\": \"Wakeup Bath Bot. IPaddress: " + String(WiFi.localIP()) + "\"}";
  //String message_ipaddress = "payload={\"channel\": \"#misc_geekhouse_bijogi_bath\", \"username\": \"Bath Bot\", \"text\": \"Wakeup Bath Bot. IPaddress: " + String(WiFi.localIP()) + "\"}";
  //post_to_slack(message_ipaddress);

  // Wait
  delay(5000);
  // initialize
  bath_status = false;
  M5.Lcd.clear(GREEN);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println("Bath is available");
  Serial.println("Bath is available");
  M5.Lcd.setCursor(0, 195);
  post_to_slack(message_available);
  M5.Lcd.print("IP address: ");
  M5.Lcd.println(WiFi.localIP());
}

unsigned long previous_millis = 0;

void loop() {
  time_t t;
  struct tm *tm;
  static const char *wd[7] = {"Sun","Mon","Tue","Wed","Thr","Fri","Sat"};
  unsigned long current_millis;
  unsigned long dif_millis;

  ArduinoOTA.handle();
  M5.update();
  M5.Lcd.setCursor(0, 0);

  t = time(NULL);
  tm = localtime(&t);

  current_millis = millis();
  if (current_millis > previous_millis)
  {
    dif_millis = current_millis - previous_millis;
  }
  else
  {
    unsigned long max_unsigned_long = 0UL - 1UL;
    dif_millis = current_millis + max_unsigned_long - previous_millis;
  }
  if (dif_millis > 1000)
  {
    M5.Lcd.setCursor(0, 226);
    M5.Lcd.printf(" %04d/%02d/%02d(%s) %02d:%02d:%02d\n",
          tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
          wd[tm->tm_wday],
          tm->tm_hour, tm->tm_min, tm->tm_sec);
    M5.Lcd.setCursor(0, 0);
    previous_millis = current_millis;
  }
  
  if(M5.Touch.ispressed())
  {
    if(bath_status == false)      // change state of bath in use
    {
      bath_status = true;
      M5.Lcd.clear(RED);
      M5.Lcd.println("Bath in use");
      Serial.println("Bath in use");
      M5.Lcd.setCursor(0, 195);
      post_to_slack(message_in_use);
      M5.Lcd.print("IP address: ");
      M5.Lcd.println(WiFi.localIP());
    }
    else      // change state of bath is avalilable
    {
      bath_status = false;
      M5.Lcd.clear(GREEN);
      M5.Lcd.println("Bath is available");
      Serial.println("Bath is available");
      M5.Lcd.setCursor(0, 195);
      post_to_slack(message_available);
      M5.Lcd.print("IP address: ");
      M5.Lcd.println(WiFi.localIP());
    }
  }
}