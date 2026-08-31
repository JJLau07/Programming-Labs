#include <iostream>
#include <string>

// Incident Record Program
int main()
{
    int incidentId{};
    
    std::string analystName{};
    std::string incidentTitle{};
    std::string incidentDescription{};

    std::cout << "Enter incident ID: ";
    std::cin >> incidentId;
    std::cout << "Enter analyst name: ";
    std::getline(std::cin >> std::ws, analystName);
    std::cout << "Enter incident title: ";
    std::getline(std::cin, incidentTitle);
    std::cout << "Enter incident description: ";
    std::getline(std::cin, incidentDescription);

    std::cout << "\nIncident Record\n";
    std::cout << "Incident ID: "
              << incidentId << '\n';
    std::cout << "Analyst: "
              << analystName << '\n';
    std::cout << "Title: "
              << incidentTitle << '\n';
    std::cout << "Description: "
              << incidentDescription << '\n';
    
    return 0;
}   