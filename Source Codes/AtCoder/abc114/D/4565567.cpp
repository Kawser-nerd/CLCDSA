#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>

std::map<intmax_t, intmax_t> factor(intmax_t n) {
  std::map<intmax_t, intmax_t> res;
  for (intmax_t i = 2; i*i <= n; ++i) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n > 1) ++res[n];
  return res;
}

int main() {
  intmax_t N;
  scanf("%jd", &N);

  std::map<intmax_t, intmax_t> ds;
  for (intmax_t i = 2; i <= N; ++i)
    for (const auto& p: factor(i))
      ds[p.first] += p.second;

  std::vector<intmax_t> dd;
  for (const auto& p: ds)
    dd.push_back(p.second);

  // 75 = 3 5 5
  intmax_t res = 0;
  size_t M = dd.size();
  for (size_t i = 0; i < M; ++i) {
    if (dd[i] >= 74) ++res;
    for (size_t j = 0; j < M; ++j) {
      if (j == i) continue;
      if (dd[i] >= 2 && dd[j] >= 24) ++res;
      if (dd[i] >= 4 && dd[j] >= 14) ++res;
      for (size_t k = j+1; k < M; ++k) {
        if (k == i) continue;
        if (dd[i] >= 2 && dd[j] >= 4 && dd[k] >= 4) ++res;
      }
    }
  }
  printf("%jd\n", res);
}