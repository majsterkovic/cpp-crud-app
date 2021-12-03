//
// Created by majsterkovic on 29.11.2021.
//

#ifndef PROJEKT_BASE_H
#define PROJEKT_BASE_H

#include "Device.h"
#include "Device.h"
#include <map>
#include <vector>
#include <string>
#include <algorithm>

class Base
{
private:
    std::map<int, Device*> devices;
    std::vector<int> notebooks;
    std::vector<int> smartbands;

    int ask_for_type();
    int ask_for_id();


public:
    void add_device();
    void remove_device();
    std::map<int, Device*> get_devices();

    int get_amount_of_device(std::string manufacturer);
    int get_amount_of_device(std::string manufacturer, std::string model);

    void show_all_devices();
    void show_devices_by_type();
    void show_devices_by_type_and_price_range();
    void custom_search();
    void compare_notebooks();
    void update_price();

};


#endif //PROJEKT_BASE_H
