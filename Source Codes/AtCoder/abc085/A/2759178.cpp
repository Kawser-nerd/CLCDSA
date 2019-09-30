#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  s[3] = '8';

  std::cout << s << std::endl;  
}