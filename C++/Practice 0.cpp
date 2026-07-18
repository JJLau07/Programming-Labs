#include <iostream>
#include <string>

int main()
{
    std::string inputName;
    std::string studentName = "Jalf Joseph Lauron";
    std::string school = "AMA University";
    std::string program = "BS-CyberSecurity";
    std::string level = "1st Year";
    int age = 26;

    std::cout << "Enter Your Name: ";
    std::getline (std::cin, inputName);
    std::cout << std::endl;
    std::cout << "Hello " << inputName << "!" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "*                                         *" << std::endl;
    std::cout << "*      WELCOME TO MY C++ PROGRAMMING!     *" << std::endl;
    std::cout << "*                                         *" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << std::endl;
    std::cout << "          STUDENT PROFILE          " << std::endl;
    std::cout << std::endl;
    std::cout << "Name       : " << studentName << std::endl;
    std::cout << "Age        : " << age << std::endl;
    std::cout << "School     : " << school << std::endl;
    std::cout << "Program    : " << program << std::endl;
    std::cout << "Year Level : " << level << std::endl;
    std::cout << std::endl;
    std::cout << "Message:" << std::endl;
    std::cout << "One of my goals is to become one of the best cybersecurity professional." << std::endl;
    std::cout << "My journey starts here." << std::endl;
    std::cout << std::endl;
    std::cout << "Thank you for reading " << inputName << "!" << std::endl;
    std::cout << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "                 ASCII ART                 " << std::endl;
    std::cout << std::endl;
    std::cout << "  /|" << std::endl;
    std::cout << " / |" << std::endl;
    std::cout << "/__|" << std::endl;
    std::cout << std::endl;
    std::cout << " _____" << std::endl;
    std::cout << "|     |" << std::endl;
    std::cout << "|     |" << std::endl;
    std::cout << "|_____|" << std::endl;
    std::cout << std::endl;
    std::cout << "===========================================" << std::endl;

    return 0;
}