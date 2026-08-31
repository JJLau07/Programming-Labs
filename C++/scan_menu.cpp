#include <iostream>

// Scan Menu Program
int main()
{
    int selectedMenu{};

    do {
        std::cout << "\nMenu\n"
                  << "1.Run security scan\n"
                  << "0.Exit\n"
                  << "Select an option: ";
        std::cin >> selectedMenu;

        if (selectedMenu == 1)
        {
            std::cout << "\nScanning system...\n";
        }
        else if (selectedMenu == 0)
        {
            std::cout << "\nExiting...\n";
        }
        else
        {
            std::cout << "\nInvalid option\n";
        }
    } while (selectedMenu != 0);
    
    return 0;
}