#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <map>

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
  size_t N, K, L;
  scanf("%zu %zu %zu", &N, &K, &L);

  union_find uf1(N);
  for (size_t i = 0; i < K; ++i) {
    size_t p, q;
    scanf("%zu %zu", &p, &q);
    --p;
    --q;
    uf1.unite(p, q);
  }

  union_find uf2(N);
  for (size_t i = 0; i < L; ++i) {
    size_t r, s;
    scanf("%zu %zu", &r, &s);
    --r;
    --s;
    uf2.unite(r, s);
  }

  std::map<std::pair<size_t, size_t>, int> res;
  for (size_t i = 0; i < N; ++i)
    ++res[{uf1.find(i), uf2.find(i)}];

  for (size_t i = 0; i < N; ++i)
    printf("%d%c", res[{uf1.find(i), uf2.find(i)}], i+1<N? ' ':'\n');
}