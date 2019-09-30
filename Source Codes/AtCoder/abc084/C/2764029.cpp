#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> C(N-1), S(N-1), F(N-1);

  for (int i = 0; i < N-1; i++) {
    std::cin >> C[i] >> S[i] >> F[i];
  }

  for (int i = 0; i < N-1; i++) {
    int t = 0;

    for (int j = i; j < N-1; j++) {
      t = ((std::max(t, S[j]) + F[j] - 1) / F[j]) * F[j] + C[j];
    }

    std::cout << t << std::endl;
  }

  std::cout << 0 << std::endl;
}