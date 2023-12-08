#pragma once

// Include
#include <ios>
#include <limits>

// Function
void ClearInputBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clearing input buffer
}