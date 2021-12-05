//
// Created by majsterkovic on 29.11.2021.
//

#include "Base.h"
#include "Notebook.h"
#include "Smartband.h"

int Base::ask_for_type()
{
    std::cout << "\n";
    int type;
    std::cout << "Choose type of device: " << std::endl;
    std::cout << "1. Notebook" << std::endl;
    std::cout << "2. Smartband" << std::endl;
    std::cin >> type;

    while(std::cin.fail() || type < 1 || type > 2)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again: " << std::endl;
        std::cin >> type;
    }

    return type;
}

int Base::ask_for_id()
{
    std::cout << "\n";
    int id;
    std::cout << "Enter device id (must be a unique number): " << std::endl;
    std::cin >> id;

    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter device id (must be a unique number): " << std::endl;
        std::cin >> id;
    }

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
        std::cin.clear();
        fflush(stdin);
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
            std::cout << "Enter notebook price ($): ";
            std::cin >> price;
            std::cout << "Enter notebook RAM (GB): ";
            int ram;
            std::cin >> ram;
            std::cout << "Enter notebook storage (GB): ";
            int disk;
            std::cin >> disk;
            devices[id] = new Notebook(manufacturer, model, price, ram, disk);
            notebooks_ids.push_back(id);
            break;
        }
        case 2: {
            std::cout << "Enter smartband manufacturer: ";
            std::cin >> manufacturer;
            std::cout << "Enter smartband model: ";
            std::cin >> model;
            std::cout << "Enter smartband price ($): ";
            std::cin >> price;
            std::cout << "Enter smartband strip length (mm): ";
            int length;
            std::cin >> length;
            std::cout << "Enter 1 if the smartband has NFC: ";
            int nfc;
            std::cin >> nfc;
            devices[id] = new Smartband(manufacturer, model, price, length, (bool)nfc);
            smartbands_ids.push_back(id);
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

int Base::get_amount_of_device(std::string manufacturer) const
{
    return std::count_if(devices.begin(), devices.end(), [manufacturer] (auto D) { return D.second->manufacturer == manufacturer; });
}

int Base::get_amount_of_device(std::string manufacturer, std::string model) const
{
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

        if (auto it = std::find(notebooks_ids.begin(), notebooks_ids.end(), id); it != notebooks_ids.end())
        {
            notebooks_ids.erase(it);
        }
        else if (auto it = std::find(smartbands_ids.begin(), smartbands_ids.end(), id); it != smartbands_ids.end())
        {
            smartbands_ids.erase(it);
        }
    }

    else
    {
        std::cout << "Device with this id doesn't exist.\n";
    }
}


void Base::show_all_devices() {
    if( (notebooks_ids.size() + smartbands_ids.size()) == 0)
    {
        std::cout << "There are no devices in the base.\n";
    }
    else
    {
        for (auto d : devices)
        {
            d.second->show_info();
        }
    }


}

void Base::show_devices_by_type() {
    std::cout << "What type of device do you want to show?\n";
    int type = ask_for_type();

    auto& subcontainer = type == 1 ? notebooks_ids : smartbands_ids;

    if (subcontainer.size() == 0)
    {
        std::cout << "There are no devices of this type in the base.\n";
    }
    else
    {
        for (auto id : subcontainer)
        {
            devices[id]->show_info();
        }
    }
}

void Base::show_devices_by_type_and_price_range() {
    std::cout << "What type of device do you want to show?\n";
    int type = ask_for_type();
    std::cout << "Enter price range (min max): ";
    int min, max;
    std::cin >> min >> max;

    auto& subcontainer = type == 1 ? notebooks_ids : smartbands_ids;

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
    if ((std::find(notebooks_ids.begin(), notebooks_ids.end(), id1) != notebooks_ids.end()) && (std::find(notebooks_ids.begin(), notebooks_ids.end(), id2) != notebooks_ids.end()))
    {
        Notebook& n1 = dynamic_cast<Notebook&>(*devices[id1]);
        Notebook& n2 = dynamic_cast<Notebook&>(*devices[id2]);
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
    int type = ask_for_type();

    std::string manufacturer;
    std::string model;
    double price;
    bool found = false;

    auto& subcontainer = type == 1 ? notebooks_ids : smartbands_ids;
    std::cout << "Enter search parameters:\n";
    switch(type) {
        case 1: {

            std::cout << "Enter notebook manufacturer: ";
            std::cin >> manufacturer;
            std::cout << "Enter notebook model: ";
            std::cin >> model;
            std::cout << "Enter notebook price ($): ";
            std::cin >> price;
            std::cout << "Enter notebook RAM (GB):  ";
            int ram;
            std::cin >> ram;
            std::cout << "Enter notebook storage (GB): ";
            int disk;
            std::cin >> disk;

            for (auto id: subcontainer) {
                Notebook& n = dynamic_cast<Notebook &>(*devices[id]);
                if ((n.manufacturer == manufacturer) && (n.model == model) && (n.get_price() == price) &&
                    (n.get_RAM() == ram) && (n.get_disk() == disk)) {
                    std::cout << "This device has ID: " << id << "\n";
                    n.show_info();
                    found = true;
                }
            }

            break;
        }
        case 2: {
            std::cout << "Enter smartband manufacturer: ";
            std::cin >> manufacturer;
            std::cout << "Enter smartband model: ";
            std::cin >> model;
            std::cout << "Enter smartband price ($): ";
            std::cin >> price;
            std::cout << "Enter smartband strip length (mm): ";
            int length;
            std::cin >> length;
            std::cout << "Enter 1 if the smartband has NFC: ";
            bool nfc;
            std::cin >> nfc;


            for (auto id: subcontainer) {
                Smartband& s = dynamic_cast<Smartband &>(*devices[id]);
                if ((s.manufacturer == manufacturer) && (s.model == model) && (s.get_price() == price) &&
                    (s.get_strip_length() == length) && (s.mobile_payments() == nfc)) {
                    std::cout << "This device has ID: " << id << "\n";
                    s.show_info();
                    found = true;
                }
            }
            break;
        }
        default:
            break;
    }

    if (!found) {
        std::cout << "No devices found.\n";
    }
}