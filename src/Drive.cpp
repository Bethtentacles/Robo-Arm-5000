#include "Drive.h"

Drive::Drive(int pot_pin, int low, int high, int pot_angle, int servo_pin, int minL, int maxL)
  : pot(pot_pin, low, high, pot_angle), servo(servo_pin, minL, maxL) {
}

void Drive::begin() {
  servo.begin();
}

void Drive::update() {
  int angle = pot.get_mapped_angle();

  Serial.print(" angle: ");
  Serial.println(angle);

  // drive the servo to the mapped angle
  servo.write(angle);
}
