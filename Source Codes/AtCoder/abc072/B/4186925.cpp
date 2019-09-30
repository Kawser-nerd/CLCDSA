#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  for (size_t i = 0; i < s.length(); i += 2)
    std::cout << s[i];

  std::cout << std::endl;
}