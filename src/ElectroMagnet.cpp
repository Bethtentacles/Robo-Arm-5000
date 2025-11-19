#include "ElectroMagnet.h"

ElectroMagnet::ElectroMagnet(int control_pin)
  : pin(control_pin) {
}


  // default off need timer or magnet will burn out
void ElectroMagnet::begin() {
  pinMode(pin, OUTPUT);
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
