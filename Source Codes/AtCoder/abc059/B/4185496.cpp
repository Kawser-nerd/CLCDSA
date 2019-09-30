#include <iostream>
#include <string>

int main() {
  std::string A, B;
  std::cin >> A >> B;

  int res = 0;
  if (A == B) {
    res = 0;
  } else if (A.length() != B.length()) {
    if (A.length() < B.length()) {
      res = -1;
    } else {
      res = 1;
    }
  } else {
    if (A < B) {
      res = -1;
    } else {
      res = 1;
    }
  }

  if (res < 0) {
    std::cout << "LESS" << std::endl;
  } else if (res > 0) {
    std::cout << "GREATER" << std::endl;
  } else {
    std::cout << "EQUAL" << std::endl;
  }
}