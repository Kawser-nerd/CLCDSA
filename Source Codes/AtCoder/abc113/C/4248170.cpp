#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <tuple>

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  std::vector<std::pair<int, int>> PY(M);
  for (auto& pi: PY) scanf("%d %d", &pi.first, &pi.second);

  std::map<int, std::vector<int>> aux;
  for (auto& pi: PY) {
    int p, y;
    std::tie(p, y) = pi;
    aux[p].push_back(y);
  }

  std::map<int, std::map<int, int>> ord;
  for (auto& p: aux) {
    std::sort(p.second.begin(), p.second.end());
    for (size_t i = 0; i < p.second.size(); ++i)
      ord[p.first][p.second[i]] = i+1;
  }

  for (auto& pi: PY) {
    int p, y;
    std::tie(p, y) = pi;
    printf("%06d%06d\n", p, ord[p][y]);
  }
}