#include <iostream>

// Alert Sum Program
int calculateTotal(int first, int second)
{
    int sum = first + second;
    return sum;
}

int main()
{
    int first{};
    int second{};

    std::cout << "First alert: ";
    std::cin >> first;
    std::cout << "Second alert: ";
    std::cin >> second;

    int total = calculateTotal(first, second);

    std::cout << "\nResults: \n";
    std::cout << "First alert count: " << first << '\n';
    std::cout << "Second alert count: " << second << '\n';
    std::cout << "Total alerts: " << total << '\n';

    return 0;
}