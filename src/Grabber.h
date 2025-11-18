#ifndef GRABBER_H
#define GRABBER_H

#include "ToolHead.h"
#include "Servo_c.h"

class Grabber : public ToolHead {
  public:
    // servo_pin: the servo controlling the grabber
    // grabbed_angle: angle used to grab (default 90)
    // released_angle: angle used to release (default 180)
    Grabber(int servo_pin, int grabbed_angle = 90, int released_angle = 180);
    void begin() override;
    void engage() override;    // close/grab
    void disengage() override; // open/release
    void update() override;

  private:
    Servo_c servo;
    int grabbed_angle;
    int released_angle;
};

#endif
