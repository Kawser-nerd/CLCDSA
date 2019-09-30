#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
  size_t N;
  intmax_t H;
  scanf("%zu %jd", &N, &H);

  std::vector<intmax_t> a(N), b(N);
  for (size_t i = 0; i < N; ++i)
    scanf("%jd %jd", &a[i], &b[i]);

  std::sort(a.rbegin(), a.rend());
  std::sort(b.rbegin(), b.rend());

  int res = 0;
  for (auto bi: b) {
    if (bi <= a[0]) break;
    ++res;
    H -= bi;
    if (H <= 0) break;
  }

  if (H > 0)
    res += (H+a[0]-1) / a[0];
  printf("%d\n", res);
}