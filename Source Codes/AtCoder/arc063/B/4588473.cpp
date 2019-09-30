#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <map>

int main() {
  size_t N, T;
  scanf("%zu %zu", &N, &T);

  std::vector<intmax_t> A(N);
  for (auto& ai: A) scanf("%jd", &ai);

  intmax_t INF = 1e14;
  intmax_t min = INF;
  intmax_t max = -INF;

  std::map<intmax_t, int> res;  

  for (auto ai: A) {
    if (min > ai) {
      min = ai;
      max = ai;
    }
    if (max < ai) {
      max = ai;
      ++res[max-min];
    }
  }

  printf("%d\n", (--res.end())->second);
}