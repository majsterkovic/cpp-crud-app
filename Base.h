//
// Created by majsterkovic on 29.11.2021.
//

#ifndef PROJEKT_BASE_H
#define PROJEKT_BASE_H

#include "Device.h"
#include "Device.h"
#include <map>
#include <vector>

class Base
{
private:
    std::map<int, Device*> devices;
    std::vector<int> notebooks;
    std::vector<int> smartbands;


public:
    void add_device();
    void remove_device();
    std::map<int, Device*> get_devices();

    int get_amount_of_device(std::string manufacturer);
    int get_amount_of_device(std::string manufacturer, std::string model);

    void show_all_devices();
    void show_devices_by_type();
    void show_devices_by_type_and_price_range();
    void show_devices_by_type_and_brand();
    void custom_search();
    void compare_notebooks();
    void update_price();


};


#endif //PROJEKT_BASE_H
