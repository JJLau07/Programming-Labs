#include <iostream>
#include <string>
#include <cstdlib>

// ============ Declarations ============
void clearTerminal();
void invalidInput();
void exitSystem();
double calculatePercent(int count, int total);

std::string determineTemporaryBlock(int lockedAccountCount, double failurePercent);
std::string determineSecurityStatus(double failurePercent);
std::string determineCommonFailure(int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount);

void analyzeLoginAttempt( int loginCount, int successfulCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount, double& successPercent, double& failurePercent, std::string& commonFailure, std::string& securityStatus, std::string& temporaryBlock);
void displayAnalysisResult(int loginCount, int successfulCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount);
void processLoginAttempt(int loginCount, int& successfulCount, int& wrongPasswordCount, int& unknownUsernameCount, int& lockedAccountCount);
void runLoginAttempt();
void displayMainMenu(int& selectMainMenu);

// ============ Controllers ============
int main()
{
    int selectMainMenu{};
    do
    {
        displayMainMenu(selectMainMenu);

        if (selectMainMenu == 1)
        {   
            runLoginAttempt();
        }
        else if (selectMainMenu == 2)
        {
            clearTerminal();
            exitSystem();
        }
        else
        {
            clearTerminal();
            invalidInput();
        }
    } while (selectMainMenu != 2);

    return 0;
    
}

void displayMainMenu(int& selectMainMenu)
{
    std::cout << "\n============ Security Login Analyzer ============\n"
              << "1. Analyze Login Attempts\n"
              << "2. Exit\n"
              << "Select option: ";
    std::cin >> selectMainMenu;
}

void runLoginAttempt()
{
    int loginCount;
    std::cout << "Login attempts to be analyzed: ";
    std::cin >> loginCount;

    if (loginCount <= 0)
    {
        invalidInput();
        return;
    }

    int successfulCount{}, wrongPasswordCount{}, unknownUsernameCount{}, lockedAccountCount{};
    processLoginAttempt(loginCount, successfulCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
    clearTerminal();
    displayAnalysisResult(loginCount, successfulCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
}

void processLoginAttempt(int loginCount, int& successfulCount, int& wrongPasswordCount, int& unknownUsernameCount, int& lockedAccountCount)
{   
    std::cout << "\nAttempt Types: 1-Successful Login 2-Wrong Password 3-Unknown Username 4-Locked Account\n";
    for (int attempt = 1; attempt <= loginCount; attempt++)
    {
        int attemptCount;
        std::cout << "Login Attempt " << attempt << ": ";
        std::cin >> attemptCount;

        if (attemptCount == 1) successfulCount++;
        else if (attemptCount == 2) wrongPasswordCount++;
        else if (attemptCount == 3) unknownUsernameCount++;
        else if (attemptCount == 4) lockedAccountCount++;
        else
        {
            invalidInput();
            attempt--;
        }
    }
}

void displayAnalysisResult(int loginCount, int successfulCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount)
{   
    double successPercent{}, failurePercent{};
    std::string commonFailure{}, securityStatus{}, temporaryBlock{};
    analyzeLoginAttempt(loginCount, successfulCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount, successPercent, failurePercent, commonFailure, securityStatus, temporaryBlock);
    std::cout << "\n============ Analysis Result ============\n";
    std::cout << "Totals\n";
    std::cout << "  Successful Logins : " << successfulCount << '\n';
    std::cout << "  Wrong Passwords   : " << wrongPasswordCount << '\n';
    std::cout << "  Unknown Usernames : " << unknownUsernameCount << '\n';
    std::cout << "  Locked Accounts   : " << lockedAccountCount << '\n';

    std::cout << "\nPercentages\n";
    std::cout << "  Success Logins : " << successPercent << "%\n";
    std::cout << "  Failure Logins : " << failurePercent << "%\n";

    std::cout << "\nMost Common Failure : " << commonFailure << '\n';
    std::cout << "Security Status     : " << securityStatus << '\n';
    std::cout << "Temporary Block     : " << temporaryBlock << '\n';

    std::cout << "\nReturning to Main Menu...\n";
}

void analyzeLoginAttempt( int loginCount, int successfulCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount, 
                                double& successPercent, double& failurePercent,
                                std::string& commonFailure, std::string& securityStatus, std::string& temporaryBlock)
{
    int totalFailure = wrongPasswordCount + unknownUsernameCount + lockedAccountCount;
    successPercent = calculatePercent(successfulCount, loginCount);
    failurePercent = calculatePercent(totalFailure, loginCount);
    commonFailure = determineCommonFailure (wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
    securityStatus = determineSecurityStatus(failurePercent);
    temporaryBlock = determineTemporaryBlock(lockedAccountCount, failurePercent);
}
// ============ Core Logic ============
std::string determineCommonFailure(int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount)
{
    int maxCount = wrongPasswordCount;
    if (unknownUsernameCount > maxCount) maxCount = unknownUsernameCount;
    if (lockedAccountCount > maxCount) maxCount = lockedAccountCount;

    if (maxCount == 0) return "None";
    else
    {
        int ties = 0;
        if (wrongPasswordCount == maxCount) ties++;
        if (unknownUsernameCount == maxCount) ties++;
        if (lockedAccountCount == maxCount) ties++;
        if (ties > 1) return "Tie";
        else if (wrongPasswordCount == maxCount) return "Wrong Password";
        else if (unknownUsernameCount == maxCount) return "Unknown Username";
        else return "Locked Account";
    }
}

std::string determineSecurityStatus(double failurePercent)
{
    if (failurePercent >= 50.0) return "High Risk";
    else if (failurePercent > 0.0) return "Warning";
    else return "Normal";
}

std::string determineTemporaryBlock(int lockedAccountCount, double failurePercent)
{
    if (lockedAccountCount >= 3 || failurePercent >= 75.0) return "Yes";
    else return "No";
}

// ============ Utilities ============
double calculatePercent(int count, int total)
{
    if (total <= 0) return 0.0;
    return (count * 100.0) / total;
}

void exitSystem()
{
    std::cout << "\nExited Successfully.\n";
}

void invalidInput()
{
    std::cout << "\nInvalid Input. Try Again.\n";
}

void clearTerminal()
{
    #ifdef _WIN32
    std::system("cls");
    #else
        std::system("clear");
    #endif
}