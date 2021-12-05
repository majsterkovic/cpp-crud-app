#include <iostream>

#include "Device.h"
#include "Base.h"
#include <string>
#include <thread>
#include <chrono>

void show_menu()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "\n";
    std::cout << "1. Add new device" << std::endl;
    std::cout << "2. Show all devices" << std::endl;
    std::cout << "3. Show all devices by type" << std::endl;
    std::cout << "4. Show all devices by type and price range" << std::endl;
    std::cout << "5. Custom search" << std::endl;
    std::cout << "6. Compare notebooks" << std::endl;
    std::cout << "7. Count devices by the same manufacturer" << std::endl;
    std::cout << "8. Count devices by the same model" << std::endl;
    std::cout << "9. Update price" << std::endl;
    std::cout << "10. Delete device" << std::endl;
    std::cout << "11. Exit" << std::endl;
}

int main()

{
    std::cout << "Welcome to the device database management application" << std::endl;

    Base *base = new Base();

    bool menu = true;
    int choice;

    std::string manufacturer;
    std::string model;


    do {

        show_menu();
        std::cin.clear();
        fflush(stdin);
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice)
        {
            case 1:
                base->add_device();
                break;
            case 2:
                base->show_all_devices();
                break;
            case 3:
                base->show_devices_by_type();
                break;
            case 4:
                base->show_devices_by_type_and_price_range();
                break;
            case 5:
                base->custom_search();
                break;
            case 6:
                base->compare_notebooks();
                break;
            case 7:
                std::cout << "Enter manufacturer: ";
                std::cin >> manufacturer;
                std::cout << base->get_amount_of_device(manufacturer) << " device(s) found\n";
                break;
            case 8:
                std::cout << "Enter manufacturer: ";
                std::cin >> manufacturer;
                std::cout << "Enter model: ";
                std::cin >> model;
                std::cout << base->get_amount_of_device(manufacturer, model) << " device(s) found\n";
                break;
            case 9:
                base->update_price();
                break;
            case 10:
                base->remove_device();
                break;
            case 11:
                menu = false;
                std::cout << "Goodbye!" << std::endl;
                break;
        }

    }while(menu);

    delete base;

    return 1;
}
