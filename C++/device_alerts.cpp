#include <iostream>

// Device Alerts Program
int main()
{
    int deviceCount{};
    int deviceNumber{1};
    int totalAlerts{0};

    std::cout << "Enter number of devices: ";
    std::cin >> deviceCount;

    while (deviceNumber <= deviceCount)
    {
        int deviceAlerts{};
        std::cout << "Enter alerts for device " << deviceNumber << ": ";
        std::cin >> deviceAlerts;

        totalAlerts += deviceAlerts;
        ++deviceNumber;
    }

    std::cout << "\nDevice Alert Report\n";
    std::cout << "Devices processed: " << deviceCount << '\n';
    std::cout << "Total alerts: " << totalAlerts << '\n';

    return 0;
}