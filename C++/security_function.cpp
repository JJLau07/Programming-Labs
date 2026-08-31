#include <iostream>

void showMenu()
{
    std::cout << "\n1. Run scan\n"
              << "0. Exit\n"
              << "Select option: ";
}

void runScan()
{
    for (int device = 1; device <= 3; device++)
    {
        std::cout << "Scanning messages for device " << device << '\n';
    }
    std::cout << "\nScan Complete.\n";
}

void showExit()
{
    std::cout << "\nExiting program...\n";
}

int main()
{
    int selectedOption{};

    do
    {
        showMenu();
        std::cin >> selectedOption;

        if (selectedOption == 1)
        {
            runScan();
        }
        else if (selectedOption == 0)
        {
            showExit();
        }
        else
        {
            std::cout << "\nInvalid option\n";
        }

    } while (selectedOption != 0);

    return 0;
}