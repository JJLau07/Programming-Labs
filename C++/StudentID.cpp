#include <iostream>
#include <string>

int main()
{
    std::string name = "Jalf Joseph Lauron";
    std::string program = "BS CyberSecurity";
    std::string school = "AMA University";
    std::string level = "1st Year";
    int age = 26;
    double gpa = 1.75;

    std::cout << "========================================" << std::endl;
    std::cout << "               STUDENT ID               " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;
    std::cout << "Name       : " << name << std::endl;
    std::cout << "Age        : " << age << std::endl;
    std::cout << "Program    : " << program << std::endl;
    std::cout << "School     : " << school << std::endl;
    std::cout << "Year Level : " << level << std::endl;
    std::cout << "GPA        : " << gpa << std::endl;
    std::cout << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}