// Input.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Enter two numbers separated by a space: ";
    int x{};
    int y{};
    std::cin >> x >> y;
    std::cout << "You entered: " << x << " and " << y <<'\n';
    return 0;
}

