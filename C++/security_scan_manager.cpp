#include <iostream>

// Security Scan Manager Program
void showMenu()
{
    std::cout << "\nMenu\n"
              << "1. Start scan\n"
              << "0. Exit\n"
              << "Select Menu: ";
}

int readNonnegative()
{
    int value{};
    std::cin >> value;

    while (value < 0)
    {
        std::cout << "Invalid input. Try again: ";
        std::cin >> value;
    }
    return value;
}

void classifyDevice(int alerts)
{
    if (alerts == 0)
    {
        std::cout << "Clear\n";
    }
    else if ( alerts >= 1 && alerts <= 4)
    {
        std::cout << "Low alert\n";
    }
    else 
    {
        std::cout << "High alert\n";
    }
}

int collectAlerts(int deviceCount)
{
    int totalAlerts{};

    for (int device = 1; device <= deviceCount; device++)
    {
        std::cout << "Alerts for device " << device << ": ";
        int alerts = readNonnegative();
        
        classifyDevice(alerts);
        totalAlerts += alerts;
    }
    return totalAlerts;
}

void showSummary(int deviceCount, int totalAlerts)
{
    std::cout << "\nScan Report\n";
    std::cout << "Devices scanned: " << deviceCount << '\n';
    std::cout << "Total alerts: " << totalAlerts << '\n';
}

int main()
{
    int selectedMenu{};

    do
    {   
        showMenu();
        std::cin >> selectedMenu;

        if (selectedMenu == 1)
        {

            std::cout << "\nDevices to check: ";
            int deviceCount = readNonnegative();

            int totalAlerts = collectAlerts(deviceCount);
            showSummary(deviceCount, totalAlerts);
        }
        else if (selectedMenu == 0)
        {
            std::cout << "Exiting...\n";
        }
        else
        {
            std::cout << "\nInvalid option\n";
        }
    } while (selectedMenu != 0);

    return 0;
}