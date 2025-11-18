
#ifndef TOOLHEAD_H
#define TOOLHEAD_H

#include <Arduino.h>

class Grabber;
class ElectroMagnet;

class ToolHead {
  public:
    enum class Type {
      ElectroMagnet,
      Grabber
    };

    ToolHead(Type t, int pin, int button_pin = -1);
    ~ToolHead();

    Type getType() const { return type; }
    int getButtonPin() const { return button_pin; }

    void begin();
    void engage();
    void disengage();
    void update();

  private:
    Type type;
    int button_pin;
    Grabber* grabber;
    ElectroMagnet* magnet;
};

#endif
