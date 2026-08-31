#include <iostream>
#include <string>

// Threat Classifier Program
int main()
{
    double threatScore{};

    std::string threatLevel{};
    bool validScore{true};
    bool immediateResponse{false};

    std::cout << "Enter threat score: ";
    std::cin >> threatScore;

    if (threatScore < 0.0 || threatScore > 10.0)
    {
        validScore = false;
        threatLevel = "Invalid";
    }
    else if (threatScore >= 9.0)
    {
        threatLevel = "Critical";
        immediateResponse = true;
    }
    else if (threatScore >= 7.0)
    {
        threatLevel = "High";
    }
    else if (threatScore >= 4.0)
    {
        threatLevel = "Medium";
    }
    else
    {
        threatLevel = "Low";
    }

    std::cout << std::boolalpha;
    std::cout << "\nThreat Classification Report\n";
    std::cout << "Valid score: " << validScore << '\n';
    std::cout << "Threat level: " << threatLevel << '\n';
    std::cout << "Immediate response: " << immediateResponse << '\n';

    return 0;
}