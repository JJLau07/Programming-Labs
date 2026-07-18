#include <iostream>
#include <string>

int main()
{
    std::string name;
    int inputNumber;
    int counter = 1;

    std::cout << "Enter Your Name: ";
    std::getline (std::cin, name);

    std::cout << "Enter a Number: ";
    std::cin >> inputNumber;

    std::cout << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "   NUMBER COUNTER   " << std::endl;
    std::cout << "====================" << std::endl;

    std::cout << std::endl;
    std::cout << "Counting..." << std::endl;
    std::cout << std::endl;
    while (counter <= inputNumber)
        {
            std::cout << counter << std::endl;
            counter++;
        }
    std::cout << std::endl;
    std::cout << "Counting Complete, " << name << "!" << std::endl;
    std::cout << std::endl;
    std::cout << "Thank you for using the program!" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}