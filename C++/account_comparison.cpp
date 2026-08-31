#include <iostream>

// Account Comparison Program
int main()
{
    int failedAttempts{};
    double securityScore{};
    char enteredClearance{};

    const int maximumFailedAttempts{5};
    const double requiredSecurityScore{8.0};
    const char requiredClearance{'B'};

    std::cout << "Enter failed attempts: ";
    std::cin >> failedAttempts;
    std::cout << "Enter security score: ";
    std::cin >> securityScore;
    std::cout << "Enter clearance level: ";
    std::cin >> enteredClearance;

    std::cout << std::boolalpha;
    const bool attemptsBelowMaximum{failedAttempts < maximumFailedAttempts};
    const bool attemptsAtMaximum{failedAttempts == maximumFailedAttempts};
    const bool maximumExceeded{failedAttempts > maximumFailedAttempts};
    const bool scoreMeetsRequirement{securityScore >= requiredSecurityScore};
    const bool clearanceMatches{enteredClearance == requiredClearance};
    const bool clearanceDiffers{enteredClearance != requiredClearance};

    std::cout << "\nAccount Security Comparison\n";
    std::cout << "Attempts below maximum: " << attemptsBelowMaximum << '\n';
    std::cout << "Attempts at maximum: " << attemptsAtMaximum << '\n';
    std::cout << "Maximum exceeded: " << maximumExceeded << '\n';
    std::cout << "Security score meets requirements: " << scoreMeetsRequirement << '\n';
    std::cout << "Clearance matches: " << clearanceMatches << '\n';
    std::cout << "Clearance differs: " << clearanceDiffers << '\n';

    return 0;
}