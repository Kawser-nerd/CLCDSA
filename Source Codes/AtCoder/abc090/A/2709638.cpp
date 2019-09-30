#include <iostream>
#include <string>

int main() {
  for (int i = 0; i < 3; i++) {
    std::string s;
    std::cin >> s;
    std::cout << s[i];
  }

  std::cout << std::endl;
}