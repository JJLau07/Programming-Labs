#include <iostream>

// Scan Summary Program
int collectAlerts(int deviceCount)
{
    int totalAlerts{};

    for (int device = 1; device <= deviceCount; device++)
    {
        int alerts{};
        std::cout << "Alerts for device " << device << ": ";
        std::cin >> alerts;
        totalAlerts += alerts;
    }

    return totalAlerts;
}

void showSummary(int deviceCount, int totalAlerts)
{
    std::cout << "\nDevices checked: " << deviceCount << '\n';
    std::cout << "Total alerts: " << totalAlerts << '\n';
}

int main()
{
    int deviceCount{};

    std::cout << "Devices to check: ";
    std::cin >> deviceCount;

   int total = collectAlerts(deviceCount);
   showSummary(deviceCount, total);

   return 0;
}