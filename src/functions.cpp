
#include "functions.h"

int poweredAnalogRead(int pin_power, int pin_value) {
  digitalWrite(pin_power, HIGH);
  delay(5); // wait to become the sensor fully powered
  int result = analogRead(pin_value);
  digitalWrite(pin_power, LOW);
  return result;
}
