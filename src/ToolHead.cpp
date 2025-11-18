#include "ToolHead.h"
#include "Grabber.h"
#include "ElectroMagnet.h"

ToolHead::ToolHead(Type t, int pin, int button_pin)
    : type(t), button_pin(button_pin), grabber(nullptr), magnet(nullptr) {
    switch (type) {
        case Type::Grabber:
            grabber = new Grabber(pin);
            break;
        case Type::ElectroMagnet:
            magnet = new ElectroMagnet(pin);
            break;
    }
}

ToolHead::~ToolHead() {
    if (grabber) delete grabber;
    if (magnet) delete magnet;
}

void ToolHead::begin() {
    if (grabber) grabber->begin();
    if (magnet) magnet->begin();
}

void ToolHead::engage() {
    if (grabber) grabber->engage();
    if (magnet) magnet->engage();
}

void ToolHead::disengage() {
    if (grabber) grabber->disengage();
    if (magnet) magnet->disengage();
}

void ToolHead::update() {
    if (grabber) grabber->update();
    if (magnet) magnet->update();
}
