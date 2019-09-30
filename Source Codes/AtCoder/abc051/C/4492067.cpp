#include <iostream>
#include <vector>

int main() {
  int sx, sy, tx, ty;
  std::cin >> sx >> sy >> tx >> ty;
  for (int i = sy; i < ty; i++) {
    std::cout << "U";
  }
  for (int i = sx; i < tx; i++) {
    std::cout << "R";
  }
  for (int i = sy; i < ty; i++) {
    std::cout << "D";
  }
  for (int i = sx; i < tx; i++) {
    std::cout << "L";
  }

  std::cout << "L";
  for (int i = sy; i <= ty; i++) {
    std::cout << "U";
  }
  for (int i = sx; i <= tx; i++) {
    std::cout << "R";
  }
  std::cout << "D";
  std::cout << "R";
  for (int i = sy; i <= ty; i++) {
    std::cout << "D";
  }
  for (int i = sx; i <= tx; i++) {
    std::cout << "L";
  }
  std::cout << "U" << std::endl;
}