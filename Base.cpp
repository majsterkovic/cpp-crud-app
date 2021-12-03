//
// Created by majsterkovic on 29.11.2021.
//

#include "Base.h"
#include "Notebook.h"
#include "Smartband.h"

int Base::ask_for_type()
{
    int type;
    std::cout << "Choose type of device: " << std::endl;
    std::cout << "1. Notebook" << std::endl;
    std::cout << "2. Smartband" << std::endl;
    std::cin >> type;
    return type;
}

int Base::ask_for_id()
{
    int id;
    std::cout << "Enter device id: " << std::endl;
    std::cin >> id;
    return id;
}


void Base::add_device()
{
    int type = ask_for_type();

    std::string manufacturer;
    std::string model;
    int id;
    double price;

    bool flag;
    do {
        flag = false;
        id = ask_for_id();

        if (devices.find(id) != devices.end())
        {
            std::cout << "Device with this id already exists.\n";
            flag = true;
        }
    }while(flag);

    switch(type) {
        case 1: {

            std::cout << "Enter notebook manufacturer: ";
            std::cin >> manufacturer;
            std::cout << "Enter notebook model: ";
            std::cin >> model;
            std::cout << "Enter notebook price: ";
            std::cin >> price;
            std::cout << "Enter notebook RAM: ";
            int ram;
            std::cin >> ram;
            std::cout << "Enter notebook storage: ";
            int disk;
            std::cin >> disk;
            devices[id] = new Notebook(manufacturer, model, price, ram, disk);
            notebooks.push_back(id);
            break;
        }
        case 2: {
            std::cout << "Enter smartband manufacturer: ";
            std::cin >> manufacturer;
            std::cout << "Enter smartband model: ";
            std::cin >> model;
            std::cout << "Enter smartband price: ";
            std::cin >> price;
            std::cout << "Enter smartband strip length: ";
            int length;
            std::cin >> length;
            std::cout << "Enter if the smartband has NFC: ";
            bool nfc;
            std::cin >> nfc;
            devices[id] = new Smartband(manufacturer, model, price, length, nfc);
            smartbands.push_back(id);
            break;
        }
        default:
            std::cout << "Wrong input!\n";
            break;
    }

}

std::map<int, Device*> Base::get_devices() {
    return devices;
}

int Base::get_amount_of_device(std::string manufacturer)
{
    return std::count_if(devices.begin(), devices.end(), [manufacturer] (auto D) { return D.second->manufacturer == manufacturer; });
}

int Base::get_amount_of_device(std::string manufacturer, std::string model) {
    return std::count_if(devices.begin(), devices.end(), [manufacturer, model] (auto D) { return (D.second->manufacturer == manufacturer) && (D.second->model == model); });
}


void Base::remove_device()
{
    int id = ask_for_id();

    if (devices.find(id) != devices.end())
    {
        Device* d = devices[id];
        devices.erase(id);
        delete d;

        if (std::find(notebooks.begin(), notebooks.end(), id) != notebooks.end())
        {
            notebooks.erase(std::remove(notebooks.begin(), notebooks.end(), id), notebooks.end());
        }
        else if (std::find(smartbands.begin(), smartbands.end(), id) != smartbands.end())
        {
            smartbands.erase(std::remove(smartbands.begin(), smartbands.end(), id), smartbands.end());
        }
    }

    else
    {
        std::cout << "Device with this id doesn't exist.\n";
    }
}


void Base::show_all_devices() {
    for (auto d : devices)
    {
        d.second->show_info();
    }
}

void Base::show_devices_by_type() {
    std::cout << "What type of device do you want to show?\n";
    int type = ask_for_type();

    auto& subcontainer = type == 1 ? notebooks : smartbands;

    for (auto id : subcontainer)
    {
        devices[id]->show_info();
    }

}

void Base::show_devices_by_type_and_price_range() {
    std::cout << "What type of device do you want to show?\n";
    int type = ask_for_type();
    std::cout << "Enter price range: ";
    int min, max;
    std::cin >> min >> max;

    auto& subcontainer = type == 1 ? notebooks : smartbands;

    for(auto id : subcontainer)
    {
        if (devices[id]->get_price() >= min && devices[id]->get_price() <= max)
        {
            devices[id]->show_info();
        }
    }
}

void Base::update_price() {
    int id = ask_for_id();
    if (devices.find(id) != devices.end())
    {
        std::cout << "Enter new price: ";
        int price;
        std::cin >> price;
        devices[id]->update_price(price);
    }
    else
    {
        std::cout << "Device with this id doesn't exist.\n";
    }
}

void Base::compare_notebooks() {
    std::cout << "Enter first device id: ";
    int id1;
    std::cin >> id1;
    std::cout << "Enter second device id: ";
    int id2;
    std::cin >> id2;
    if ((std::find(notebooks.begin(), notebooks.end(), id1) != notebooks.end()) && (std::find(notebooks.begin(), notebooks.end(), id2) != notebooks.end()))
    {
        Notebook n1 = dynamic_cast<Notebook&>(*devices[id1]);
        Notebook n2 = dynamic_cast<Notebook&>(*devices[id2]);
        if (n1 < n2)
        {
            std::cout << "First device is slower.\n";
        }
        else
        {
            std::cout << "Devices are equal.\n";
        }
    }
    else
    {
        std::cout << "Device with this id doesn't exist.\n";
    }
}

void Base::custom_search() {
    std::cout << "Enter manufacturer: ";
    std::string manufacturer;
    std::cin >> manufacturer;
    std::cout << "Enter model: ";
    std::string model;
    std::cin >> model;

    for(auto device : devices)
    {
        if ((device.second->manufacturer == manufacturer) && (device.second->model == model))
        {
            std::cout << "Device with this id: " << device.first << "\n";
            device.second->show_info();
        }
    }

}
