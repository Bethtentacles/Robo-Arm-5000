#ifndef ELECTROMAGNET_H
#define ELECTROMAGNET_H

#include "ToolHead.h"
#include <Arduino.h>

class ElectroMagnet : public ToolHead {
  public:
    // control_pin: digital pin used to switch the electromagnet
    ElectroMagnet(int control_pin);
    void begin() override;
    void engage() override;    // turn magnet on
    void disengage() override; // turn magnet off
    void update() override;

  private:
    int pin;
};

#endif
