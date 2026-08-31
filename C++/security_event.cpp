#include <iostream>

// Security Event Program
int main()
{
    int eventId{};
    double severityScore{};
    char classification{};

    std::cout << "Enter event ID: ";
    std::cin >> eventId;
    std::cout << "Enter severity score: ";
    std::cin >> severityScore;
    std::cout << "Classification: ";
    std::cin >> classification;

    std::cout << "\nSecurity Event Report\n";
    std::cout << "Event ID: "
              << eventId << '\n';
    std::cout << "Severity score: "
              << severityScore << '\n';
    std::cout << "Classification: "
              << classification << '\n';

    return 0;
}