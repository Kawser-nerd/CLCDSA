#include <iostream>

int main() {
  int N, M, X;
  std::cin >> N >> M >> X;

  int cz = 0, cn = 0;

  for (int i = 0; i < M; i++) {
    int m;
    std::cin >> m;

    if (m < X) {
      cz += 1;
    }

    if (m > X) {
      cn += 1;
    }
  }

  std::cout << std::min(cz, cn) << std::endl;
}