
#include "functions.h"

int poweredAnalogRead(int pin_power, int pin_value) {
  digitalWrite(pin_power, HIGH);
  delay(50);
  int result = analogRead(pin_value);
  digitalWrite(pin_power, LOW);
  return result;
}
