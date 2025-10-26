//
// Created by Bethl on 10/26/2025.
//

#ifndef ROBO_ARM_5000_TOOL_HEAD_H
#define ROBO_ARM_5000_TOOL_HEAD_H


class Tool_head {
    private:
    enum tool_type {
        grabber,
        magnet,
    };
    int tool_position{};
    int tool_status{};
    bool tool_active{};

    public:

    Tool_head();

    Tool_head(tool_type, int tool_position, int tool_status, bool tool_active) {
    }

    //getter
    int get_tool_position();
    int get_tool_active();

    //setter
    int set_tool_status(int tool_status = 0);
};


#endif //ROBO_ARM_5000_TOOL_HEAD_H