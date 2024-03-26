/* Question: Find total number of duplicate number */

#include "NoOfDuplicateNumbers.h"

// Main function
int main() {
  // Sorting array
  SortArray();
  // Finding Dupes
  FindDuplicate();

  // Printing output
  std::cout << "Total Number of dupes are: " << totalDups << std::endl;

  return 0;
}

// Logics to custom functions
void SortArray() {
  for (int i{0}; i < sizeOfArray; i++) {
    for (int y{i + 1}; y < sizeOfArray; y++) {
      if (numArray[y] < numArray[i]) {
        int temp = numArray[y];
        numArray[y] = numArray[i];
        numArray[i] = temp;
      }
    }
  }
}

// Finding Dupplicate
void FindDuplicate() {
  for (int i{0}; i < sizeOfArray - 1; i++) {
    std::cout << numArray[i] << " " << numArray[i + 1] << std::endl;
    if (numArray[i] == numArray[i + 1])
      totalDups++;
  }
}