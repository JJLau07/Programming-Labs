#include <iostream>
#include <string>

int main()
{
    int score;

    std::cout << "What is Your Score: ";
    std::cin >> score;

    if (score >= 90)
        {
            std::cout << "Excellent";
        }
    else if (score >= 80)
        {
            std::cout << "Good";
        }
    else if (score >= 75)
        {
            std::cout << "Passed";
        }
    else
        {
            std::cout << "Failed";
        }
    return 0;
}