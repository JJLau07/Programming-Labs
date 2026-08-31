#include <iostream>

// Alert Workload Program
int main()
{
    int newAlerts{};
    int existingAlerts{};
    int resolvedAlerts{};
    int analystCount{};
    double minutesPerAlert{};

    std::cout << "Enter new alerts: ";
    std::cin >> newAlerts;
    std::cout << "Enter existing alerts: ";
    std::cin >> existingAlerts;
    std::cout << "Enter resolved alerts: ";
    std::cin >> resolvedAlerts;
    std::cout << "Enter analyst count: ";
    std::cin >> analystCount;
    std::cout << "Enter minutes per alert: ";
    std::cin >> minutesPerAlert;

    const int totalAlerts{newAlerts + existingAlerts};
    const int remainingAlerts{totalAlerts - resolvedAlerts};
    const int alertsPerAnalyst{remainingAlerts / analystCount};
    const int leftoverAlerts{remainingAlerts % analystCount};
    const double estimatedMinutes{remainingAlerts * minutesPerAlert};

    std::cout << "\nAlert Workload Report\n";
    std::cout << "Total alerts: " << totalAlerts << '\n';
    std::cout << "Remaining alerts: " << remainingAlerts << '\n';
    std::cout << "Alerts per analyst: " << alertsPerAnalyst << '\n';
    std::cout << "Leftover alerts: " << leftoverAlerts << '\n';
    std::cout << "Estimated minutes: " << estimatedMinutes << '\n';

    return 0;
}