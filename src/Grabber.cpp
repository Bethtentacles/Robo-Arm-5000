#include "Grabber.h"

// Default angles: grabbed = 90, released = 180
Grabber::Grabber(int servo_pin)
  : servo(servo_pin, 0, 180), grabbed_angle(90), released_angle(180) {
}

void Grabber::begin() {
  servo.begin();
  // default to released state
  servo.write(released_angle);
}

void Grabber::engage() {
  // move to grabbed angle
  servo.write(grabbed_angle);
}

void Grabber::disengage() {
  // move to released angle
  servo.write(released_angle);
}

void Grabber::update() {
  // No periodic work required for simple servo control
}
