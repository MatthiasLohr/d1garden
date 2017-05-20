
#include <Arduino.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include "functions.h"
#include "settings.h"
#include "webserver.h"

int hlevel = 0;
int ptime = 0;

int loop_cycles = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  pinMode(PIN_SENSOR, INPUT);
  pinMode(PIN_SENSOR_POWER, OUTPUT);
  digitalWrite(PIN_SENSOR_POWER, LOW);
  pinMode(PIN_PUMP, OUTPUT);
  Serial.println("Setting up WLAN...");
  WiFi.hostname("garden");
  WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
  webserver.on("/", webserverIndex);
  webserver.on("/style.css", webserverStyle);
  webserver.on("/update", webserverUpdate);
  webserver.begin();
  EEPROM.begin(512);
  EEPROM.get(0, hlevel);
  EEPROM.get(4, ptime);
}

void loop() {
  webserver.handleClient();
  // only measure humidity every 5 minutes
  if (loop_cycles > 3000) {
    int current_hlevel = poweredAnalogRead(PIN_SENSOR_POWER, PIN_SENSOR);
    if (current_hlevel > hlevel) {
      digitalWrite(PIN_PUMP, HIGH);
      delay(ptime);
      digitalWrite(PIN_PUMP, LOW);
    }
    loop_cycles = 0;
  }

  loop_cycles++;
  delay(100);
}
