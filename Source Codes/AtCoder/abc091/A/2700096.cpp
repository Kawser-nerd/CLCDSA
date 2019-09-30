#include <iostream>

int main() {
  int A, B, C;
  std::cin >> A >> B >> C;

  std::cout << (A + B < C ? "No" : "Yes") << std::endl;
}