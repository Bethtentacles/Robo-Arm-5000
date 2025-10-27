//
// Created by Bethl on 10/26/2025.
//

#include "Servo_control.h"
#include <string>

using namespace std;
//set default values for servos to prevent damage to robot and area around it
Servo_control::Servo_control():
    servo_joint ("default"),
    servo_pin (-1),
    max_limit (10),
    min_limit (0) {


}