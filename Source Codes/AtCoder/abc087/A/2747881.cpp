#include <iostream>

int main() {
  int X, A, B;
  std::cin >> X >> A >> B;

  std::cout << (X - A) % B << std::endl;
}