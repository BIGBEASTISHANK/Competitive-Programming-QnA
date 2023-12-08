// Question url:
// https://mycode.prepbytes.com/contest/PRIMETIMEJULY20/problems/DATEGAME

// Include
#include <iostream>
#include "GlobalLogic.h"

// Variable
int numOfBar{0};
int *NOBData{nullptr};
int YDate{0}, YMonth{0};

// Declare function
void TakeInput();
int Calculation();

// Main function
int main()
{
    // Run function
    TakeInput();
    std::cout << std::endl
              << "Total number of combination: "
              << Calculation();

    return 0;
}

// Add logic to functions
void TakeInput()
{
    // Setting total number of chocolate bar
    std::cout << "Enter total number of chocolate bar: ";
    std::cin >> numOfBar;
    ClearInputBuffer();

    // Constraints 1
    if (1 <= numOfBar && numOfBar <= 90)
        NOBData = new int[numOfBar];
    else
    {
        std::cout << "Please enter number of bar between 1 and 90.";
        exit(0);
    }

    // Taking NOBData
    std::cout << std::endl
              << "Enter each bar number seprated by space: ";
    for (int i{0}; i < numOfBar; i++)
        std::cin >> NOBData[i];
    ClearInputBuffer();

    // Constraint 2
    for (int i{0}; i < numOfBar; i++)
    {
        if (NOBData == nullptr)
            break;
        else
        {
            if (NOBData[i] < 1 || NOBData[i] > 5)
            {
                std::cout << "Enter data between 1 and 5.";
                exit(0);
            }
        }
    }

    // Taking data of birth
    std::cout << std::endl
              << "Enter data of birth (DD MM): ";
    std::cin >> YDate >> YMonth;
    ClearInputBuffer();

    // Constraing 3 & 4
    if (YDate > 31 || YDate < 1)
    {
        std::cout << "Enter a valid date.";
        exit(0);
    }
    if (YMonth > 12 || YMonth < 1)
    {
        std::cout << "Enter a valid month";
        exit(0);
    }
}

// Calculation
int Calculation()
{
    // Variable
    int tempNum{0};
    int count{0};

    // Logic loop
    for (int x{0}; x < numOfBar; x++)
    {
        tempNum += NOBData[x];

        for (int y{x + 1}; y <= (YMonth - 1) + x; y++)
            tempNum += NOBData[y];

        if (tempNum == YDate)
            count++;
        tempNum = 0;
    }

    // Returning number
    return count;
}