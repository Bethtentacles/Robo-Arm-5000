#ifndef TOOLHEAD_H
#define TOOLHEAD_H

#include <Arduino.h>

class ToolHead {
  public:
    enum class Type {
      ElectroMagnet,
      Grabber
    };

    ToolHead(Type t) : type(t) {}
    virtual ~ToolHead() {}

    Type getType() const { return type; }

    // lifecycle
    virtual void begin() = 0;
    // engage the tool (grab or turn on magnet)
    virtual void engage() = 0;
    // disengage the tool (release or turn off magnet)
    virtual void disengage() = 0;
    // optional periodic update
    virtual void update() {}

  private:
    Type type;
};

#endif
