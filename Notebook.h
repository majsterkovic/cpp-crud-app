//
// Created by majsterkovic on 29.11.2021.
//

#ifndef PROJEKT_NOTEBOOK_H
#define PROJEKT_NOTEBOOK_H

#include "Device.h"


class Notebook : public virtual Device {
    int RAM;
    int disk;

public:
    int calculate_performance(int RAM, int disk);
    void show_info();

    Notebook(std::string manufacturer, std::string model, double price, int RAM, int disk);
    ~Notebook();

    friend bool operator <(Notebook &notebook1, Notebook &notebook2);
    friend bool operator >(Notebook &notebook1, Notebook &notebook2);
    friend bool operator ==(Notebook &notebook1, Notebook &notebook2);
};


#endif //PROJEKT_NOTEBOOK_H
