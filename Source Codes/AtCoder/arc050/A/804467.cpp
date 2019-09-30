#include <iostream>
#include <string>
int main () {
  std::string line;
  std::getline(std::cin, line);

  if (line[0] - 'A' == line[2] - 'a') {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
}