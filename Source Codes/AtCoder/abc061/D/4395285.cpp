#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

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

  void connect_with(size_t src, size_t dst, Weight cost=1) {
    (*this)[src].emplace_back(src, dst, cost);
    (*this)[dst].emplace_back(dst, src, cost);
  }

  void connect_to(size_t src, size_t dst, Weight cost=1) {
    (*this)[src].emplace_back(src, dst, cost);
  }
};

template <class Tp>
constexpr Tp inf = (Tp(1) << (8*sizeof(Tp)-3));

template <class Weight>
std::vector<Weight> shortest(const graph<Weight>& g, size_t s) {
  // based-on Bellman-Ford algorithm
  size_t V = g.size();
  std::vector<Weight> res(V, inf<Weight>);
  res[s] = 0;

  for (size_t i = 1; i < V; ++i)
    for (size_t v = 0; v < V; ++v)
      for (const auto& e: g[v])
        if (res[e.dst] > res[e.src] + e.cost)
          res[e.dst] = res[e.src] + e.cost;

  for (size_t v = 0; v < V; ++v)
    for (const auto& e: g[v])
      if (res[e.dst] > res[e.src] + e.cost)
        res[e.dst] = -inf<Weight>;
  
  return res;
}

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  graph<intmax_t> g(N);
  for (size_t i = 0; i < M; ++i) {
    size_t a, b;
    intmax_t c;
    scanf("%zu %zu %jd", &a, &b, &c);
    --a;
    --b;
    g.connect_to(a, b, -c);
  }

  intmax_t res = shortest(g, 0)[N-1];
  if (res == -inf<intmax_t>) return puts("inf"), 0;
  printf("%jd\n", -res);
}