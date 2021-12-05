//
// Created by majsterkovic on 29.11.2021.
//

#include "Notebook.h"

int Notebook::calculate_performance(int RAM, int disk) const {
    return RAM*100+disk;
}

Notebook::Notebook(std::string manufacturer, std::string model, double price, int RAM, int disk) : Device(manufacturer, model, price ), RAM(RAM), disk(disk) {}

void Notebook::show_info() const {
    Device::show_info();
    std::cout << "RAM: " << this->RAM << " GB" << std::endl;
    std::cout << "Disk: " << this->disk << " GB" << std::endl;
}

bool operator<(Notebook &notebook1, Notebook &notebook2) {
    return notebook1.calculate_performance(notebook1.RAM, notebook1.disk) < notebook2.calculate_performance(notebook2.RAM, notebook2.disk);
}

bool operator>(Notebook &notebook1, Notebook &notebook2) {
    return notebook1.calculate_performance(notebook1.RAM, notebook1.disk) > notebook2.calculate_performance(notebook2.RAM, notebook2.disk);
}

bool operator==(Notebook &notebook1, Notebook &notebook2) {
    return notebook1.calculate_performance(notebook1.RAM, notebook1.disk) == notebook2.calculate_performance(notebook2.RAM, notebook2.disk);
}


int Notebook::get_RAM() const {
    return this->RAM;
}

int Notebook::get_disk() const {
    return this->disk;
}



