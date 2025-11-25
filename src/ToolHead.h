
#ifndef TOOLHEAD_H
#define TOOLHEAD_H

#include <Arduino.h>

class Grabber;
class ElectroMagnet;
class PCA9685;

class ToolHead {
  public:
    enum class Type {
      ElectroMagnet,
      Grabber
    };

    ToolHead(Type t, PCA9685* pca_instance, int channel, int button_pin = -1);
    ~ToolHead();

    Type get_type() const { return type; }
    int get_button_pin() const { return button_pin; }

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
