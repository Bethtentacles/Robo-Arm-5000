#ifndef DRIVE_H
#define DRIVE_H

#include <Arduino.h>
#include "Pot.h"
#include "Servo_c.h"

class Drive {
  public:
    Drive(int pot_pin, int low, int high, int pot_angle, int servo_pin, int minL, int maxL);
    void begin();
    void update();

  private:
    Pot pot;
    Servo_c servo;
};

#endif
