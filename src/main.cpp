#include <Arduino.h>
#include "Drive.h"

// Drive instance: (pot pin, low offset, high offset, pot angle (=max servo angle), servo pin, min limit, max limit)
Drive base_rotation(A1, 0, 1023, 180, 6, 0, 180);

void setup() {
  Serial.begin(115200);
  // give Serial a short time to initialize on USB boards
  delay(10);
  base_rotation.begin();
}

void loop() {
  base_rotation.update();
  delay(50);
}
