#include <iostream>
#include <string>
#include <cstdlib>

void clearTerminal()
{
    // clear terminal
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

struct resultVariables
{
    int threatNormalCount{};
    int threatSuspiciousCount{};
    int threatMaliciousCount{};
    int threatLowCount{};
    int threatMediumCount{};
    int threatHighCount{};
    int threatCriticalCount{};

    double normalPercent{};
    double suspiciousPercent{};
    double maliciousPercent{};
    double highCriticalPercent{};
    
    std::string commonThreat{};
    std::string commonSeverity{};
    std::string threatLevel{};
    std::string actionRequired{};
    std::string emergencyResponse{};
    std::string systemAction{};


};

void printResult(const resultVariables& res)
{   
    std::cout << "\n============ Results ============\n";

    std::cout << "\nThreat Categories\n";
    std::cout << "  Total Normal Threats     : " << res.threatNormalCount << '\n';
    std::cout << "  Total Suspicious Threats : " << res.threatSuspiciousCount << '\n';
    std::cout << "  Total Malicious Threats  : " << res.threatMaliciousCount << '\n';

    std::cout << "\nSeverity Levels\n";
    std::cout << "  Total Low Severity       : " << res.threatLowCount << '\n';
    std::cout << "  Total Medium Severity    : " << res.threatMediumCount << '\n';
    std::cout << "  Total High Severity      : " << res.threatHighCount << '\n';
    std::cout << "  Total Critical Severity  : " << res.threatCriticalCount << '\n';

    std::cout << "\nPercentages\n";
    std::cout << "  Normal          : " << res.normalPercent << "%\n";
    std::cout << "  Suspicious      : " << res.suspiciousPercent << "%\n";
    std::cout << "  Malicious       : " << res.maliciousPercent << "%\n";
    std::cout << "  High & Critical : " << res.highCriticalPercent << "%\n";

    std::cout << "\nMost Common Threat   : " << res.commonThreat << '\n';
    std::cout << "Most Common Severity : " << res.commonSeverity << '\n';
    std::cout << "Threat Level         : " << res.threatLevel << '\n';
    std::cout << "\n";
    std::cout << res.actionRequired;
    std::cout << "Emergency Response   : " << res.emergencyResponse << '\n';
    std::cout << "System Action        : " << res.systemAction << '\n';
    
    std::cout << "\n=================================\n";
    std::cout << "\nReturning to Menu...\n";
    std::cout << " \n";
}

// Security Threat Classifier Program
int main()
{   
    int selectMainMenu{};
    do
    {   
        // Main Menu Section
        std::cout << "\n====== Security Threat Classifier ======\n"
                  << "1. Start Threat Classification\n"
                  << "2. Exit\n"
                  << "\nSelect option: ";
        std::cin >> selectMainMenu;

        if (selectMainMenu == 1)
        {   
            resultVariables result;

            // Clear Terminal
            clearTerminal();

            // Event Count Section
            int eventCount{};
            std::cout << "\nSecurity events to be classified: ";
            std::cin >> eventCount;
            if (eventCount <= 0)
            {
                std::cout << "\nInvalid Input. Try Again.\n";
                continue;
            }

            // Threat Count Section
            std::cout << "\nCategory: 1-Normal 2-Suspicious 3-Malicious\n";
            std::cout << "Severity Level: 1-Low 2-Medium 3-High 4-Critical\n";
            
            for (int threatNum = 1; threatNum <= eventCount; threatNum++)
            {
                int threatCategoryCount{};
                int threatSeverityCount{};
                std::cout << "\nThreat " << threatNum << " Category: ";
                std::cin >> threatCategoryCount;
                std::cout << "Threat " << threatNum << " Severity: ";
                std::cin >> threatSeverityCount;

                // Invalid Input
                if (threatCategoryCount < 1 || threatCategoryCount > 3 || threatSeverityCount < 1 || threatSeverityCount > 4)
                {
                    std::string invalidType{};
                    std::string input{};
                    if (threatCategoryCount < 1 || threatCategoryCount > 3) 
                    {
                        invalidType = "Category"; 
                        input = "1-Normal 2-Suspicious 3-Malicious\n";
                    }
                    else if (threatSeverityCount < 1 || threatSeverityCount > 4) 
                    {
                        invalidType = "Severity";
                        input = "1-Low 2-Medium 3-High 4-Critical\n";
                    }

                    std::cout << "\nInvalid " << invalidType << " Input. Try Again.\n";
                    std::cout << invalidType << " options: " << input;
                    threatNum--;
                    continue;
                }

                // Category Count
                if (threatCategoryCount == 1) result.threatNormalCount++;
                else if (threatCategoryCount == 2) result.threatSuspiciousCount++;
                else if (threatCategoryCount == 3) result.threatMaliciousCount++;

                // Severity Count
                if (threatSeverityCount == 1) result.threatLowCount++;
                else if (threatSeverityCount == 2) result.threatMediumCount++;
                else if (threatSeverityCount == 3) result.threatHighCount++;
                else if (threatSeverityCount == 4) result.threatCriticalCount++;
            }

            clearTerminal();

            result.normalPercent = result.threatNormalCount * 100.0 / eventCount;
            result.suspiciousPercent = result.threatSuspiciousCount * 100.0 / eventCount;
            result.maliciousPercent = result.threatMaliciousCount * 100.0 / eventCount;
            result.highCriticalPercent = (result.threatHighCount + result.threatCriticalCount) * 100.0 / eventCount;

            // Common Threat
            int maxThreatCount = result.threatNormalCount;
            if (result.threatSuspiciousCount > maxThreatCount) maxThreatCount = result.threatSuspiciousCount;
            if (result.threatMaliciousCount > maxThreatCount) maxThreatCount = result.threatMaliciousCount;

            int threatTies = 0;
            if (result.threatNormalCount == maxThreatCount) threatTies++;
            if (result.threatSuspiciousCount == maxThreatCount) threatTies++;
            if (result.threatMaliciousCount == maxThreatCount) threatTies++;
           
            if (threatTies > 1) result.commonThreat = "Tie";
            else if (result.threatNormalCount == maxThreatCount) result.commonThreat = "Normal";
            else if (result.threatSuspiciousCount == maxThreatCount) result.commonThreat = "Suspicious";
            else if (result.threatMaliciousCount == maxThreatCount) result.commonThreat = "Malicious";

            // Common Severity
            int maxSeverityCount = result.threatLowCount;
            if (result.threatMediumCount > maxSeverityCount) maxSeverityCount = result.threatMediumCount;
            if (result.threatHighCount > maxSeverityCount) maxSeverityCount = result.threatHighCount;
            if (result.threatCriticalCount > maxSeverityCount) maxSeverityCount = result.threatCriticalCount;

            int severityTies = 0;
            if (result.threatLowCount == maxSeverityCount) severityTies++;
            if (result.threatMediumCount == maxSeverityCount) severityTies++;
            if (result.threatHighCount == maxSeverityCount) severityTies++;
            if (result.threatCriticalCount == maxSeverityCount) severityTies++;

            if (severityTies > 1) result.commonSeverity = "Tie";
            else if (result.threatLowCount == maxSeverityCount) result.commonSeverity = "Low";
            else if (result.threatMediumCount == maxSeverityCount) result.commonSeverity = "Medium"; 
            else if (result.threatHighCount == maxSeverityCount) result.commonSeverity = "High";
            else if (result.threatCriticalCount == maxSeverityCount) result.commonSeverity = "Critical";

            // Threat Level
            if (result.maliciousPercent >= 50.0 || result.threatCriticalCount >= 3) result.threatLevel = "Critical";
            else if (result.maliciousPercent > 0.0)
            {
                if (result.highCriticalPercent < 50.0)
                {
                    result.threatLevel = "Medium";
                }
                else if (result.highCriticalPercent >= 50.0)
                {
                    result.threatLevel = "High";
                }
            }
            else if (result.maliciousPercent == 0.0) result.threatLevel = "Low";

            // Emergency Response
            if (result.threatMaliciousCount >= 3 || result.threatCriticalCount >= 3 || result.maliciousPercent >= 75.0) result.emergencyResponse = "Required";
            else result.emergencyResponse = "Not Required";

            // System Action
            if (result.emergencyResponse == "Required") result.systemAction = "Isolate and Investigate";
            else result.systemAction = "Continue Monitoring";

            // Action Required
            if (result.emergencyResponse == "Required") result.actionRequired = "!!! Warning: Action Needed !!!\n";

            printResult(result);
        }
        else if (selectMainMenu == 2)
        {
            // clear terminal
            clearTerminal();
            // Exit Message
            std::cout << "\nExited Successfully.\n";
        }
        else 
        {
            // clear terminal
            clearTerminal();
            // Invalid Message
            std::cout << "\nInvalid Input. Try Again.\n";
        }
    } while (selectMainMenu != 2);
    
    return 0;
} 