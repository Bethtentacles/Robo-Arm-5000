#ifndef DRIVE_H
#define DRIVE_H

#include <Arduino.h>
#include "Pot.h"
#include "Servo_c.h"
#include "PCA9685.h"

class Drive {
  public:
    Pot pot;
    Servo_c servo;
    
    Drive(int pot_pin, int low, int high, int pot_angle, PCA9685* pca_instance, int channel, int min_limit = 0, int max_limit = 180);
    
  
    void begin();
    void update();
};

#endif
