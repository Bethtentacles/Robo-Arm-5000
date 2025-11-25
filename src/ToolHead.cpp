#include "ToolHead.h"
#include "Grabber.h"
#include "ElectroMagnet.h"
#include "PCA9685.h"

ToolHead::ToolHead(Type t, PCA9685* pca_instance, int channel, int button_pin)
    : type(t), button_pin(button_pin), grabber(nullptr), magnet(nullptr) {
    switch (type) {
        case Type::Grabber:
            grabber = new Grabber(pca_instance, channel);
            break;
        case Type::ElectroMagnet:
            magnet = new ElectroMagnet(channel);
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
