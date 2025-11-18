#ifndef POT_H
#define POT_H

#include <Arduino.h>

class Pot {
  private:
    int pot_pin;
    int low_offset;
    int high_offset;
    int angle_max;

  public:
    Pot(int p_pin = A0, int p_low = 0, int p_high = 1023, int p_angle = 180);
    int get_mapped_angle();
    int get_max_angle() const;
};

#endif
