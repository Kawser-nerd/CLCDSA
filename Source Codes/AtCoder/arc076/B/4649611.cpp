#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>

class union_find {
  std::vector<intmax_t> tree;

public:
  union_find(size_t n): tree(n, -1) {}

  size_t find(size_t v) {
    if (tree[v] < 0)
      return v;

    return (tree[v] = find(tree[v]));
  }

  bool unite(size_t u, size_t v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;

    if (-tree[u] >= -tree[v])
      std::swap(u, v);

    tree[v] += tree[u];
    tree[u] = v;
    return true;
  }

  bool connected(size_t u, size_t v) {
    return (find(u) == find(v));
  }

  size_t size(size_t v) {
    return -tree[find(v)];
  }
};

template <class Weight>
struct edge {
  using value_type = Weight;
  size_t src, dst;
  value_type cost;

  edge(size_t src, size_t dst, value_type cost=1):
    src(src), dst(dst), cost(cost)
  {}

  bool operator <(const edge<value_type> &rhs) const {
    if (cost != rhs.cost) return cost < rhs.cost;
    if (src != rhs.src) return src < rhs.src;
    return dst < rhs.dst;
  }
};

template <class ForwardIt>
auto min_spanning_tree(size_t v, ForwardIt first, ForwardIt last) {
  // return type: std::pair<Weight, std::set<edge<Weight>>
  // based on Kruskal algorithm
  using Weight = typename ForwardIt::value_type::value_type;
  union_find uf(v);
  Weight cost = Weight();
  std::set<edge<Weight>> mst;
  while (first != last) {
    const auto& e = *first++;
    if (uf.connected(e.src, e.dst)) continue;
    cost += e.cost;
    mst.insert(e);
    uf.unite(e.src, e.dst);
  }
  return std::make_pair(cost, mst);
}

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<std::pair<intmax_t, size_t>> x(N), y(N);
  for (size_t i = 0; i < N; ++i) {
    scanf("%jd %jd", &x[i].first, &y[i].first);
    x[i].second = y[i].second = i;
  }

  std::sort(x.begin(), x.end());
  std::sort(y.begin(), y.end());

  std::vector<edge<intmax_t>> es;
  for (size_t i = 1; i < N; ++i) {
    intmax_t dx = std::abs(x[i].first-x[i-1].first);
    intmax_t dy = std::abs(y[i].first-y[i-1].first);
    es.emplace_back(x[i].second, x[i-1].second, dx);
    es.emplace_back(x[i-1].second, x[i].second, dx);
    es.emplace_back(y[i].second, y[i-1].second, dy);
    es.emplace_back(y[i-1].second, y[i].second, dy);
  }

  std::sort(es.begin(), es.end());
  printf("%jd\n", min_spanning_tree(N, es.begin(), es.end()).first);
}