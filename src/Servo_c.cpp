#include "Servo_c.h"

Servo_c::Servo_c(PCA9685* pca_instance, int ch, int s_min, int s_max)
  : pca(pca_instance), channel(ch), min_lim(s_min), max_lim(s_max), 
    current_angle(90), min_pwm(102), max_pwm(512) {
}

void Servo_c::begin() {
  // PCA9685 should already be initialized before servos are created
  // Set servo to center position (90 degrees)
  write(90);
}

void Servo_c::write(int angle) {
  if (pca == nullptr) return;
  
  // Constrain angle to limits
  angle = constrain(angle, min_lim, max_lim);
  current_angle = angle;
  
  // Map angle (0-180) to PWM value (min_pwm to max_pwm)
  // Standard servo: 0° = min_pwm, 90° = center, 180° = max_pwm
  uint16_t pwm = map(angle, 0, 180, min_pwm, max_pwm);
  
  // Write to PCA9685 channel
  pca->setChannelPWM(channel, pwm);
}

int Servo_c::getAngle() const {
  return current_angle;
}

int Servo_c::getChannel() const {
  return channel;
}

void Servo_c::setPWMRange(uint16_t min, uint16_t max) {
  min_pwm = min;
  max_pwm = max;
  // Re-write current angle with new PWM range
  write(current_angle);
}
