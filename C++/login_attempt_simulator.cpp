#include <iostream>
#include <string>
#include <cstdlib> // Required for std::system()

// Login Attempt Simulator Program
int main()
{   
    // Setting up Username & Password
    std::string expectedUsername{};
    std::string expectedPassword{};
    std::cout << "\nSet Username: ";
    std::cin >> expectedUsername;
    std::cout << "Set Password: ";
    std::cin >> expectedPassword;

    // Clear Terminal
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    std::cout << "\nUsername and Password is Set Successfully\n";
    bool loggedIn = false;
    const int maxAttempt = 1;

    // Login Process
    for (int attempt = 3; attempt >= maxAttempt; attempt--)
    {
        // Username & Password Input
        std::string inputUsername{};
        std::string inputPassword{};
        std::cout << "\nAttempts left: " << attempt << '\n';
        std::cout << "Enter Username: ";
        std::cin >> inputUsername;
        std::cout << "Enter Password: ";
        std::cin >> inputPassword;

        // Clear Terminal
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif

        if (inputUsername == expectedUsername && inputPassword == expectedPassword)
        {
            loggedIn = true;
            std::cout << "\nLogin Successfuly\n";
            break;
        }
        if (inputUsername != expectedUsername || inputPassword != expectedPassword)
        {
            std::cout << "\nIncorrect Username or Password\n";
        }
        if (attempt == maxAttempt)
        {
            std::cout << "\nAttempts limit reached. Access blocked for this session\n";
            break;
        }
    }

    // Session Menu
    if (loggedIn)
    {
        int selectedMenu{};
        do
        {   
            std::cout << "\nMenu\n";
            std::cout << "1. View Account\n"
                        << "2. Log out\n"
                        << "Select option: ";
            std::cin >> selectedMenu;

            // Clear Terminal
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif

            if (selectedMenu == 1)
            {
                std::cout << "\nAccount";
                std::cout << "\nUsername: " << expectedUsername << '\n';
            }
            else if (selectedMenu == 2)
            {
                std::cout << "\nLogged out successfuly\n";
            }
            else
            {
                std::cout << "\nInvalid Input\n";
            }

        } while (selectedMenu != 2);
    }

    return 0;
}