#include <cstdio>
#include <vector>

int dfs(const std::vector<std::vector<size_t>>& g, size_t v, int visited) {
  size_t N = g.size();
  if (visited == (1 << N)-1) return 1;

  int res = 0;
  for (size_t u: g[v]) {
    if (visited >> u & 1) continue;
    res += dfs(g, u, (1 << u | visited));
  }
  return res;
}

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  std::vector<std::vector<size_t>> g(N);
  for (size_t i = 0; i < M; ++i) {
    size_t a, b;
    scanf("%zu %zu", &a, &b);
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  printf("%d\n", dfs(g, 0, 1));
}