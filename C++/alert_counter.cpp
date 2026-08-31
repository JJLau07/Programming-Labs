#include <iostream>

// Alert Counter Program
int main()
{
    int activeAlerts{12};
    int resolvedAlerts{5};
    int blockedAddresses{3};
    double investigationHours{2.5};

    std::cout << "Initial active alerts: " << activeAlerts << '\n';
    std::cout << "Initial resolved alerts: " << resolvedAlerts << '\n';
    std::cout << "Initial blocked addresses: " << blockedAddresses << '\n';
    std::cout << "Initial investigation hours: " << investigationHours << '\n';

    ++activeAlerts;
    activeAlerts += 4;
    resolvedAlerts++;
    resolvedAlerts += 2;
    --blockedAddresses;
    investigationHours *= 3;

    std::cout << "\nUpdated Alert Report\n";
    std::cout << "Active alerts: " << activeAlerts << '\n';
    std::cout << "Resolved alerts: " << resolvedAlerts << '\n';
    std::cout << "Blocked addresses: " << blockedAddresses << '\n';
    std::cout << "Investigation hours: " << investigationHours << '\n';

    return 0;
}