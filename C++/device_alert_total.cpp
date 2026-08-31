#include <iostream>

// Device Alert Program
int main()
{
    int deviceCount{};

    std::cout << "How many devices to check: ";
    std::cin >> deviceCount;

    int totalAlerts{};

    for (int device = 1; device <= deviceCount; device++)
    {
        int alerts;

        std::cout << "Alerts for device " << device << ": ";
        std::cin >> alerts;

        totalAlerts = totalAlerts + alerts;
    }

        std::cout << "Devices Checked: " << deviceCount << '\n';
        std::cout << "Total alerts: " << totalAlerts << '\n';

    return 0;
}