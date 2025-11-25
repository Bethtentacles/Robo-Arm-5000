#ifndef SERVO_C_H
#define SERVO_C_H

#include <Arduino.h>
#include "PCA9685.h"

class Servo_c {
  private:
    PCA9685* pca;         
    int channel;            
    int min_lim;           
    int max_lim;            
    int current_angle;     
    uint16_t min_pwm;       
    uint16_t max_pwm;       

  public:
    // Constructor: takes PCA9685 instance pointer and channel number
    Servo_c(PCA9685* pca_instance = nullptr, int ch = 0, int s_min = 0, int s_max = 180);
    
    void begin();
    void write(int angle);
    int getAngle() const;
    int getChannel() const;
    
    // Set custom PWM range for servo calibration
    void setPWMRange(uint16_t min, uint16_t max);
};

#endif
