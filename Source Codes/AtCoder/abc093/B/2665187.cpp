#include <iostream>

int main() {
  int A, B, K;
  std::cin >> A >> B >> K;

  for (int i = A; i <= B; i++) {
    if (i - A < K || B - i < K) {
      std::cout << i << std::endl;
    }
  }
}