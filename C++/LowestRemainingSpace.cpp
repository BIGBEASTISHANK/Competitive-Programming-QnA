// Question Url:
// https://mycode.prepbytes.com/problems/recursion/MINVOID

// Include
#include <cmath>
#include <iostream>
#include "GlobalLogic.h"

// Variable
int noOfDisk{0}, heightOfCylinder{0};
int *heightOfAllDisk{nullptr};

// Declare function
void TakingInput();
int Calculation();

// Main function
int main()
{
    // Call Function
    TakingInput();
    std::cout << Calculation();

    return 0;
}

// Logic to variable
// Taking input
void TakingInput()
{
    // Line 1
    std::cout << "Enter number of disk and height of cylinder: ";
    std::cin >> noOfDisk >> heightOfCylinder;
    ClearInputBuffer();
    heightOfAllDisk = new int[noOfDisk];

    // Constraints 1
    if (noOfDisk < 1 || noOfDisk > 20)
    {
        std::cout << "Number of disk should be between 1 and 20.";
        exit(0);
    }

    // Constraing 2
    for (int i{0}; i < noOfDisk; i++)
    {
        if (heightOfCylinder < 1 || heightOfCylinder > pow(10, 9))
        {
            std::cout << "Enter height of disk between 1 and " << pow(10, 9) << ".";
            exit(0);
        }
    }

    // Line 2
    std::cout << "Enter height of each disk seprated by space: ";
    for (int i{0}; i < noOfDisk; i++)
        std::cin >> heightOfAllDisk[i];
    ClearInputBuffer();

    // Constraing 2
    for (int i{0}; i < noOfDisk; i++)
    {
        if (heightOfAllDisk[i] < 1 || heightOfAllDisk[i] > pow(10, 9))
        {
            std::cout << "Enter height of disk between 1 and " << pow(10, 9) << ".";
            exit(0);
        }
    }
}

// Calculating
int Calculation()
{
    int totalSum{0};

    // Sorting
    for (int i{0}; i < noOfDisk - 1; i++)
        for (int j{i + 1}; j < noOfDisk; j++)
            if (heightOfAllDisk[j] < heightOfAllDisk[i])
            {
                int temp = heightOfAllDisk[j];
                heightOfAllDisk[j] = heightOfAllDisk[i];
                heightOfAllDisk[i] = temp;
            }

    // Getting total number of disk
    for (int i{0}; i < noOfDisk; i++)
        if (heightOfAllDisk[i] + totalSum <= heightOfCylinder)
            totalSum += heightOfAllDisk[i];

    return heightOfCylinder - totalSum;
}