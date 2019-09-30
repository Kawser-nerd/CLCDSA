#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> X(N);
  for (auto& xi: X) scanf("%d", &xi);

  std::vector<int> Y = X;
  std::sort(Y.begin(), Y.end());
  int small = Y[N/2-1];
  int large = Y[N/2];
  for (auto xi: X) {
    if (small < xi) {
      printf("%d\n", small);
    } else {
      printf("%d\n", large);
    }
  }
}