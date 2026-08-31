#include <iostream>
#include <string>
#include <cstdlib>

int main()
{   
    int selectMainMenu{};

    do
    {
        // Main Menu
        std::cout << "\n===== Security Event Monitor =====\n"
                << "1. Start Monitoring\n"
                << "2. Exit\n"
                << "\nSelect option: ";
        std::cin >> selectMainMenu;

        if (selectMainMenu == 1)
        {
            // Clear Terminal
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif

            int eventCount{};
            int lowEvents{};
            int mediumEvents{};
            int highEvents{};
            int criticalEvents{};

            std::cout << "\nSecurity Events to monitor: ";
            std::cin >> eventCount;

            if (eventCount < 0)
            {
                std::cout << "\nInvalid Input. Please Try Again.\n";
                continue;
            }

            std::cout << "\nSeverity Scale: 1-Low 2-Medium 3-High 4-Critical\n";

            for (int event = 1; event <= eventCount; event++)
            {
                int severity{};
                std::cout << "Security Event " << event << ": ";
                std::cin >> severity;

                if (severity == 1)
                {
                    lowEvents++;
                }
                else if (severity == 2)
                {
                    mediumEvents++;
                }
                else if (severity == 3)
                {
                    highEvents++;
                }
                else if (severity == 4)
                {
                    criticalEvents++;
                }
                else
                {   
                    std::cout << "\nInvalid Severity Input. Please Try Again.\n";
                    event--;
                }
            }

            // Clear Terminal
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif

            double highCriticalPercent = (highEvents + criticalEvents ) * 100.0 / eventCount;

            std::cout << "\n====== Results ======\n";
            std::cout << "Total Events: " << eventCount << '\n';
            std::cout << "Low Events: " << lowEvents << '\n';
            std::cout << "Medium Events: " << mediumEvents << '\n';
            std::cout << "High Events: " << highEvents << '\n';
            std::cout << "Critical Events: " << criticalEvents << '\n';


            if (highEvents + criticalEvents > 0)
            {
                std::cout << "\nWarning: " << highCriticalPercent << "% Security Threats Detected!\n";
            }
            else
            {
                std::cout << "\nSystem: Normal.\n";
            }
        }
        else if (selectMainMenu == 2)
        {
            // Clear Terminal
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif
            std::cout << "\nExited Successfully.\n";
        }
        else
        {
            std::cout << "\nInvalid Input. Please Try Again\n";
        }

    } while (selectMainMenu != 2);
    
    return 0;
}