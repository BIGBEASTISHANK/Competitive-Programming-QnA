#include <iostream>

// Declaring Variables
int numArray[]{1, 2, 2, 3, 6, 3};
int sizeOfArray{sizeof(numArray) / sizeof(int)};
int totalDups{0};

// Declare custom functions
void SortArray();
void FindDuplicate();