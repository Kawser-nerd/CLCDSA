#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>

template <class Weight>
struct edge {
  size_t src, dst;
  Weight cost;

  edge(size_t src, size_t dst, Weight cost=1):
    src(src), dst(dst), cost(cost)
  {}

  bool operator <(const edge<Weight> &rhs) const {
    if (cost != rhs.cost) return cost < rhs.cost;
    if (src != rhs.src) return src < rhs.src;
    return dst < rhs.dst;
  }
};

template <class Weight>
struct graph: public std::vector<std::vector<edge<Weight>>> {
  graph(size_t n): std::vector<std::vector<edge<Weight>>>(n) {}

  void connect_to(size_t src, size_t dst, Weight cost=1) {
    (*this)[src].emplace_back(src, dst, cost);
  }
};

constexpr int IND = -2e9;

bool dfs(graph<int>& g, size_t v, std::vector<int>& res) {
  for (const auto& e: g[v]) {
    if (res[e.dst] == IND) {
      res[e.dst] = res[e.src] + e.cost;
      if (!dfs(g, e.dst, res)) return false;
    } else {
      if (res[e.dst] != res[e.src] + e.cost) return false;
    }
  }
  return true;
}

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  graph<int> g(N);
  for (size_t i = 0; i < M; ++i) {
    size_t L, R;
    int D;
    scanf("%zu %zu %d", &L, &R, &D);
    --L;
    --R;
    g.connect_to(L, R, D);
    g.connect_to(R, L, -D);
  }

  std::vector<int> res(N, IND);
  for (size_t i = 0; i < N; ++i) {
    if (res[i] != IND) continue;
    res[i] = 0;
    if (!dfs(g, i, res))
      return puts("No"), 0;
  }

  puts("Yes");
}