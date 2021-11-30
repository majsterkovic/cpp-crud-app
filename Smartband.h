//
// Created by majsterkovic on 29.11.2021.
//

#ifndef PROJEKT_SMARTBAND_H
#define PROJEKT_SMARTBAND_H

#include "Device.h"

class Smartband : public virtual Device {
private:
    int strip_length;
    bool NFC;

public:
    void show_info();
    bool mobile_payments() const;

    Smartband(std::string manufacturer, std::string model, double price, int strip_length, bool NFC);
    ~Smartband();
};


#endif //PROJEKT_SMARTBAND_H
