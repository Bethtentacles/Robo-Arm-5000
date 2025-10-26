//
// Created by Bethl on 10/26/2025.
//

#ifndef ROBO_ARM_5000_SERVO_CONTROL_H
#define ROBO_ARM_5000_SERVO_CONTROL_H

#include <string>

using namespace std;


class Servo_control {
    private:
        string servo_joint;

        int servo_pin;
        int potentiometer_pin;

        int servo_angle;
        int potentiometer_angle;


        int servo_max;
        int servo_min;

    public:

    Servo_control();

    Servo_control(const string& servo_joint, int servo_pin, int potentiometer_pin, int servo_max, int servo_min);

    //getter

    string get_servo_joint;
    int get_servo_angle();
    int get_potentiometer_angle() const;

    //setter
    void set_servo_angle(int new_servo_angle);




};


#endif //ROBO_ARM_5000_SERVO_CONTROL_H