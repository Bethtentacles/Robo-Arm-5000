//
// Created by Bethl on 10/26/2025.
//

#ifndef ROBO_ARM_5000_TOOL_HEAD_H
#define ROBO_ARM_5000_TOOL_HEAD_H

// The tool head is what tool is attached to the end of the arm. Different tools will have different functions.
class Tool_head {
    private:
    enum tool_type {
        grabber,
        magnet,
    };
    int tool_position{};
    bool tool_status{};
    bool tool_active{};

    public:
//the tool constructor needs to know what tool is at the end, if its activated and a signal to activate and
//deactivate it

    Tool_head();

    Tool_head(
        tool_type,
        int tool_position,
        int tool_status,
        bool tool_active) {
    }

    ~Tool_head();

};


#endif //ROBO_ARM_5000_TOOL_HEAD_H