#include <iostream>
#include <string>
#include <cstdlib>

// ============ Declaration ============
void clearTerminal();
void invalidInput();
void exitSystem();
// ---
// ---
void displayMainMenu();
void loginAttemptSystem();

// ============ Controller ============
int main()
{   
    loginAttemptSystem();
    return 0;
}

void loginAttemptSystem()
{
    int selectMainMenu{};
    do
    {
        displayMainMenu(selectMainMenu);
        if (selectMainMenu == 1)
        {

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
    
}

void displayMainMenu(int selectMainMenu)
{
    std::cout << "\n============ Security Login Analyzer ============\n"
              << "1. Analyze Login Attempts\n"
              << "2. Exit\n"
              << "\nSelect option: ";
    std::cin >> selectMainMenu;
}

// ============ Core Logic ============

// ============ Utilities ============
void clearTerminal()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void invalidInput()
{
    std::cout << "\nInvalid Input. Try Again\n";
}

void exitSystem()
{
    std::cout << "\nExited Sucessfully.\n";
}