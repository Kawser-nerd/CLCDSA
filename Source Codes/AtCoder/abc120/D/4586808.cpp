#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

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

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  std::vector<std::pair<size_t, size_t>> AB(M);
  for (auto& p: AB) {
    scanf("%zu %zu", &p.first, &p.second);
    --p.first;
    --p.second;
  }
  std::reverse(AB.begin(), AB.end());

  union_find uf(N);
  std::vector<size_t> res{0};

  for (size_t i = 0; i+1 < M; ++i) {
    size_t a, b;
    std::tie(a, b) = AB[i];

    size_t u = uf.size(a);
    size_t v = uf.size(b);
    size_t tmp = res[i];
    if (uf.unite(a, b)) tmp += u*v;
    res.push_back(tmp);
  }

  for (size_t i = M; i--;)
    printf("%zu\n", N*(N-1)/2-res[i]);
}