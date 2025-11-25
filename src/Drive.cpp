#include "Drive.h"

Drive::Drive(int pot_pin, int low, int high, int pot_angle, PCA9685* pca_instance, int channel, int min_limit, int max_limit)
  : pot(pot_pin, low, high, pot_angle), servo(pca_instance, channel, min_limit, max_limit) {
}

void Drive::begin() {
  servo.begin();
}

void Drive::update() {
  int angle = pot.get_mapped_angle();

  Serial.print(" angle: ");
  Serial.println(angle);

  servo.write(angle);
}
