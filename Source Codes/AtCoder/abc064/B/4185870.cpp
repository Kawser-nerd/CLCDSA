#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> a(N);
  for (auto& ai: a) scanf("%d", &ai);
  std::sort(a.begin(), a.end());

  printf("%d\n", a.back()-a.front());
}