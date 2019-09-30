#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> A(N), B(N), C(N);
  for (auto& ai: A) scanf("%d", &ai);
  for (auto& bi: B) scanf("%d", &bi);
  for (auto& ci: C) scanf("%d", &ci);

  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());
  std::sort(C.begin(), C.end());

  intmax_t res = 0;
  for (size_t i = 0; i < N; ++i) {
    intmax_t a = std::lower_bound(A.begin(), A.end(), B[i]) - A.begin();
    intmax_t c = C.end() - std::upper_bound(C.begin(), C.end(), B[i]);
    res += a*c;
  }
  printf("%jd\n", res);
}