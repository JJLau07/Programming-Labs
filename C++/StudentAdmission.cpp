#include <iostream>
#include <string>
int main()
{
    std::string name;
    int age;
    int examScore;
    int hasDocument;

    std::cout << "Enter Your Name: ";
    std::getline (std::cin, name);
    std::cout << "Enter Your Age: ";
    std::cin >> age;
    std::cout << "Enter Your Entrance Exam Score: ";
    std::cin >> examScore;
    std::cout << "Complete Documents? (1=Yes, 0=No): ";
    std::cin >> hasDocument;

    std::cout << std::endl;

    std::cout << "==============================" << std::endl;
    std::cout << "   STUDENT ADMISSION RESULT   " << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << std::endl;
    std::cout << "Name      : " << name << std::endl;
    std::cout << "Age       : " << age << std::endl;
    std::cout << "Score     : " << examScore << std::endl;
    if (hasDocument == 1)
        {
            std::cout << "Documents : Complete" << std::endl;
        }
        else
        {
          std::cout << "Documents : Incomplete" << std::endl;
        }
    std::cout << std::endl;
    if (age <18)
        {
            std::cout << "Admission Status : Rejected" << std::endl;
            std::cout << "Reason: Applicant must be at least 18 years old." << std::endl;
        }
        else if (hasDocument == 0)
        {
            std::cout << "Admission Status : Rejected" << std::endl;
            std::cout << "Reason Incomplete Documents" << std::endl;
        }
        else if (examScore >= 90)
        {
            std::cout << "Performance : Excellent" << std::endl;
            std::cout << "Admission Status : Accepted" << std::endl;
        }
        else if (examScore >= 80)
        {
            std::cout << "Performance : Good" << std::endl;
            std::cout << "Admission Status : Accepted" << std::endl;
        }
        else if (examScore >= 75)
        {
            std::cout << "Performance : Passed" << std::endl;
            std::cout << "Admission Status : Waitlisted" << std::endl;
        }
        else
        {
            std::cout << "Admission Status : Rejected" << std::endl;
            std::cout << "Reason : Entrance Exam Failed" << std::endl;
        }

    return 0;
}