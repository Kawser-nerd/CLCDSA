#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <utility>
#include <functional>
#include <tuple>

template <class T>
using greater_queue = std::priority_queue<T, std::deque<T>, std::greater<T>>;

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
  // based-on Dijkstra algorithm
  size_t V = g.size();
  std::vector<Weight> res(V, inf<Weight>);
  res[s] = 0;
  greater_queue<std::pair<Weight, size_t>> q;
  q.emplace(0, s);
  while (!q.empty()) {
    size_t v;
    Weight w;
    std::tie(w, v) = q.top();
    q.pop();
    if (res[v] < w) continue;
    for (const auto& e: g[v])
      if (res[e.dst] > res[e.src] + e.cost) {
        res[e.dst] = res[e.src] + e.cost;
        q.emplace(res[e.dst], e.dst);
      }
  }
  
  return res;
}

int main() {
  size_t N;
  scanf("%zu", &N);

  graph<intmax_t> g(N);
  for (size_t i = 1; i < N; ++i) {
    size_t a, b;
    intmax_t c;
    scanf("%zu %zu %jd", &a, &b, &c);
    --a;
    --b;
    g.connect_with(a, b, c);
  }

  int Q;
  size_t K;
  scanf("%d %zu", &Q, &K);
  --K;

  auto dist = shortest(g, K);
  for (int i = 0; i < Q; ++i) {
    size_t x, y;
    scanf("%zu %zu", &x, &y);
    --x;
    --y;
    printf("%jd\n", dist[x]+dist[y]);
  }
}