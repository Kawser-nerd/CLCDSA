#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>
#include <functional>

template <class Tp, class Compare>
using priority_queue = std::priority_queue<Tp, std::deque<Tp>, Compare>;

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
};

template <class Tp>
constexpr Tp inf = Tp(1) << (8*sizeof(Tp)-3);

template <class Weight>
std::vector<Weight> shortest(const graph<Weight> &g, size_t s) {
  // based on Dijkstra algorithm
  std::vector<Weight> res(g.size(), inf<Weight>);
  priority_queue<std::pair<Weight, size_t>, std::greater<>> q;
  res[s] = 0;
  q.emplace(0, s);
  while (!q.empty()) {
    Weight w;
    size_t v;
    std::tie(w, v) = q.top();
    q.pop();
    if (w > res[v]) continue;

    for (const auto& e: g[v]) {
      if (res[e.dst] > w + e.cost) {
        res[e.dst] = w + e.cost;
        q.emplace(res[e.dst], e.dst);
      }
    }
  }
  return res;
}

int main() {
  size_t N;
  scanf("%zu", &N);

  graph<int> g(N);
  for (size_t i = 1; i < N; ++i) {
    size_t a, b;
    scanf("%zu %zu", &a, &b);
    --a;
    --b;
    g.connect_with(a, b);
  }

  auto d1 = shortest(g, 0);
  auto d2 = shortest(g, N-1);

  int fennec = 0;
  int snuke_ = 0;
  for (size_t i = 0; i < N; ++i)
    ++((d1[i] <= d2[i])? fennec:snuke_);

  puts((fennec > snuke_)? "Fennec":"Snuke");
}