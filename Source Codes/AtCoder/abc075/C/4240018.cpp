#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

void dfs(const std::vector<std::vector<size_t>>& g, size_t v,
         std::vector<bool>& vis) {

  if (vis[v]) return;
  vis[v] = true;
  for (size_t u: g[v]) dfs(g, u, vis);
}

bool connected(const std::vector<std::vector<size_t>>& g) {
  size_t N = g.size();
  std::vector<bool> vis(N);
  dfs(g, 0, vis);
  return std::all_of(vis.begin(), vis.end(), [](bool f) { return f; });
}

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  std::vector<size_t> a(M), b(M);
  for (size_t i = 0; i < M; ++i) {
    scanf("%zu %zu", &a[i], &b[i]);
    --a[i];
    --b[i];
  }

  int res = 0;
  for (size_t i = 0; i < M; ++i) {
    std::vector<std::vector<size_t>> g(N);
    for (size_t j = 0; j < M; ++j) {
      if (j == i) continue;
      g[a[j]].push_back(b[j]);
      g[b[j]].push_back(a[j]);
    }
    if (!connected(g)) ++res;
  }
  printf("%d\n", res);
}