//
// Created by Bethl on 10/26/2025.
//

#ifndef ROBO_ARM_5000_SERVO_CONTROL_H
#define ROBO_ARM_5000_SERVO_CONTROL_H

#include <string>

using namespace std;

//This is the main servo control class, it uses servos (which have position control built in) to control the different
//joints of the robotic ar.
class Servo_control {
    private:
        string servo_joint;

        int servo_pin;
        int servo_angle;

        int max_limit;
        int min_limit;

    public:
//constructor, the servo needs a name for what joint it is, the signal pin
//and min/max limits so it doesn't destroy its self
    Servo_control();

    Servo_control(
        const string &servo_joint,
        int servo_pin,
        int max_limit,
        int min_limit);




};


#endif //ROBO_ARM_5000_SERVO_CONTROL_H