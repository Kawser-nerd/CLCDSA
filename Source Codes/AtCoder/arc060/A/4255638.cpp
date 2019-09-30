#include <cstdio>
#include <vector>
#include <map>

std::map<std::pair<size_t, int>, intmax_t> memo;

intmax_t dfs(const std::vector<int>& x, size_t i, int sum) {
  if (i == x.size()) return 0;
  std::pair<size_t, int> key(i, sum);
  auto it = memo.lower_bound(key);
  if (it != memo.end() && it->first == key) return it->second;

  intmax_t res = 0;
  res += dfs(x, i+1, sum+x[i]) + ((sum+x[i] == 0)? 1:0);
  res += dfs(x, i+1, sum);
  memo.emplace_hint(it, key, res);
  return res;
}

int main() {
  size_t N;
  int A;
  scanf("%zu %d", &N, &A);

  std::vector<int> x(N);
  for (auto& xi: x) {
    scanf("%d", &xi);
    xi -= A;
  }

  printf("%jd\n", dfs(x, 0, 0));
}