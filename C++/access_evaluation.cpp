#include <iostream>

// Access Evaluation Program
int main()
{
    int failedAttempts{};
    double securityScore{};
    char enteredClearance{};
    bool passwordVerified{};
    bool recoveryCodeVerified{};

    const int maximumFailedAttempts{5};
    const double minimumSecurityScore{8.0};
    const char requiredClearance{'B'};


    std::cout << "Enter failed attempts: ";
    std::cin >> failedAttempts;
    std::cout << "Enter security score: ";
    std::cin >> securityScore;
    std::cout << "Enter clearance level: ";
    std::cin >> enteredClearance;
    std::cout << "Password verified (1 or 0): ";
    std::cin >> passwordVerified;
    std::cout << "Recovery code verified (1 or 0): ";
    std::cin >> recoveryCodeVerified;

    const bool attemptsAccepted{failedAttempts < maximumFailedAttempts};
    const bool scoreAccepted{securityScore >= minimumSecurityScore};
    const bool clearanceMatches{enteredClearance == requiredClearance};
    const bool identityVerified{passwordVerified || recoveryCodeVerified};
    const bool basicRequirementsMet{attemptsAccepted && scoreAccepted && clearanceMatches};
    const bool accessGranted{basicRequirementsMet && identityVerified};
    const bool accessDenied{!accessGranted};
    const bool securityWarning{!attemptsAccepted || !scoreAccepted};
    
    std::cout << std::boolalpha;
    std::cout << "\nAccess Evaluation Report\n";
    std::cout << "Attempts accepted: " << attemptsAccepted << '\n';
    std::cout << "Score accepted: " << scoreAccepted << '\n';
    std::cout << "Clearance matches: " << clearanceMatches << '\n';
    std::cout << "Identity verified: " << identityVerified << '\n';
    std::cout << "Basic requirements met: " << basicRequirementsMet << '\n';
    std::cout << "Access granted: " << accessGranted << '\n';
    std::cout << "Access denied: " << accessDenied << '\n';
    std::cout << "Security warning: " << securityWarning << '\n';

    return 0;
}