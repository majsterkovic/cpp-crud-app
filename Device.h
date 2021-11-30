//
// Created by majsterkovic on 29.11.2021.
//

#ifndef PROJEKT_DEVICE_H
#define PROJEKT_DEVICE_H

#include <string>
#include <iostream>

class Device {

private:
    double price;

public:
    std::string manufacturer;
    std::string model;
    void update_price(double new_price);
    virtual void show_info();
    double get_price() const;

    Device(std::string manufacturer, std::string model, double price);
    virtual ~Device();


};


#endif //PROJEKT_DEVICE_H
