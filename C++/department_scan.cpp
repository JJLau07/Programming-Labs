#include <iostream>

// Department Scan Program
int main()
{
    int departmentCount{};
    int devicesPerDepartment{};

    std::cout << "Departments: ";
    std::cin >> departmentCount;

    std::cout << "Devices per department: ";
    std::cin >> devicesPerDepartment;

    int totalScanned{};

    for (int department = 1; department <= departmentCount; department++)
    {
        std::cout << "\nDepartment " << department << '\n';

        for (int devices = 1; devices <= devicesPerDepartment; devices++)
        {
            std::cout << "Scanning device " << devices << '\n';
            totalScanned++;
        }
    }

    std::cout << "\nTotal devices scanned: " << totalScanned << '\n';

    return 0;
}