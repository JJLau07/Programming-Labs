#include <iostream>
#include <string>
#include <cstdlib>

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
            // clear terminal
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif

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
            int threatNormalCount{};
            int threatSuspiciousCount{};
            int threatMaliciousCount{};
            int threatLowCount{};
            int threatMediumCount{};
            int threatHighCount{};
            int threatCriticalCount{};

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
                if (threatCategoryCount == 1) threatNormalCount++;
                else if (threatCategoryCount == 2) threatSuspiciousCount++;
                else if (threatCategoryCount == 3) threatMaliciousCount++;

                // Severity Count
                if (threatSeverityCount == 1) threatLowCount++;
                else if (threatSeverityCount == 2) threatMediumCount++;
                else if (threatSeverityCount == 3) threatHighCount++;
                else if (threatSeverityCount == 4) threatCriticalCount++;
            }

            // Summary Section
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif

            double normalPercent = threatNormalCount * 100.0 / eventCount;
            double suspiciousPercent = threatSuspiciousCount * 100.0 / eventCount;
            double maliciousPercent = threatMaliciousCount * 100.0 / eventCount;
            double highCriticalPercent = (threatHighCount + threatCriticalCount) * 100.0 / eventCount;
            
            std::string commonThreat{};
            std::string commonSeverity{};
            std::string threatLevel{};
            std::string actionRequired{};
            std::string emergencyResponse{};
            std::string systemAction{};

            // Common Threat
            int maxThreatCount = threatNormalCount;
            if (threatSuspiciousCount > maxThreatCount) maxThreatCount = threatSuspiciousCount;
            if (threatMaliciousCount > maxThreatCount) maxThreatCount = threatMaliciousCount;

            int threatTies = 0;
            if (threatNormalCount == maxThreatCount) threatTies++;
            if (threatSuspiciousCount == maxThreatCount) threatTies++;
            if (threatMaliciousCount == maxThreatCount) threatTies++;
           
            if (threatTies > 1) commonThreat = "Tie";
            else if (threatNormalCount == maxThreatCount) commonThreat = "Normal";
            else if (threatSuspiciousCount == maxThreatCount) commonThreat = "Suspicious";
            else if (threatMaliciousCount == maxThreatCount) commonThreat = "Malicious";

            // Common Severity
            int maxSeverityCount = threatLowCount;
            if (threatMediumCount > maxSeverityCount) maxSeverityCount = threatMediumCount;
            if (threatHighCount > maxSeverityCount) maxSeverityCount = threatHighCount;
            if (threatCriticalCount > maxSeverityCount) maxSeverityCount = threatCriticalCount;

            int severityTies = 0;
            if (threatLowCount == maxSeverityCount) severityTies++;
            if (threatMediumCount == maxSeverityCount) severityTies++;
            if (threatHighCount == maxSeverityCount) severityTies++;
            if (threatCriticalCount == maxSeverityCount) severityTies++;

            if (severityTies > 1) commonSeverity = "Tie";
            else if (threatLowCount == maxSeverityCount) commonSeverity = "Low";
            else if (threatMediumCount == maxSeverityCount) commonSeverity = "Medium"; 
            else if (threatHighCount == maxSeverityCount) commonSeverity = "High";
            else if (threatCriticalCount == maxSeverityCount) commonSeverity = "Critical";

            // Threat Level
            if (maliciousPercent >= 50.0 || threatCriticalCount >= 3) threatLevel = "Critical";
            else if (maliciousPercent > 0.0)
            {
                if (highCriticalPercent < 50.0)
                {
                    threatLevel = "Medium";
                }
                else if (highCriticalPercent >= 50.0)
                {
                    threatLevel = "High";
                }
            }
            else if (maliciousPercent == 0.0) threatLevel = "Low";

            // Emergency Response
            if (threatMaliciousCount >= 3 || threatCriticalCount >= 3 || maliciousPercent >= 75.0) emergencyResponse = "Required";
            else emergencyResponse = "Not Required";

            // System Action
            if (emergencyResponse == "Required") systemAction = "Isolate and Investigate";
            else systemAction = "Continue Monitoring";

            // Action Required
            if (emergencyResponse == "Required") actionRequired = "!!! Warning: Action Needed !!!\n";

            // Results (Print)
            std::cout << "\n============ Results ============\n";

            std::cout << "\nThreat Categories\n";
            std::cout << "  Total Normal Threats     : " << threatNormalCount << '\n';
            std::cout << "  Total Suspicious Threats : " << threatSuspiciousCount << '\n';
            std::cout << "  Total Malicious Threats  : " << threatMaliciousCount << '\n';

            std::cout << "\nSeverity Levels\n";
            std::cout << "  Total Low Severity       : " << threatLowCount << '\n';
            std::cout << "  Total Medium Severity    : " << threatMediumCount << '\n';
            std::cout << "  Total High Severity      : " << threatHighCount << '\n';
            std::cout << "  Total Critical Severity  : " << threatCriticalCount << '\n';

            std::cout << "\nPercentages\n";
            std::cout << "  Normal          : " << normalPercent << "%\n";
            std::cout << "  Suspicious      : " << suspiciousPercent << "%\n";
            std::cout << "  Malicious       : " << maliciousPercent << "%\n";
            std::cout << "  High & Critical : " << highCriticalPercent << "%\n";

            std::cout << "\nMost Common Threat   : " << commonThreat << '\n';
            std::cout << "Most Common Severity : " << commonSeverity << '\n';
            std::cout << "Threat Level         : " << threatLevel << '\n';
            std::cout << "\n";
            std::cout << actionRequired;
            std::cout << "Emergency Response   : " << emergencyResponse << '\n';
            std::cout << "System Action        : " << systemAction << '\n';
            
            std::cout << "\n=================================\n";
            std::cout << "\nReturning to Menu...\n";
            std::cout << " \n";
        }
        else if (selectMainMenu == 2)
        {
            // clear terminal
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif
            // Exit Message
            std::cout << "\nExited Successfully.\n";
        }
        else 
        {
            // clear terminal
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif
            // Invalid Message
            std::cout << "\nInvalid Input. Try Again.\n";
        }
    } while (selectMainMenu != 2);
    
    return 0;
} 