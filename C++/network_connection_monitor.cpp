#include <iostream>
#include <cstdlib>

// Network Connection Monitor program
int main()
{ 
    int selectMainMenu{};

    do
    {
        std::cout << "\n===== Network Connection Monitor =====\n"
                  << "1. Start Connection Monitor\n"
                  << "2. Exit\n"
                  << " \n"
                  << "Select option: ";
        std::cin >> selectMainMenu;

        if (selectMainMenu == 1)
        {
            // Clear Terminal
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif

            int attemptsCount{};
            int trusted{};
            int unknown{};
            int suspicious{};
            int blocked{};

            std::cout << "\nConnection attempts to be monitored: ";
            std::cin >> attemptsCount;

            if (attemptsCount <= 0)
            {
                std::cout << "\nInvalid Input. Try Again.\n";
                continue;
            }

            std::cout << "\nConnection Type: 1-Trusted 2-Unknown 3-Suspicious 4-Blocked\n";

            for (int attempt = 1; attempt <= attemptsCount; attempt++)
            {
                int connectionType{};
                std::cout << "Connection Attempt " << attempt << ": ";
                std::cin >> connectionType;

                if (connectionType == 1)
                {
                    trusted++;
                }
                else if (connectionType == 2)
                {
                    unknown++;
                }
                else if (connectionType == 3)
                {
                    suspicious++;
                }
                else if (connectionType == 4)
                {
                    blocked++;
                }
                else
                {
                    std::cout << "\nInvalid Input. Try Again.\n";
                    attempt--;
                }
            }

            // Clear Terminal
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif
            std::cout << "\n====== Results ======\n";
            int maxCount = trusted;
            if (unknown > maxCount) maxCount = unknown;
            if (suspicious > maxCount) maxCount = suspicious;
            if (blocked > maxCount) maxCount = blocked;

            int ties = 0;
            if (trusted == maxCount) ties++;
            if (unknown == maxCount) ties++;
            if (suspicious == maxCount) ties++;
            if (blocked == maxCount) ties++;
            
            if (ties > 1)
            {
                std::cout << "Most Common Connection Type: Tie\n";
            }
            else if (trusted == maxCount)
            {
                std::cout << "Most Common Connection Type: Trusted\n";
            }
            else if (unknown == maxCount)
            {
                std::cout << "Most Common Connection Type: Unknown\n";
            }
            else if (suspicious == maxCount)
            {
                std::cout << "Most Common Connection Type: Suspicious\n";
            }
            else if (blocked == maxCount)
            {
                std::cout << "Most Common Connection Type: Blocked\n";
            }

            double trustedPercent = trusted * 100.0 / attemptsCount;
            double suspiciousBlockedPercent = (suspicious + blocked) * 100.0 / attemptsCount;

            std::cout << "\nTotal Connections: " << attemptsCount << '\n';
            std::cout << "Trusted Connections: " << trusted << '\n';
            std::cout << "Unknown Connections: " << unknown << '\n';
            std::cout << "Suspicious Connections: " << suspicious << '\n';
            std::cout << "Blocked Connections: " << blocked << '\n';
            std::cout << "\n====== Percentage ======\n";
            std::cout << "Trusted Connections: " << trustedPercent << "%\n";
            std::cout << "Suspicious & Blocked Connections: " << suspiciousBlockedPercent << "%\n";

            if (suspicious + blocked <= 0)
            {
                std::cout << "\nNetwork Status: Secure\n";
                std::cout << " \n";
            }
            else if (suspiciousBlockedPercent < 50.0)
            {
                std::cout << "\nNetwork Status: Warning\n";
                std::cout << " \n";
            }
            else
            {
                std::cout << "\nNetwork Status: Critical\n";
                std::cout << " \n";
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
            std::cout << "\nInvalid Input. Try Again.\n";
        }
    } while (selectMainMenu != 2);

    return 0;
}