#include "Grabber.h"

Grabber::Grabber(int servo_pin, int grabbed_angle_, int released_angle_)
  : ToolHead(Type::Grabber), servo(servo_pin, 0, 180), grabbed_angle(grabbed_angle_), released_angle(released_angle_) {
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
