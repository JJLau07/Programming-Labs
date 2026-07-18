#include <iostream>
#include <string>

int main()
{
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << std::endl;
    std::cout << "Hello, " << name << "!" << std::endl;
    std::cout << "Welcome to C++ Programming!" << std::endl;

    return 0;
}