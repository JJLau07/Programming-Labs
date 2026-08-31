#include <iostream>

// Secure Login Program
int main()
{
    int failedAttempts{};
    double securityScore{};
    bool passwordVerified{};

    const int maximumFailedAttempts{5};
    const double minimumSecurityScore{8.0};

    bool accountLocked{false};
    bool accessGranted{false};

    std::cout << "Enter failed attempts: ";
    std::cin >> failedAttempts;
    std::cout << "Enter security score: ";
    std::cin >> securityScore;
    std::cout << "Password verified (1 or 0): ";
    std::cin >> passwordVerified;

    if (failedAttempts >= maximumFailedAttempts)
    {
        accountLocked = true;
        std::cout << "Account locked\n";
    }
    else
    {
        std::cout << "Account active\n";

        if (securityScore >= minimumSecurityScore && passwordVerified)
        {
            accessGranted = true;
            std::cout << "Access granted\n";
        }
        else
        {
            std::cout << "Access denied\n";
        }
    }

    std::cout << std::boolalpha;
    std::cout << "\nSecure Login Report\n";
    std::cout << "Account locked: " << accountLocked << '\n';
    std::cout << "Access granted: " << accessGranted << '\n';

    return 0;
}