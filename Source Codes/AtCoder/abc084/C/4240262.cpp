#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> T(N);
  for (size_t i = 1; i < N; ++i) {
    int C, S, F;
    scanf("%d %d %d", &C, &S, &F);
    for (size_t j = 0; j < i; ++j) {
      T[j] = std::max(S, (T[j]+F-1)/F*F) + C;
    }
  }

  for (auto ti: T) printf("%d\n", ti);
}