#include <iostream>
#include <string>

int main()
{
    std::string name;
    int age;
    std::string school;
    std::string program;
    std::string yearLevel;

    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Enter your school: ";
    std::getline(std::cin, school);

    std::cout << "Enter your program: ";
    std::getline(std::cin, program);

    std::cout << "Enter your year level: ";
    std::getline(std::cin, yearLevel);

    std::cout << std::endl;
    
    std::cout << "===============================" << std::endl;
    std::cout << "        STUDENT PROFILE        " << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Name       : " << name << std::endl;
    std::cout << "Age        : " << age << std::endl;
    std::cout << "School     : " << school << std::endl;
    std::cout << "Program    : " << program << std::endl;
    std::cout << "Year Level : " << yearLevel << std::endl;
    std::cout << "===============================" << std::endl;

    return 0;
}