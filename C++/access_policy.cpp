#include <iostream>

// Access Policy Program
int main()
{
    const int maximumLoginAttempts{5};
    const double sessionTimeout{30.5};
    const char requiredClearance{'B'};
    const bool multiFactorRequired{true};

    int currentLoginAttempts{1};

    std::cout << std::boolalpha;

    std::cout << "Maximum login attempts: "
              << maximumLoginAttempts << '\n';
    std::cout << "Session timeout: "
              << sessionTimeout << " minutes" << '\n';
    std::cout << "Required clearance: "
              << requiredClearance << '\n';
    std::cout << "Multi-factor required: "
              << multiFactorRequired << '\n';
    std::cout << "Current login attempts: "
              << currentLoginAttempts << '\n';
    
    currentLoginAttempts = 3;
    std::cout << "Updated login attempts: "
              << currentLoginAttempts << '\n';

    return 0;
}