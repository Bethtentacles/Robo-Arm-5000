cmake_minimum_required(VERSION 4.0)
project(Robo_Arm_5000)

set(CMAKE_CXX_STANDARD 20)

add_executable(Robo_Arm_5000 src/main.cpp
        src/Servo_control.cpp
        src/Servo_control.h
        src/Tool_head.cpp
        src/Tool_head.h
        src/Kinematics.cpp
        src/Kinematics.h
        src/Input_control.cpp
        src/Input_control.h)
