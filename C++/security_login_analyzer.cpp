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

void storeAnalysisHistory(int& historyCount, int loginCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount,
                     int& loginCount1, int& wrongPasswordCount1, int& unknownUsernameCount1, int& lockedAccountCount1,
                     int& loginCount2, int& wrongPasswordCount2, int& unknownUsernameCount2, int& lockedAccountCount2,
                     int& loginCount3, int& wrongPasswordCount3, int& unknownUsernameCount3, int& lockedAccountCount3);
void runAnalysisHistory(int historyCount,
                        int loginCount1, int wrongPasswordCount1, int unknownUsernameCount1, int lockedAccountCount1,
                        int loginCount2, int wrongPasswordCount2, int unknownUsernameCount2, int lockedAccountCount2,
                        int loginCount3, int wrongPasswordCount3, int unknownUsernameCount3, int lockedAccountCount3);
void printSingleHistory(int analysisNum, int loginCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount);
void printRecentAnalysis(int loginCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount);
void runAlertSummary(bool analyzedLoginAttempt, int loginCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount);
void printAnalysisResult(int loginCount, int successfulCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount);
void processLoginAttempt(int loginCount, int& successfulCount, int& wrongPasswordCount, int& unknownUsernameCount, int& lockedAccountCount);
void runLoginAttempt(bool& analyzedLoginAttempt, int& loginCount, int& wrongPasswordCount, int& unknownUsernameCount, int& lockedAccountCount,
                     int& historyCount,
                     int& loginCount1, int& wrongPasswordCount1, int& unknownUsernameCount1, int& lockedAccountCount1,
                     int& loginCount2, int& wrongPasswordCount2, int& unknownUsernameCount2, int& lockedAccountCount2,
                     int& loginCount3, int& wrongPasswordCount3, int& unknownUsernameCount3, int& lockedAccountCount3);
void displayMainMenu(int& selectMainMenu);
bool handleMainMenu(int selectMainMenu, bool& analyzedLoginAttempt, int& loginCount, int& wrongPasswordCount, int& unknownUsernameCount, int& lockedAccountCount,
                    int& historyCount,
                    int& loginCount1, int& wrongPasswordCount1, int& unknownUsernameCount1, int& lockedAccountCount1,
                    int& loginCount2, int& wrongPasswordCount2, int& unknownUsernameCount2, int& lockedAccountCount2,
                    int& loginCount3, int& wrongPasswordCount3, int& unknownUsernameCount3, int& lockedAccountCount3);

// ============ Controllers ============
int main()
{
    int selectMainMenu{};
    bool runLoop = true;
    bool analyzedLoginAttempt = false;
    int loginCount{};
    int wrongPasswordCount{};
    int unknownUsernameCount{};
    int lockedAccountCount{};
    int historyCount = 0;
    int loginCount1 = 0, wrongPasswordCount1 = 0, unknownUsernameCount1 = 0, lockedAccountCount1 = 0;
    int loginCount2 = 0, wrongPasswordCount2 = 0, unknownUsernameCount2 = 0, lockedAccountCount2 = 0;
    int loginCount3 = 0, wrongPasswordCount3 = 0, unknownUsernameCount3 = 0, lockedAccountCount3 = 0;

    do
    {
        displayMainMenu(selectMainMenu);
        runLoop = handleMainMenu(selectMainMenu, analyzedLoginAttempt, loginCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount, historyCount,
                                 loginCount1, wrongPasswordCount1, unknownUsernameCount1, lockedAccountCount1,
                                 loginCount2, wrongPasswordCount2, unknownUsernameCount2, lockedAccountCount2,
                                 loginCount3, wrongPasswordCount3, unknownUsernameCount3, lockedAccountCount3);


    } while (runLoop);

    return 0;
    
}

