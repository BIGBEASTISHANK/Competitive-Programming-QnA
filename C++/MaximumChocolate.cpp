// Question:
// - Take input of number of rs you have
// - 1 Chocolate cost 1rs
// - 1 Chocolate can also cost 3 wrappes
// Find the maximum number of chocolates you can buy

// Include
#include <iostream>
#include "GlobalLogic.h"

// Variable
int rs{0};
const int costOfChocolate{1};
const int chocolateCWW{3};

// Declare function
void TakeInput();
int Calculation();

// Main functoin
int main()
{
    // Call function
    TakeInput();

    std::cout << "Total Number of chocolate you can buy are: " << Calculation() << ".";

    return 0;
}

// Logic to function
// TakeInput
void TakeInput()
{
    std::cout << "Enter amount you have in rs: ";
    std::cin >> rs;
    ClearInputBuffer();
}

// Calculation
int Calculation()
{
    // Variables
    int totalChocolate{0};
    int totalAvaWrappers{0};

    // Chocolate with rs
    totalChocolate += rs / costOfChocolate;
    totalAvaWrappers = totalChocolate;

    // Chocolate with wrappers
    while (totalAvaWrappers >= chocolateCWW)
    {
        int newChocolates = totalAvaWrappers / chocolateCWW;
        totalChocolate += newChocolates;
        totalAvaWrappers = (totalAvaWrappers % chocolateCWW) + newChocolates;
    }

    return totalChocolate;
}