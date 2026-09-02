#include <iostream>
#include <string>
#include <cstdlib>

// ============ Declaration ============
void clearTerminal();
void invalidInput();
void exitSystem();
// ---
// ---
void analyzeLoginAttempts();
void displayMainMenu(int& selectMainMenu);

// ============ Controller ============
int main()
{   
    int selectMainMenu{};
    do
    {
        displayMainMenu(selectMainMenu);
        if (selectMainMenu == 1)
        {
            analyzeLoginAttempts();
        }
        else if (selectMainMenu == 2)
        {
            clearTerminal();
            exitSystem();
        }
        else{
            clearTerminal();
            invalidInput();
        }
    } while (selectMainMenu !=2);

    return 0;
}

void displayMainMenu(int& selectMainMenu)
{
    std::cout << "\n============ Security Login Analyzer ============\n"
              << "1. Analyze Login Attempts\n"
              << "2. Exit\n"
              << "\nSelect option: ";
    std::cin >> selectMainMenu;
}

void analyzeLoginAttempts()
{
    int loginCount;
    std::cout << "\nLogin attempts to be analyzed: ";
    std::cin >> loginCount;
    if (loginCount <= 0)
    {
        invalidInput();
        return;
    }
}

// ============ Core Logic ============

// ============ Utilities ============
void exitSystem()
{
    std::cout << "\nExited Sucessfully.\n";
}

void invalidInput()
{
    std::cout << "\nInvalid Input. Try Again\n";
}

void clearTerminal()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}