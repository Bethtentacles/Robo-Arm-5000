#include "Grabber.h"

Grabber::Grabber(PCA9685* pca_instance, int channel, int grabbed_ang, int released_ang)
  : servo(pca_instance, channel, 0, 180), grabbed_angle(grabbed_ang), released_angle(released_ang) {
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
