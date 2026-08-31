#include <iostream>
#include <string>
#include <cstdlib>

//Security Access Control Program
int main()
{   
    std::string expectedUsername{};
    std::string expectedPassword{};
    bool createAccountSession = false;
    bool loginSession = false;
    bool securitySystem = false;
    bool running = true;

    while (running)
    {
        // Main Menu
        int selectMenu{};
        // Clear Terminal
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif

        std::cout << "\nWelcome User! Please select your option below.\n";
        std::cout << "\n===== Security Access Control =====\n";
        std::cout << "1. Login\n"
                << "2. Create Credentials\n"
                << "3. Exit\n"
                << "\nSelect option: ";
        std::cin >> selectMenu;

        // Clear Terminal
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif

        if (selectMenu == 1)
        {
            loginSession = true;
        }
        else if (selectMenu == 2)
        {
            createAccountSession = true;
        }
        else if (selectMenu == 3)
        {
            std::cout << "\nExited Succesfully. Thank you for using the program!\n";
            return 0;
        }
        else
        {
            std::cout << "\nInvalid Input. Please try again.\n";
            continue;
        }

        // ===== Setup Username & Password =====
        accountSetupLabel:
        if (createAccountSession)
        {
            int selectOptionAccounts{};
            const std::string returnMenu = "0";
            const std::string returnLoginSession = "1";

            std::cout << "\n1. Login\n";
            std::cout << "0. Back to Menu\n";
            std::cout << "\n===== Setup Credentials =====\n";
            std::cout << "Set Username: ";
            std::cin >> expectedUsername;
            if (expectedUsername == returnMenu)
            {
                createAccountSession = false;
                continue;
            }
            if (expectedUsername == returnLoginSession)
            {
                // Clear Terminal
                #ifdef _WIN32
                    std::system("cls");
                #else
                    std::system("clear");
                #endif
                createAccountSession = false;
                loginSession = true;
                goto loginSessionLabel;
            }

            std::cout << "Set Password: ";
            std::cin >> expectedPassword;
            if (expectedPassword == returnMenu)
            {
                createAccountSession = false;
                continue;
            }
            if (expectedPassword == returnLoginSession)
            {
                // Clear Terminal
                #ifdef _WIN32
                    std::system("cls");
                #else
                    std::system("clear");
                #endif

                createAccountSession = false;
                loginSession = true;
                goto loginSessionLabel;
            }

            // Clear Terminal
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif

            std::cout << "\nCredentials Created Successfuly.\n";
            std::cout << "\n0. Back to Menu\n"
                      << "Select option: ";
            std::cin >> selectOptionAccounts;

            if (selectOptionAccounts == 0)
            {
                createAccountSession = false;
                continue;
            }
        }

        // ===== Login Session =====
        loginSessionLabel:
        if (loginSession)
        {
            const int maxAttempt = 1;
            const std::string returnMenu = "0";
            const std::string returnCreateAccount = "1";

            for (int attempt = 3; attempt >= maxAttempt; attempt--)
            {
                std::string inputUsername{};
                std::string inputPassword{};

                std::cout << "\n1. Create Credentials\n";
                std::cout << "0. Back to Menu\n";
                std::cout << "\n====== Login ======\n";
                std::cout << "Attempts left: " << attempt << '\n';
                std::cout << "Username: ";
                std::cin >> inputUsername;
                if (inputUsername == returnMenu)
                {
                    loginSession = false;
                    break;
                }
                if (inputUsername == returnCreateAccount)
                {
                    // Clear Terminal
                    #ifdef _WIN32
                        std::system("cls");
                    #else
                        std::system("clear");
                    #endif

                    loginSession = false;
                    createAccountSession = true;
                    goto accountSetupLabel;
                }

                std::cout << "Password: ";
                std::cin >> inputPassword;
                if (inputPassword == returnMenu)
                {
                    loginSession = false;
                    break;
                }
                if (inputPassword == returnCreateAccount)
                {
                    // Clear Terminal
                    #ifdef _WIN32
                        std::system("cls");
                    #else
                        std::system("clear");
                    #endif

                    loginSession = false;
                    createAccountSession = true;
                    goto accountSetupLabel;
                }

                // Clear Terminal
                #ifdef _WIN32
                    std::system("cls");
                #else
                    std::system("clear");
                #endif

                if (inputUsername == expectedUsername && inputPassword == expectedPassword)
                {
                    std::cout << "\nLogin Successfuly\n";
                    securitySystem = true;
                    break;
                }
                else
                {
                    std::cout << "\n*** Incorrect Username or Password ***\n";

                    if (attempt == maxAttempt)
                    {
                    std::cout << "\nAccess Blocked! Attempt Limit Reached.\n";
                    }
                }
            }
            loginSession = false;
        }

        // Sub-Menu
        if (securitySystem)
        {
            int selectMenuSecurity{};
            do
            {
                int back{};

                std::cout << "\n======== Security ========\n"
                        << "1. View Security Status\n"
                        << "2. View Access Level\n"
                        << "3. View Credentials\n"
                        << "4. Back to Menu\n"
                        << "5. Log Out\n"
                        << "\nSelect option: ";
                std::cin >> selectMenuSecurity;

                // Clear Terminal
                #ifdef _WIN32
                    std::system("cls");
                #else
                    std::system("clear");
                #endif

                if (selectMenuSecurity == 1)
                {
                    std::cout << "\n0. back\n";
                    std::cout << "\n===== Security Status =====\n";
                    std::cout << "System Status: Secure\n";
                    std::cout << " \n";
                    std::cin >> back;
                    if (back == 0)
                    {
                        // Clear Terminal
                        #ifdef _WIN32
                            std::system("cls");
                        #else
                            std::system("clear");
                        #endif
                        continue;
                    }
                    else
                    {
                        std::cout << "\nnvalid Input\n";
                    }
                }
                else if (selectMenuSecurity == 2)
                {
                    std::cout << "\n0. back\n";
                    std::cout << "\n===== Access Level Status =====\n";
                    std::cout << "Access Level: Authorized\n";
                    std::cout << " \n";
                    std::cin >> back;
                    if (back == 0)
                    {
                        // Clear Terminal
                        #ifdef _WIN32
                            std::system("cls");
                        #else
                            std::system("clear");
                        #endif
                        continue;
                    }
                    else
                    {
                        std::cout << "\nnvalid Input\n";
                    }
                }
                else if (selectMenuSecurity == 3)
                {
                    std::cout << "\n0. back\n";
                    std::cout << "\n===== Credentials =====\n";
                    std::cout << "Username: " << expectedUsername << '\n';
                    std::cout << "Password: " << expectedPassword << '\n';
                    std::cout << " \n";
                    std::cin >> back;
                    if (back == 0)
                    {
                        // Clear Terminal
                        #ifdef _WIN32
                            std::system("cls");
                        #else
                            std::system("clear");
                        #endif
                        continue;
                    }
                    else
                    {
                        std::cout << "\nnvalid Input\n";
                    }
                }
                else if (selectMenuSecurity == 4)
                {
                    securitySystem = false;
                    break;
                }
                else if (selectMenuSecurity == 5)
                {
                    std::cout << "\nLogged out successfully\n";
                    securitySystem = false;
                }
                else
                {
                    std::cout << "\nInvalid Input. Please try again\n";
                }

            } while (selectMenuSecurity != 4);
        }

    }
    return 0;
}