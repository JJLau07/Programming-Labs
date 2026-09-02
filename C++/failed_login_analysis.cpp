#include <iostream>
#include <string>
#include <cstdlib>

// Failed Login Analysis Program
void clearTerminal()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

double calculatePercentage (int count, int total)
{
    if (total <= 0) return 0.0;
    return (count * 100.0) / total;
}

std::string determineSecurityStatus (double failurePercent)
{
    if (failurePercent == 0.0)
    {
        return "Normal";
    }
    else if (failurePercent < 50.0)
    {
        return "Warning";
    }
    else
    {
        return "High Risk";
    }
}

int main()
{
    int selectMainMenu{};
    do
    {
        std::cout << "\n====== Failed Login Analysis System ======\n"
                  << "1. Analyze Login Attempts\n"
                  << "2. Exit\n"
                  << "\nSelect option: ";
        std::cin >> selectMainMenu;

        if(selectMainMenu == 1)
        {
            clearTerminal();

            int attemptCount{};
            int successfulCount{};
            int wrongPasswordCount{};
            int unknownUsernameCount{};
            int lockedAccountCount{};

            std::cout << "\nLogin Attempts to be Analyzed: ";
            std::cin >> attemptCount;

            if (attemptCount <= 0)
            {
                std::cout << "\nInvalid Input. Try Again.\n";
                continue;
            }

            std::cout << "\nScale: 1-Successful 2-Wrong Password 3-Unknown Username 4-Locked Account\n";

            for (int attempt = 1; attempt <= attemptCount; attempt++)
            {   
                int resultCount{};
                std::cout << "Login Attempt " << attempt << ": ";
                std::cin >> resultCount;

                if (resultCount == 1)
                {
                    successfulCount++;
                }
                else if (resultCount == 2)
                {
                    wrongPasswordCount++;
                }
                else if (resultCount == 3)
                {
                    unknownUsernameCount++;
                }
                else if (resultCount == 4)
                {
                    lockedAccountCount++;
                }
                else
                {
                    std::cout << "\nInvalid Input. Try Again.\n";
                    attempt--;
                }
            }

            clearTerminal();

            std::cout << "\n============ Results ============\n";
            std::cout << "Total Login Attempts: " << attemptCount << '\n';
            std::cout << "Successful Logins: " << successfulCount << '\n';
            std::cout << "Wrong Password Attempts: " << wrongPasswordCount << '\n';
            std::cout << "Unknown Username Attempts: " << unknownUsernameCount << '\n';
            std::cout << "Locked Account Attempts: " << lockedAccountCount << '\n';
            
            int totalFailure = wrongPasswordCount + unknownUsernameCount + lockedAccountCount;

            double successPercent = calculatePercentage (successfulCount, attemptCount);
            double failurePercent = calculatePercentage (totalFailure, attemptCount);

            std::cout << "\n=========== Percentage ==========\n";
            std::cout << "Success Percentage: " << successPercent << "%\n";
            std::cout << "Failure Percentage: " << failurePercent << "%\n";

            // Finding highest Count
            int maxCount = wrongPasswordCount;
            if (unknownUsernameCount > maxCount) maxCount = unknownUsernameCount;
            if (lockedAccountCount > maxCount) maxCount = lockedAccountCount;

            std::string commonFailure{};
            if (maxCount == 0)
            {
                commonFailure = "None";
            }
            else
            {
                //Determining Ties
                int ties = 0;
                if (wrongPasswordCount == maxCount) ties++;
                if (unknownUsernameCount == maxCount) ties++;
                if (lockedAccountCount == maxCount) ties++;

                if (ties > 1)
                {
                    commonFailure = "Tie";
                }
                else if (wrongPasswordCount == maxCount)
                {
                    commonFailure = "Wrong Password";
                }
                else if (unknownUsernameCount == maxCount)
                {
                    commonFailure = "Unknown Username";
                }
                else if (lockedAccountCount == maxCount)
                {
                    commonFailure = "Locked Account";
                }
            }
            std::cout << "\nMost Common Failure: " << commonFailure << '\n';

            std::string securityStatus = determineSecurityStatus(failurePercent);
            std::cout << "Security Status: " << securityStatus << '\n';

            std::string temporaryBlock{};
            if (lockedAccountCount >= 3 || failurePercent >= 75.0)
            {
                temporaryBlock = "Yes";
            }
            else
            {
                temporaryBlock = "No";
            }
            std::cout << "Temporary Block: " << temporaryBlock << '\n';
            std::cout << "\n";
            std::cout << "Returning to Menu...\n";
        }
        else if (selectMainMenu == 2)
        {
            clearTerminal();

            std::cout << "\nExited Successfully.\n";
        }
        else
        {
            clearTerminal();
            std::cout << "\nInvalid Input. Try Again.\n";
        }

    } while (selectMainMenu != 2);

    return 0;
}