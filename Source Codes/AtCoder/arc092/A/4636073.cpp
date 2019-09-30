#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <tuple>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<std::pair<int, int>> ab(N), cd(N);
  for (auto& p: ab) scanf("%d %d", &p.first, &p.second);
  for (auto& p: cd) scanf("%d %d", &p.first, &p.second);

  std::sort(ab.begin(), ab.end());
  std::sort(cd.begin(), cd.end());

  int res = 0;
  std::set<int> s;
  for (size_t i = 0, j = 0; i < N; ++i) {
    int c, d;
    std::tie(c, d) = cd[i];
    while (j < N && ab[j].first < c) s.insert(ab[j++].second);

    if (s.empty()) continue;

    auto it = s.upper_bound(d);
    if (it == s.begin()) continue;
    s.erase(--it);
    ++res;
  }
  printf("%d\n", res);
}