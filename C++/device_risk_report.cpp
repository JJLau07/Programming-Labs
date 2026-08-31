#include <iostream>

// Device Risk Report Program
int main()
{

    int deviceCount{};

    std::cout << "Devices to check: ";
    std::cin >> deviceCount;

    int totalAlerts{};
    int highAlerts{};

    for (int device = 1; device <= deviceCount; device++)
    {
        int alerts{};

        std::cout << "\nAlerts for device " << device << ": ";
        std::cin >> alerts;
        if (alerts >= 5)
        {
        std::cout << "High alert\n";
        highAlerts++;
        }
        else 
        {
            std::cout << "Low alert\n";
        }

        totalAlerts += alerts;
    }

    std::cout << "\nTotal devices: " << deviceCount << '\n';
    std::cout << "Total alerts: " << totalAlerts << '\n';
    std::cout << "High alert devices: " << highAlerts << '\n';

    return 0;
}