#include <iostream>

// Security Scan Program
int main()
{
    int detectedThreats{12};
    double scanDuration{4.75};
    char riskLevel{'H'};
    bool scanCompleted{true};

    std::cout << std::boolalpha;

    std::cout << "Detected threats: "
              << detectedThreats << '\n';
    std::cout << "Scan duration: "
              << scanDuration << " seconds" << '\n';
    std::cout << "Risk level: "
              << riskLevel << '\n';
    std::cout << "Scan completed: "
              << scanCompleted << '\n';

    return 0;
}