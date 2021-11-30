//
// Created by majsterkovic on 29.11.2021.
//

#include "Device.h"

Device::Device(std::string manufacturer, std::string model, double price) : manufacturer(manufacturer), model(model), price(price) {}

void Device::update_price(double new_price) {
    price = new_price;
}

double Device::get_price() const {
    return price;
}

void Device::show_info() {
    std::cout << "Manufacturer: " << manufacturer << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Price: " << price << std::endl;
}

Device::~Device() {
    std::cout << "Device deleted" << std::endl;
}


