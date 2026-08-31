#include <iostream>

// Intrusion Response Program
int main()
{
    int failedAttempts{};
    double threatScore{};
    bool administratorVerified{};

    const int maximumFailedAttempts{5};
    const double criticalThreatScore{8.0};

    bool accountLocked{false};
    bool criticalAlert{false};
    bool investigationRequired{false};
    bool administratorAccess{false};

    std::cout << "Enter failed attempts: ";
    std::cin >> failedAttempts;
    std::cout << "Enter threat score: ";
    std::cin >> threatScore;
    std::cout << "Administrator verified (1 or 0): ";
    std::cin >> administratorVerified;

    if (failedAttempts >= maximumFailedAttempts)
    {
         accountLocked = true;
         std::cout << "Account lock activated\n";
    }
    if (threatScore >= criticalThreatScore)
    {
         criticalAlert = true;
         std::cout << "Critical threat detected\n";
    }
    if (accountLocked || criticalAlert)
     {
          investigationRequired = true;
           std::cout << "Investigation required\n";
    }
    if (administratorVerified && !investigationRequired)
    {
        administratorAccess = true;
        std::cout << "Administrator access permitted\n";
    }

    std::cout << std::boolalpha;
    std::cout << "\nIntrusion Response Report\n";
    std::cout << "Account locked: " << accountLocked << '\n';
    std::cout << "Critical alert: " << criticalAlert << '\n';
    std::cout << "Investigation required: " << investigationRequired << '\n';
    std::cout << "Administrator access: " << administratorAccess << '\n';

    return 0;
}   