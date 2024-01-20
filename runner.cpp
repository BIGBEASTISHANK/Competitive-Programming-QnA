#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

// Function
void ClearBuffer();

int main() {
  // Taking Input for os
  int OSystem{0};
  std::cout << "Select your OS (0: Linux, 1: Windows): ";
  std::cin >> OSystem;
  ClearBuffer();

  // Taking Input
  std::string fileLocation{""};
  std::cout << "Enter your file location: ";
  std::cin >> fileLocation;
  // Ignoring input buffer
  ClearBuffer();

  // Taking Input
  std::string outPutFileName{""};
  std::cout << "Enter your output file name: ";
  std::cin >> outPutFileName;
  // Ignoring input buffer
  ClearBuffer();

  // Constructing the compile command
  std::string compileCommand = "g++ " + fileLocation + " -o " + outPutFileName;

  // Running
  int executedCommand{0};

  OSystem
      ? []() { std::cout << "I'm working on this please Stand By!"; }()
      : [&]() {
          // Building Code
          executedCommand = system(compileCommand.c_str());

          // IF want to run
          executedCommand == 0
              ? [&]() {
                  std::string runningCommand{"./" + outPutFileName};
                  int wantToRun{0};
                  std::cout << "Do You want to run the file(0: No, 1: yes): ";
                  std::cin >> wantToRun;
                  std::cout << std::endl
                            << std::endl
                            << std::endl
                            << std::endl
                            << std::endl;
                  ClearBuffer();

                  wantToRun == 1
                      ? [&]() { system(runningCommand.c_str()); }()
                      : [&]() {
                          std::cout << "File created sucessfully! Exiting.";
                          exit(0);
                        }();
                }()
              : [&]() {
                  std::cout << "Look for the error above, Exiting!";
                  exit(0);
                }();
        }();

  return 0;
}

// Clearing Buffer
void ClearBuffer() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
