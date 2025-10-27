//
// Created by Bethl on 10/26/2025.
//

#ifndef ROBO_ARM_5000_INPUT_CONTROL_H
#define ROBO_ARM_5000_INPUT_CONTROL_H

#include <string>

using namespace std;

//the input control will be potentiometers that represent each servo
class Input_control {
private:
    string pot_joint;
    int pot_pin;
    int pot_angle;

public:
    // constructor that needs the potentiometer name and the signal pin it uses. the signal pin will give a value between 0
    // and 1024.

    Input_control();

    Input_control(string pot_joint, int pot_pin);


};


#endif //ROBO_ARM_5000_INPUT_CONTROL_H