#include "ElectroMagnet.h"

ElectroMagnet::ElectroMagnet(int control_pin)
  : pin(control_pin) {
}

void ElectroMagnet::begin() {
  pinMode(pin, OUTPUT);
  // default off
  digitalWrite(pin, LOW);
}

void ElectroMagnet::engage() {
  digitalWrite(pin, HIGH);
}

void ElectroMagnet::disengage() {
  digitalWrite(pin, LOW);
}

void ElectroMagnet::update() {
  // no periodic tasks for a simple on/off magnet
}
