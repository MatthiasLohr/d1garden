
#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  pinMode(D1, OUTPUT);
}

void loop() {
  Serial.println(analogRead(A0));
  delay(500);
}
