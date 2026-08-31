#include <iostream>

int main()
{
    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << std::endl;

    if (age >= 18)
    {
        std::cout << "You are an adult." << std::endl;
    }
    else
    {
        std::cout << "You are a minor." << std::endl;
    }

    return 0;
}