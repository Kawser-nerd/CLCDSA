#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>

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

  std::vector<size_t> p(N);
  for (auto& pi: p) {
    scanf("%zu", &pi);
    --pi;
  }

  union_find uf(N);
  for (size_t i = 0; i < M; ++i) {
    size_t x, y;
    scanf("%zu %zu", &x, &y);
    --x;
    --y;
    uf.unite(x, y);
  }

  int res = 0;
  for (size_t i = 0; i < N; ++i) {
    if (uf.connected(i, p[i])) ++res;
  }
  printf("%d\n", res);
}