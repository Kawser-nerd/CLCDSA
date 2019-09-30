#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  size_t n;
  scanf("%zu", &n);

  std::vector<int> a(n);
  for (auto& ai: a) scanf("%d", &ai);

  std::sort(a.begin(), a.end());

  int ai = a.back();

  auto it = std::lower_bound(a.begin(), a.end()-1, ai/2);
  if (it > a.begin() && it[0]-ai/2 > ai/2-it[-1]) --it;
  if (it == a.end()-1) --it;
  int aj = *it;

  printf("%d %d\n", ai, aj);
}