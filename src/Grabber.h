#ifndef GRABBER_H
#define GRABBER_H

#include "Servo_c.h"
#include "PCA9685.h"

class Grabber {
  private:
    Servo_c servo;
    const int grabbed_angle;
    const int released_angle;
    bool engaged_state = false;

  public:
    Grabber(PCA9685* pca_instance, int channel, int grabbed_ang = 90, int released_ang = 180);

    void begin();

    // Old API keep for compatibility
    void engage();   
    void disengage(); 


    // New API: set/get engaged state in one call. When `on` is true the
    // servo moves to `grabbed_angle`, when false it moves to `released_angle`.
    void engage_grabber(bool on);
    bool is_engaged() const { return engaged_state; }

        
    void update();
};

#endif
