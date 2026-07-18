#include <iostream>
#include <string>

int main()
{
    std::string name;
    int choice;

    std::cout << "Enter Your Name: ";
    std::getline (std::cin, name);

    std::cout << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "       Main Menu       " << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "  1. View Profile" << std::endl;
    std::cout << "  2. Settings" << std::endl;
    std::cout << "  3. Help" << std::endl;
    std::cout << "  4. Exit" << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "Enter Your Choice: ";
    std::cin >> choice;
    std::cout << std::endl;
    switch (choice)
    {
        case 1:
            std::cout << "Viewing Profile..." << std::endl;
            break;
        case 2:
            std::cout << "Opening Settings..." << std::endl;
            break;
        case 3:
            std::cout << "Opening Help Center..." << std::endl;
            break;
        case 4:
            std::cout << "Exiting Program..." << std::endl;
            break;
        default:
            std::cout << "Invalid Menu Option" << std::endl;
    }
    std::cout << std::endl;
    std::cout << " Thank you for using the program " << name << "!" << std::endl;

    return 0;
}