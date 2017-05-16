
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "settings.h"
#include "webserver.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  pinMode(PIN_SENSOR, INPUT);
  pinMode(PIN_PUMP, OUTPUT);
  Serial.println("Setting up WLAN...");
  WiFi.hostname("garden");
  WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
  webserver.on("/", webserverIndex);
  webserver.begin();
}

void loop() {
  webserver.handleClient();
  delay(10);
}
