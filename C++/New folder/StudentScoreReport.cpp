#include <iostream>
#include <string>

int main()
{
    std::string name;
    int quizScore;
    int assignmentScore;
    int examScore;

    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your quiz score: ";
    std::cin >> quizScore;

    std::cout << "Enter your assignment score: ";
    std::cin >> assignmentScore;

    std::cout << "Enter your exam score: ";
    std::cin >> examScore;

    int totalScore = quizScore + assignmentScore + examScore;

    std::cout << std::endl;
    
    std::cout << "======================================" << std::endl;
    std::cout << "         STUDENT SCORE REPORT         " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Name             : " << name << std::endl;
    std::cout << "Quiz Score       : " << quizScore << std::endl;
    std::cout << "Assignment Score : " << assignmentScore << std::endl;
    std::cout << "Exam Score       : " << examScore << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Total Score      : " << totalScore << std::endl;
    std::cout << "======================================" << std::endl;

    return 0;
}