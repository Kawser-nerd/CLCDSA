#include <iostream>
#include <vector>

int main() {
  unsigned N, P;
  std::cin >> N >> P;
  std::vector<unsigned> A(N);
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> A[i];
    A[i] %= 2;
  }
  std::vector<unsigned long long> dp0(N, 0);
  std::vector<unsigned long long> dp1(N, 0);
  if (A[0] % 2 == 0) {
    dp0[0] = 2;
    dp1[0] = 0;
  } else {
    dp0[0] = 1;
    dp1[0] = 1;
  }
  for (unsigned i = 1; i < N; ++i) {
    if (A[i] % 2 == 0) {
      dp0[i] = dp0[i - 1] * 2;
      dp1[i] = dp1[i - 1] * 2;
    } else {
      dp0[i] = dp0[i - 1] + dp1[i - 1];
      dp1[i] = dp0[i - 1] + dp1[i - 1];
    }
  }
  if (P) {
    std::cout << dp1[N - 1] << std::endl;
  } else {
    std::cout << dp0[N - 1] << std::endl;
  }
  return 0;
}