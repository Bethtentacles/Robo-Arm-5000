#include "Pot.h"

Pot::Pot(int p_pin, int p_low, int p_high, int p_angle)
  : pot_pin(p_pin), low_offset(p_low), high_offset(p_high), angle_max(p_angle) {
  if (low_offset > high_offset) {
    int temp = low_offset;
    low_offset = high_offset;
    high_offset = temp;
  }
}

int Pot::get_mapped_angle() {
  if (low_offset == high_offset) return 0;
  int pot_value = analogRead(pot_pin);
  int angle = map(pot_value, low_offset, high_offset, 0, angle_max);
  angle = constrain(angle, 0, angle_max);
  return angle;
}

int Pot::get_max_angle() const {
  return angle_max;
}
