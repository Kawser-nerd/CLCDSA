#include <iostream>

int main() {
  int A, B, C, D;
  std::cin >> A >> B >> C >> D;

  std::cout << std::min(A, B) + std::min(C, D) << std::endl;
}