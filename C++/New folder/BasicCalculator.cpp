#include <iostream>

int main()
{
    int num1;
    int num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    int quotient = num1 / num2;

    std::cout << std::endl;
    
    std::cout << "========== BASIC CALCULATOR ==========" << std::endl;
    std::cout << "First Number  : " << num1 << std::endl;
    std::cout << "Second Number : " << num2 << std::endl;
    std::cout << std::endl;
    std::cout << "Sum           : " << sum << std::endl;
    std::cout << "Difference    : " << difference << std::endl;
    std::cout << "Product       : " << product << std::endl;
    std::cout << "Quotient      : " << quotient << std::endl;

    return 0;
}