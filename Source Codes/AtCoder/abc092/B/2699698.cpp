#include <iostream>

int main() {
  int N, D, X;
  std::cin >> N >> D >> X;

  int answer = X;

  for (int i = 0; i < N; i++) {
    int a;
    std::cin >> a;

    answer += (D - 1) / a + 1;
  }

  std::cout << answer << std::endl;
}