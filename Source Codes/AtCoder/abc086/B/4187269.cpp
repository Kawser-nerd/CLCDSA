#include <iostream>
#include <string>

int main() {
  std::string a, b;
  std::cin >> a >> b;
  a += b;

  int n = std::stoi(a);

  for (int i = 1; i < 1000; ++i)
    if (n == i*i)
      return (std::cout << "Yes" << std::endl), 0;

  std::cout << "No" << std::endl;
}