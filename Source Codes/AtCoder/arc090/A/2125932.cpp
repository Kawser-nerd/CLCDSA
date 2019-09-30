#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> A1;
  std::vector<int> A2;
  int N;
  std::cin >> N;

  A1.resize(N);
  A2.resize(N);
  for (int i = 0; i < N; i++) std::cin >> A1[i];
  for (int i = 0; i < N; i++) std::cin >> A2[i];

  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < N; i++) sum2 += A2[i];

  int max = 0;
  for (int i = 0; i < N; i++) {
    sum1 += A1[i];
    max = std::max(max, sum1 + sum2);
    sum2 -= A2[i];
  }

  std::cout << max;

  return 0;
}