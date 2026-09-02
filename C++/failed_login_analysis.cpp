#include <iostream>
#include <string>
#include <cstdlib>

// ============ Declarations ============
void clearTerminal();
double calculatePercentage(int count, int total);
std::string determineSecurityStatus(double failurePercent);
std::string temporaryBlockDecision(double failurePercent, int lockedAccountCount);
std::string determineCommonFailure(int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount);
void processLoginAttempts(int attemptCount, int& successfulCount, int& wrongPasswordCount, int& unknownUsernameCount, int& lockedAccountCount);
void analyzeLoginAttempt(int attemptCount, int successfulCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount, double& successPercent, double& failurePercent, std::string& commonFailure, std::string& securityStatus, std::string& temporaryBlock);
void displayAnalysisResult(int attemptCount, int successfulCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount);
void runAnalysisSystem();

// ============ Controller ============
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
            runAnalysisSystem();
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

void runAnalysisSystem()
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
        return;
    }
    processLoginAttempts(attemptCount, successfulCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
    clearTerminal();
    displayAnalysisResult(attemptCount, successfulCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
}

void processLoginAttempts(int attemptCount, int& successfulCount, int& wrongPasswordCount,
                          int& unknownUsernameCount, int& lockedAccountCount)
{
    std::cout << "\nScale: 1-Successful 2-Wrong Password 3-Unknown Username 4-Locked Account\n";
    for (int attempt = 1; attempt <= attemptCount; attempt++)
    {   
        int resultCount{};
        std::cout << "Login Attempt " << attempt << ": ";
        std::cin >> resultCount;
        if (resultCount == 1) successfulCount++;
        else if (resultCount == 2) wrongPasswordCount++;
        else if (resultCount == 3) unknownUsernameCount++;
        else if (resultCount == 4) lockedAccountCount++;
        else
        {
            std::cout << "\nInvalid Input. Try Again.\n";
            attempt--;
        }
    }
}

void displayAnalysisResult (int attemptCount, int successfulCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount)
{
    double successPercent{}, failurePercent{};
    std::string commonFailure{}, securityStatus{}, temporaryBlock{};
    analyzeLoginAttempt(attemptCount, successfulCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount, successPercent, failurePercent, commonFailure, securityStatus, temporaryBlock);
    std::cout << "\n============ Results ============\n";
    std::cout << "Total Login Attempts: " << attemptCount << '\n';
    std::cout << "Successful Logins: " << successfulCount << '\n';
    std::cout << "Wrong Password Attempts: " << wrongPasswordCount << '\n';
    std::cout << "Unknown Username Attempts: " << unknownUsernameCount << '\n';
    std::cout << "Locked Account Attempts: " << lockedAccountCount << '\n';
    std::cout << "\n=========== Percentage ==========\n";
    std::cout << "Success Percentage: " << successPercent << "%\n";
    std::cout << "Failure Percentage: " << failurePercent << "%\n";
    std::cout << "\nMost Common Failure: " << commonFailure << '\n';
    std::cout << "Security Status: " << securityStatus << '\n';
    std::cout << "Temporary Block: " << temporaryBlock << '\n';
}

void analyzeLoginAttempt(int attemptCount, int successfulCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount,
                         double& successPercent, double&failurePercent,
                         std::string& commonFailure, std::string& securityStatus, std::string& temporaryBlock)
{
    int totalFailure = wrongPasswordCount + unknownUsernameCount + lockedAccountCount;
    successPercent = calculatePercentage(successfulCount, attemptCount);
    failurePercent = calculatePercentage(totalFailure, attemptCount);
    commonFailure = determineCommonFailure(wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
    securityStatus = determineSecurityStatus(failurePercent);
    temporaryBlock = temporaryBlockDecision(failurePercent, lockedAccountCount);
}

// ============ Core Logic ============
std::string determineSecurityStatus(double failurePercent)
{
    if (failurePercent == 0.0) return "Normal";
    else if (failurePercent < 50.0) return "Warning";
    else return "High Risk";
}

std::string temporaryBlockDecision(double failurePercent, int lockedAccountCount)
{
    if (lockedAccountCount >= 3 || failurePercent >= 75.0) return "Yes";
    else return "No";
}

std::string determineCommonFailure(int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount)
{
    int maxCount = wrongPasswordCount;
    if (unknownUsernameCount > maxCount) maxCount = unknownUsernameCount;
    if (lockedAccountCount > maxCount) maxCount = lockedAccountCount;
    if (maxCount == 0) return "None";
    int ties = 0;
    if (wrongPasswordCount == maxCount) ties++;
    if (unknownUsernameCount == maxCount) ties++;
    if (lockedAccountCount == maxCount) ties++;
    if (ties > 1) return "Tie";
    else if (wrongPasswordCount == maxCount) return "Wrong Password";
    else if (unknownUsernameCount == maxCount) return "Unknown Username";
    else return "Locked Account";
}

// ============ Utility  ============
double calculatePercentage(int count, int total)
{
    if (total <= 0) return 0.0;
    return (count * 100.0) / total;
}

void clearTerminal()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}