bool handleMainMenu(int selectMainMenu, bool& analyzedLoginAttempt, int& loginCount, int& wrongPasswordCount, int& unknownUsernameCount, int& lockedAccountCount,
                    int& historyCount,
                    int& loginCount1, int& wrongPasswordCount1, int& unknownUsernameCount1, int& lockedAccountCount1,
                    int& loginCount2, int& wrongPasswordCount2, int& unknownUsernameCount2, int& lockedAccountCount2,
                    int& loginCount3, int& wrongPasswordCount3, int& unknownUsernameCount3, int& lockedAccountCount3)
{
    clearTerminal();
    if (selectMainMenu == 1) 
    {
        runLoginAttempt(analyzedLoginAttempt, loginCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount,
                        historyCount,
                        loginCount1, wrongPasswordCount1, unknownUsernameCount1, lockedAccountCount1,
                        loginCount2, wrongPasswordCount2, unknownUsernameCount2, lockedAccountCount2,
                        loginCount3, wrongPasswordCount3, unknownUsernameCount3, lockedAccountCount3);
        return true;
    }
    else if (selectMainMenu == 2)
    {
        runAlertSummary(analyzedLoginAttempt, loginCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
        return true;
    }
    else if (selectMainMenu == 3)
    {
        runAnalysisHistory(historyCount,
                           loginCount1, wrongPasswordCount1, unknownUsernameCount1, lockedAccountCount1,
                           loginCount2, wrongPasswordCount2, unknownUsernameCount2, lockedAccountCount2,
                           loginCount3, wrongPasswordCount3, unknownUsernameCount3, lockedAccountCount3);
        return true;
    }
    else
    {
        if (selectMainMenu == 4)
        {
            exitSystem();
            return false;
        }
        else
        {
            invalidInput();
            return true;
        }
    }
}

void displayMainMenu(int& selectMainMenu)
{
    std::cout << "\n============ Security Login Analyzer ============\n"
              << "1. Analyze Login Attempts\n"
              << "2. Security Alert Summary\n"
              << "3. Analysis History\n"
              << "4. Exit\n"
              << "\nSelect option: ";
    std::cin >> selectMainMenu;
}
bool inputLoginCount(int& loginCount)
{
    std::cout << "Login attempts to be analyzed: ";
    std::cin >> loginCount;

    if (loginCount <= 0)
    {
        invalidInput();
        return false;
    }
    return true;
}

void storeAnalysisHistory(int& historyCount, int loginCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount,
                     int& loginCount1, int& wrongPasswordCount1, int& unknownUsernameCount1, int& lockedAccountCount1,
                     int& loginCount2, int& wrongPasswordCount2, int& unknownUsernameCount2, int& lockedAccountCount2,
                     int& loginCount3, int& wrongPasswordCount3, int& unknownUsernameCount3, int& lockedAccountCount3)
{
    if (historyCount == 0)
    {
        loginCount1 = loginCount;
        wrongPasswordCount1 = wrongPasswordCount;
        unknownUsernameCount1 = unknownUsernameCount;
        lockedAccountCount1 = lockedAccountCount;
        historyCount = 1;
    }
    else if (historyCount == 1)
    {
        loginCount2 = loginCount;
        wrongPasswordCount2 = wrongPasswordCount;
        unknownUsernameCount2 = unknownUsernameCount;
        lockedAccountCount2 = lockedAccountCount;
        historyCount = 2;
    }
    else if (historyCount == 2)
    {
        loginCount3 = loginCount;
        wrongPasswordCount3 = wrongPasswordCount;
        unknownUsernameCount3 = unknownUsernameCount;
        lockedAccountCount3 = lockedAccountCount;
        historyCount = 3;
    }
    else
    {
        loginCount1 = loginCount2; wrongPasswordCount1 = wrongPasswordCount2; unknownUsernameCount1 = unknownUsernameCount2; lockedAccountCount1 = lockedAccountCount2;
        loginCount2 = loginCount3; wrongPasswordCount2 = wrongPasswordCount3; unknownUsernameCount2 = unknownUsernameCount3; lockedAccountCount2 = lockedAccountCount3;
        loginCount3 = loginCount; wrongPasswordCount3 = wrongPasswordCount; unknownUsernameCount3 = unknownUsernameCount; lockedAccountCount3 = lockedAccountCount;
    }

}

void runLoginAttempt(bool& analyzedLoginAttempt, int& loginCount, int& wrongPasswordCount, int& unknownUsernameCount, int& lockedAccountCount,
                     int& historyCount,
                     int& loginCount1, int& wrongPasswordCount1, int& unknownUsernameCount1, int& lockedAccountCount1,
                     int& loginCount2, int& wrongPasswordCount2, int& unknownUsernameCount2, int& lockedAccountCount2,
                     int& loginCount3, int& wrongPasswordCount3, int& unknownUsernameCount3, int& lockedAccountCount3)
{
    int successfulCount{};
    wrongPasswordCount = 0;
    unknownUsernameCount = 0;
    lockedAccountCount = 0;

    if (!inputLoginCount(loginCount)) return;
    processLoginAttempt(loginCount, successfulCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
    clearTerminal();
    printAnalysisResult(loginCount, successfulCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
    analyzedLoginAttempt = true;

    storeAnalysisHistory(historyCount, loginCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount,
                         loginCount1, wrongPasswordCount1, unknownUsernameCount1, lockedAccountCount1,
                         loginCount2, wrongPasswordCount2, unknownUsernameCount2, lockedAccountCount2,
                         loginCount3, wrongPasswordCount3, unknownUsernameCount3, lockedAccountCount3);
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

void printAnalysisResult(int loginCount, int successfulCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount)
{   
    int totalFailure = wrongPasswordCount + unknownUsernameCount + lockedAccountCount;
    double successPercent = calculatePercent(successfulCount, loginCount);
    double failurePercent = calculatePercent(totalFailure, loginCount);
    std::string commonFailure = determineCommonFailure (wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
    std::string securityStatus = determineSecurityStatus(failurePercent);
    std::string temporaryBlock = determineTemporaryBlock(lockedAccountCount, failurePercent);

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
    std::cout << "=========================================\n";
    std::cout << "\nReturning to Main Menu...\n";
}

void runAlertSummary(bool analyzedLoginAttempt, int loginCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount)
{   
    if (!analyzedLoginAttempt)
    {
        std::cout << "\nNo login analysis has been performed yet.\n";
        return;
    }
    printRecentAnalysis(loginCount, wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
}

void printRecentAnalysis(int loginCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount)
{
    int totalFailure = wrongPasswordCount + unknownUsernameCount + lockedAccountCount;
    double failurePercent = calculatePercent(totalFailure, loginCount);
    std::string commonFailure = determineCommonFailure (wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
    std::string securityStatus = determineSecurityStatus(failurePercent);
    std::string temporaryBlock = determineTemporaryBlock(lockedAccountCount, failurePercent);
    
    std::cout << "\n====== Recent Login Analysis Report ======\n";
    std::cout << "Most Common Failure : " << commonFailure << '\n';
    std::cout << "Security Status     : " << securityStatus << '\n';
    std::cout << "Temporary Block     : " << temporaryBlock << '\n';
    std::cout << "==========================================\n";
    std::cout << "\nReturning to Main Menu...\n";
}

void printSingleHistory(int analysisNum, int loginCount, int wrongPasswordCount, int unknownUsernameCount, int lockedAccountCount)
{   
    int totalFailure = wrongPasswordCount + unknownUsernameCount + lockedAccountCount;
    double failurePercent = calculatePercent(totalFailure, loginCount);
    std::string commonFailure = determineCommonFailure (wrongPasswordCount, unknownUsernameCount, lockedAccountCount);
    std::string securityStatus = determineSecurityStatus(failurePercent);
    std::string temporaryBlock = determineTemporaryBlock(lockedAccountCount, failurePercent);

    std::cout << "\nAnalysis #" << analysisNum << '\n';
    std::cout << "  Total Attempts      : " << loginCount << '\n';
    std::cout << "  Wrong Passwords     : " << wrongPasswordCount << '\n';
    std::cout << "  Unknown Usernames   : " << unknownUsernameCount << '\n';
    std::cout << "  Locked Accounts     : " << lockedAccountCount << '\n';
    std::cout << "  Most Common Failure : " << commonFailure << '\n';
    std::cout << "  Security Status     : " << securityStatus << '\n';
    std::cout << "  Temporary Block     : " << temporaryBlock << '\n';
    std::cout << "======================================\n"; 
    std::cout << "\nReturning to Main Menu...\n"; 
}

void runAnalysisHistory(int historyCount,
                        int loginCount1, int wrongPasswordCount1, int unknownUsernameCount1, int lockedAccountCount1,
                        int loginCount2, int wrongPasswordCount2, int unknownUsernameCount2, int lockedAccountCount2,
                        int loginCount3, int wrongPasswordCount3, int unknownUsernameCount3, int lockedAccountCount3)
{
    if (historyCount == 0)
    {
        std::cout << "\nNo login analysis has been performed yet.\n";
        return;
    }
    std::cout << "\n========== Analysis History ==========";
    if (historyCount >= 1) printSingleHistory(1, loginCount1, wrongPasswordCount1, unknownUsernameCount1, lockedAccountCount1);
    if (historyCount >= 2) printSingleHistory(2, loginCount2, wrongPasswordCount2, unknownUsernameCount2, lockedAccountCount2);
    if (historyCount >= 3) printSingleHistory(3, loginCount3, wrongPasswordCount3, unknownUsernameCount3, lockedAccountCount3);
    if (historyCount >= 3)
    {
        std::cout << "\n!!! Note: Analysis History Storage Full !!!\n";
        return;
    }
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