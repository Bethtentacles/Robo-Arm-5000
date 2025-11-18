#ifndef ELECTROMAGNET_H
#define ELECTROMAGNET_H

#include <Arduino.h>

class ElectroMagnet {
  private:
    int pin;

  public:
    // control_pin: digital pin used to switch the electromagnet
    ElectroMagnet(int control_pin);

    void begin();
    void engage();    // turn magnet on
    void disengage(); // turn magnet off
    void update();
};

#endif
