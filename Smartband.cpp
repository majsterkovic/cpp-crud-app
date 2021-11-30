//
// Created by majsterkovic on 29.11.2021.
//

#include "Smartband.h"

Smartband::Smartband(std::string manufacturer, std::string model, double price, int strip_length, bool NFC) : Device(manufacturer, model, price), strip_length(strip_length), NFC(NFC) {}

void Smartband::show_info() {
    Device::show_info();
    std::cout << "Strip length: " << strip_length << " mm" << std::endl;
    std::cout << "NFC: " << (NFC ? "Yes" : "No") << std::endl;
}

Smartband::~Smartband() {
    Device::~Device();
}

bool Smartband::mobile_payments() const {
    return NFC;
}
