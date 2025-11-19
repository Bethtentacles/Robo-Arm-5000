#include "Grabber.h"

// Default angles: grabbed = 90, released = 180
Grabber::Grabber(int servo_pin)
  : servo(servo_pin, 0, 180), grabbed_angle(90), released_angle(180) {
}


// default to released 
void Grabber::begin() {
  servo.begin();
  servo.write(released_angle);
}

void Grabber::engage() {
  servo.write(grabbed_angle);
}

void Grabber::disengage() {
  servo.write(released_angle);
}

void Grabber::update() {
}
