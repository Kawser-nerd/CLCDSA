#include <iostream>
#include <sstream>

int main() {
  int A, B;
  std::cin >> A >> B;

  std::stringstream ss;

  ss << A << B;

  int n = std::stoi(ss.str());

  bool yes = false;

  for (int i = 0; !yes && i * i <= n; i++) {
    yes = (i * i == n);
  }

  std::cout << (yes ? "Yes" : "No") << std::endl;
}