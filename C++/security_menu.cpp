#include <iostream>
#include <string>

// Security Menu Program
int main()
{
    int menuChoice{};
    
    std::string selectedAction{};
    bool validChoice{true};
    bool scanRequested{false};
    bool reportRequested{false};
    bool exitRequested{false};

    std::cout << "Security Operations Menu\n"
              << "1. Run security scan\n"
              << "2. View incident report\n"
              << "3. Exit\n"
              << "Enter choice: ";
    std::cin >> menuChoice;

    switch (menuChoice)
    {
        case 1:
            selectedAction = "Run security scan";
            scanRequested = true;
            break;

        case 2:
            selectedAction = "View incident report";
            reportRequested = true;
            break;

        case 3:
            selectedAction = "Exit";
            exitRequested = true;
            break;

        default:
            selectedAction = "Invalid";
            validChoice = false;
            break;
    }

    std::cout << std::boolalpha;
    std::cout << "\nOperation Selection Report\n";
    std::cout << "Selected action: " << selectedAction << '\n';
    std::cout << "Valid choice: " << validChoice << '\n';
    std::cout << "Scan requested: " << scanRequested << '\n';
    std::cout << "Report requested: " << reportRequested << '\n';
    std::cout << "Exit requested: " << exitRequested << '\n';

    return 0;
}