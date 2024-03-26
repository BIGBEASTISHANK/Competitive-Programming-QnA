#include "GlobalLogic.h"

// Clearing Input buffer
void ClearInputBuffer() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                  '\n'); // Clearing input buffer
}
