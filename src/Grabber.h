#ifndef GRABBER_H
#define GRABBER_H

#include "Servo_c.h"

class Grabber {
  private:
    Servo_c servo;
    const int grabbed_angle;
    const int released_angle;
    bool engaged_state = false;

  public:
    // servo pin the servo controlling the grabber
    Grabber(int servo_pin);

    void begin();
    void engage();    // close/grab (keeps compatibility)
    void disengage(); // open/release (keeps compatibility)
    void update();

    // New API: set/get engaged state in one call. When `on` is true the
    // servo moves to `grabbed_angle`, when false it moves to `released_angle`.
    void engage_grabber(bool on);
    bool is_engaged() const { return engaged_state; }
};

#endif
