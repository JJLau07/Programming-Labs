#include <iostream>

// Device Scan program
int main()
{
    int deviceCount{};
    std::cout << "How many devices to scan? ";
    std::cin >> deviceCount;

    for (int scan = 1; scan <= deviceCount; scan++)
    {
        std::cout << "Scanning device " << scan << '\n';
    }

    std::cout << "\nScan complete. Devices scanned: " << deviceCount << '\n';
    
    return 0;
}