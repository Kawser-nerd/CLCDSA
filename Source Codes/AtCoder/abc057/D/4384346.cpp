#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
  size_t N;
  intmax_t A, B;
  scanf("%zu %jd %jd", &N, &A, &B);

  std::vector<std::vector<intmax_t>> ncr(N+1, std::vector<intmax_t>(N+1));
  {
    ncr[0][0] = 1;
    for (size_t i = 1; i <= N; ++i) {
      ncr[i][0] = ncr[i][i] = 1;
      for (size_t j = 1; j <= N; ++j)
        ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
    }
  }

  std::vector<intmax_t> v(N);
  for (auto& vi: v) scanf("%jd", &vi);

  std::sort(v.rbegin(), v.rend());

  std::vector<intmax_t> vv(N+1);
  intmax_t sum = std::accumulate(v.begin(), v.begin()+A, 0L);

  printf("%.12f\n", double(sum)/A);

  size_t left = A-1;
  size_t right = A-1;
  while (left > 0 && v[left] == v[left-1]) --left;
  while (right+1 < N && v[right] == v[right+1]) ++right;

  if (v[0] != v[left])
    return !printf("%jd\n", ncr[right-left+1][A-left]);
    
  intmax_t res = 0;
  for (size_t i = A; i <= std::min<size_t>(B, right+1); ++i)
    res += ncr[right-left+1][i-left];

  printf("%jd\n", res);
}