#include <iostream>

#include "Device.h"
#include "Notebook.h"
#include "Smartband.h"
#include "Base.h"
#include <string>

void show_menu()
{
    std::cout << "1. Add new device" << std::endl;
    std::cout << "2. Show all devices" << std::endl;
    std::cout << "3. Show all devices by type" << std::endl;
    std::cout << "4. Show all devices by type and price range" << std::endl;
    std::cout << "5. Show all devices by type and brand" << std::endl;
    std::cout << "6. Custom search" << std::endl;
    std::cout << "7. Compare notebooks" << std::endl;
    std::cout << "8. Count devices by the same manufacturer" << std::endl;
    std::cout << "9. Count devices by the same model" << std::endl;
    std::cout << "10. Update price" << std::endl;
    std::cout << "11. Exit" << std::endl;
}

int main()

{

    Base *base = new Base();

    bool menu = true;
    int choice;

    base->add_device();
    base->add_device();
    base->add_device();

    base->show_all_devices();

    base->remove_device();

    base->show_all_devices();

    base->custom_search();
    base->show_devices_by_type();
    base->compare_notebooks();

    std::string model;
    std::string manufacturer;


//    do {
//
//        show_menu();
//        std::cout << "Enter your choice: ";
//
//        switch(choice)
//        {
//            case 1:
//                base->add_device();
//                break;
//            case 2:
//                base->show_all_devices();
//                break;
//            case 3:
//                base->show_devices_by_type();
//                break;
//            case 4:
//                base->show_devices_by_type_and_price_range();
//                break;
//            case 5:
//                base->show_devices_by_type_and_brand();
//                break;
//            case 6:
//                base->custom_search();
//                break;
//            case 7:
//                base->compare_notebooks();
//                break;
//            case 8:
//                base->get_amount_of_device(manufacturer);
//                break;
//            case 9:
//                base->get_amount_of_device(manufacturer, model);
//                break;
//            case 10:
//                base->update_price();
//                break;
//            case 11:
//                menu = false;
//                break;
//        }
//
//    }while(!menu);

}
