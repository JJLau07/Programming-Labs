#include <iostream>

// Login Monitoring Program
int main()
{
    int failedLoginAttempts{2};
    int blockedAccounts{1};

    std::cout << "Initial failed login attempts: "
              << failedLoginAttempts << '\n';
    std::cout << "Initial blocked accounts: "
              << blockedAccounts << '\n';

    failedLoginAttempts = 6;
    std::cout << "Updated failed login attempts: "
              << failedLoginAttempts << '\n';
    blockedAccounts = 3;
    std::cout << "Updated blocked accounts: "
              << blockedAccounts << '\n';

    return 0;
}