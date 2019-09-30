#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

bool check(const std::vector<int>& path,
           const std::vector<std::vector<int>>& g) {
  int cur = 1;
  std::vector<bool> used(g.size(), false);
  used[1] = true;
  for (auto p : path) {
    if (!used[p] &&
        std::find(g[cur].begin(), g[cur].end(), p) != g[cur].end()) {
      cur = p;
      used[p] = true;
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  std::vector<int> path(n - 1);
  std::iota(path.begin(), path.end(), 2);
  int ans = 0;
  do {
    if (check(path, g)) ans++;
  } while (std::next_permutation(path.begin(), path.end()));
  std::cout << ans << std::endl;
}