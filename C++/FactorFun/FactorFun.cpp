// Question Url:
// https://mycode.prepbytes.com/contest/PRIMETIMEJULY20/problems/FFUN

// Header files
#include "FactorFun.h"

// Main function
int main()
{
  // Taking input
  takeInput();
  // Calculating output
  calculateOutput();

  // Giving answer
  std::cout << "Answer: ";
  for (int i{0}; i < arraySize; i++)
  {
    std::cout << outputArray[i] << " ";
  }

  return 0;
}

// Add logics to function
// Take input
void takeInput()
{
  // Taking array size
  std::cout << "Enter array size: ";
  std::cin >> arraySize;
  ClearInputBuffer();
  // Setting array size

  inputArray = new int[arraySize];
  outputArray = new int[arraySize];

  if (1 <= arraySize && arraySize <= pow(10, 5))
  {
    // Taking array input
    std::cout << "Enter array inputs seprated by space: ";
    for (int i{0}; i < arraySize; i++)
    {
      std::cin >> inputArray[i];
    }
    ClearInputBuffer();

    // Constraints 2 checking array data size
    for (int i = 0; i < arraySize; i++)
    {
      if (1 <= inputArray[i] && inputArray[i] <= pow(10, 6))
        continue;
      else
      {
        std::cout << "Array value size should be betwwn 1 and " << pow(10, 6) << ".";
        break;
      }
    }
  }
  else
  {
    std::cout << "Enter array size between 1 and " << pow(10, 5)
              << "."; // Constraints 1 checking array size
  }
}

// Getting output
void calculateOutput()
{
  for (int i{0}; i < arraySize; i++)
  {
    int count{0};
    for (int j{0}; j < i; j++)
    {
      if (inputArray[i] % inputArray[j] == 0)
        count++;
    }
    outputArray[i] = count;
    count = 0;
  }
}