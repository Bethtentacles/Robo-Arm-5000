#ifndef SERVO_C_H
#define SERVO_C_H

#include <Servo.h>
#include <Arduino.h>

class Servo_c {
  private:
    int servo_pin;
    Servo servo;
    int min_lim;
    int max_lim;

  public:
    Servo_c(int s_pin = -1, int s_min = 0, int s_max = 180);
    void begin();
    void write(int angle);
    int get_servo_pin() const;
};

#endif
