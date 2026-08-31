#include <iostream>
#include <string>
#include <cstdlib>

// Intrusion Detection Analyzer Program
int main()
{   
    int selectMainMenu{};
    do
    {
        std::cout << "\n====== Intrusion Detection Analyzer ======\n"
                  << "1. Start Intrusion Analysis\n"
                  << "2. Exit\n"
                  << "\nSelect option: ";
        std::cin >> selectMainMenu;

        if (selectMainMenu == 1)
        {  
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif

            int activityCount{};
            int normalTrafficCount{};
            int failedLoginCount{};
            int portScanCount{};
            int malwareDetectedCount{};
            int unauthorizedAccessCount{};
            int suspicious{};
            std::string commonActivity{};
            std::string threatLevel{};

            std::cout << "\nNetwork Activity Records to be Analyzed: ";
            std::cin >> activityCount;

            if (activityCount <= 0)
            {
                std::cout << "\nInvalid Input. Try Again\n";
                continue;
            }
            
            std::cout << "Activity Type: 1-Normal Traffic 2-Failed Login 3-Port Scan 4-Malware Detected 5-Unauthorized Access\n";

            for (int record = 1; record <= activityCount; record++)
            {   
                int activityType{};
                std::cout << "Network Activity " << record << ": ";
                std::cin >> activityType;

                if (activityType == 1)
                {
                    normalTrafficCount++;
                }
                else if (activityType == 2)
                {
                    failedLoginCount++;
                }
                else if (activityType == 3)
                {
                    portScanCount++;
                }
                else if (activityType == 4)
                {
                    malwareDetectedCount++;
                }
                else if (activityType == 5)
                {
                    unauthorizedAccessCount++;
                }
                else
                {
                    std::cout << "\nInvalid Input. Try Again.\n";
                    record--;
                }
            }

            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif

            std::cout << "\n============ Results ============\n";
            std::cout << "Total Records: " << activityCount << '\n';
            std::cout << "Normal Traffic: " << normalTrafficCount << '\n';
            std::cout << "Failed Login: " << failedLoginCount << '\n';
            std::cout << "Port Scan: " << portScanCount << '\n';
            std::cout << "Malware Detected: " << malwareDetectedCount << '\n';
            std::cout << "Unauthorized Access: " << unauthorizedAccessCount << '\n';
            
            suspicious = (failedLoginCount + portScanCount + malwareDetectedCount + unauthorizedAccessCount);

            double normalTrafficPercent = normalTrafficCount * 100.0 / activityCount;
            double suspiciousActivityPercent = suspicious * 100.0 / activityCount;
            std::cout << "\n=========== Percentage ==========\n";
            std::cout << "Normal Traffic: " << normalTrafficPercent << "%\n";
            std::cout << "Suspicious Activities: " << suspiciousActivityPercent << "%\n";
            
            int maxCount = normalTrafficCount;
            if (failedLoginCount > maxCount) maxCount = failedLoginCount;
            if (portScanCount > maxCount) maxCount = portScanCount;
            if (malwareDetectedCount > maxCount) maxCount = malwareDetectedCount;
            if (unauthorizedAccessCount > maxCount) maxCount = unauthorizedAccessCount;

            int ties = 0;
            if (normalTrafficCount == maxCount) ties++;
            if (failedLoginCount == maxCount) ties++;
            if (portScanCount == maxCount) ties++;
            if (malwareDetectedCount == maxCount) ties++;
            if (unauthorizedAccessCount == maxCount) ties++;

            if (ties > 1)
            {
                commonActivity = "Tie";
            }
            else if (normalTrafficCount == maxCount)
            {
                commonActivity = "Normal Traffic";
            }
            else if (failedLoginCount == maxCount)
            {
                commonActivity = "Failed Login";
            }
            else if (portScanCount == maxCount)
            {
                commonActivity = "Port Scan";
            }
            else if (malwareDetectedCount == maxCount)
            {
                commonActivity = "Malware Detected";
            }
            else if (unauthorizedAccessCount == maxCount)
            {
                commonActivity = "Unauthorized Access";
            }
           
            std::cout << "\nMost Common Activity: " << commonActivity << '\n';

            if (suspiciousActivityPercent >= 50.0)
            {
                threatLevel = "High";
            }
            else if (suspiciousActivityPercent >= 25.0)
            {
                threatLevel = "Medium";
            }
            else if (suspiciousActivityPercent > 0)
            {
                threatLevel = "Low";
            }
            else 
            {
                threatLevel = "None";
            }
            std::cout << "Threat Level: " << threatLevel << '\n';

            std::string automaticResponse{};
            if (malwareDetectedCount >= 2 || unauthorizedAccessCount >= 2 || suspiciousActivityPercent >= 75.0)
            {
                automaticResponse = "Triggered";
            }
            else
            {
                automaticResponse = "Not Required";
            }
            std::cout << "Automatic Response: " << automaticResponse << '\n';

            std::string systemAction{};
            if (automaticResponse == "Triggered")
            {
                systemAction = "Isolate Network";
            }
            else
            {
                systemAction = "Continue Monitoring";
            }
           
            std::cout << "System Action: " << systemAction << '\n';
            std::cout << "\nReturning to Menu...\n";
        }
        else if (selectMainMenu == 2)
        {   
            #ifdef _WIN32
                std::system ("cls");
            #else
                std::system ("clear");
            #endif
            std::cout << "Exited Successfully.";
        }
        else 
        {
            std::cout << "\nInvalid Input. Try Again.\n";
        }

    } while (selectMainMenu != 2);
    return 0;
}