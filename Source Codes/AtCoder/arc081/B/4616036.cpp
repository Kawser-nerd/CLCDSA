#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>

constexpr intmax_t MOD = 1e9+7;

int main() {
  size_t N;
  scanf("%zu", &N);

  char buf[64];
  scanf("%s", buf);
  std::string S1 = buf;
  scanf("%s", buf);
  std::string S2 = buf;

  std::vector<int> pat;
  for (size_t i = 0; i < N; ++i) {
    if (S1[i] == S2[i]) {
      pat.push_back(1);
    } else {
      pat.push_back(0);
      ++i;
    }
  }

  intmax_t res = 3;
  if (pat[0] == 0) res *= 2;
  for (size_t i = 1; i < pat.size(); ++i) {
    if (pat[i-1] == 1) {
      res *= 2;
    } else if (pat[i] == 0) {
      res *= 3;
    }
    res %= MOD;
  }
  printf("%jd\n", res);
}