#include <iostream>
#include <vector>
#include <map>

class UnionFindTree {
public:
  UnionFindTree(int n) : tree(n, -1) {}
  void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (-tree[x] < -tree[y]) std::swap(x, y);
    tree[x] += tree[y]; tree[y] = x;
  }
  int find(int x) {
    return tree[x] < 0 ? x : tree[x] = find(tree[x]);
  }
  bool same(int x, int y) {
    if (find(x) == find(y))
      return true;
    else
      return false;
  }
  std::vector<int> tree;
};

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> p(n);
  UnionFindTree uft(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >>y;
    --x, --y;
    uft.unite(x, y);
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (uft.same(i, p[i]))
      ++cnt;
  }
  std::cout << cnt << std::endl;
}