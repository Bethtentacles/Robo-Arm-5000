#include "Servo_c.h"

Servo_c::Servo_c(int s_pin, int s_min, int s_max)
  : servo_pin(s_pin), min_lim(s_min), max_lim(s_max) {
}

void Servo_c::begin() {
  if (servo_pin >= 0) servo.attach(servo_pin);
}

void Servo_c::write(int angle) {
  angle = constrain(angle, min_lim, max_lim);
  servo.write(angle);
}

int Servo_c::get_servo_pin() const {
  return servo_pin;
}
