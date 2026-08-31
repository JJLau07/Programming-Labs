#include <iostream>

// Incident Metrics Program
int main()
{
    int totalIncidents{};
    int resolvedIncidents{};
    int analystCount{};
    double totalResponseHours{};

    std::cout << "Enter total incidents: ";
    std::cin >> totalIncidents;
    std::cout << "Enter resolved incidents: ";
    std::cin >> resolvedIncidents;
    std::cout << "Enter analyst count: ";
    std::cin >> analystCount;
    std::cout << "Enter total response hours: ";
    std::cin >> totalResponseHours;

    const int unresolvedIncidents{totalIncidents - resolvedIncidents};
    const double incidentsPerAnalyst{static_cast<double>(totalIncidents) / analystCount};
    const double averageResponseHours{static_cast<double>(totalResponseHours) / totalIncidents};
    const double resolutionPercentage{(static_cast<double>(resolvedIncidents) / totalIncidents) * 100};

    std::cout << "\nIncident Metrics Report\n";
    std::cout << "Unresolved incidents: " << unresolvedIncidents << '\n';
    std::cout << "Incidents per analyst: " << incidentsPerAnalyst << '\n';
    std::cout << "Average response hours: " << averageResponseHours << '\n';
    std::cout << "Resolution percentage: " << resolutionPercentage << "%" << '\n';

    return 0;
}