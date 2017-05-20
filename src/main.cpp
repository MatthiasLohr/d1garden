
#include <Arduino.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include "settings.h"
#include "webserver.h"

int hlevel = 0;
int ptime = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  pinMode(PIN_SENSOR, INPUT);
  pinMode(PIN_PUMP, OUTPUT);
  Serial.println("Setting up WLAN...");
  WiFi.hostname("garden");
  WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
  webserver.on("/", webserverIndex);
  webserver.on("/style.css", webserverStyle);
  webserver.on("/update", webserverUpdate);
  webserver.begin();
}

void loop() {
  webserver.handleClient();
  int current_hlevel = analogRead(PIN_SENSOR);
  if (current_hlevel > hlevel) {
    digitalWrite(PIN_PUMP, HIGH);
    delay(ptime);
    digitalWrite(PIN_PUMP, LOW);
  }
  delay(100);
}
