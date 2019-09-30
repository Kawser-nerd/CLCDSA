#include <algorithm>
#include <cstdio>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class UnionFind {
  public:
    UnionFind(int n = 0) {
      init(n);
    }
    void init(int n) {
      p_.resize(n);
      r_.resize(n);
      iota(p_.begin(), p_.end(), 0);
      fill(r_.begin(), r_.end(), 0);
    }
    int find(int x) {
      int &p = p_[x];
      if (x != p) {
        p = find(p);
      }
      return p;
    }
    void unite(int x, int y) {
      int px = find(x);
      int py = find(y);
      if (r_[px] < r_[py]) {
        swap(px, py);
      }
      if (r_[px] == r_[py]) {
        ++r_[px];
      }
      p_[py] = px;
    }
  private:
    vector<int> p_, r_;
};

int main() {
  int n, m, s, u, v;
  vector<int> edges[200001];
  vector<int> ids;
  UnionFind uf;
  scanf("%d%d%d", &n, &m, &s);
  for (int mi = 0; mi < m; ++mi) {
    scanf("%d%d", &u, &v);
    if (u > v) {
      swap(u, v);
    }
    edges[u].push_back(v);
  }
  uf.init(n + 1);
  uf.unite(0, s);
  for (int ni = n; ni > 0; --ni) {
    for (size_t ei = 0; ei < edges[ni].size(); ++ei) {
      uf.unite(ni, edges[ni][ei]);
    }
    if (uf.find(ni) == uf.find(0)) {
      ids.push_back(ni);
    }
  }
  reverse(ids.begin(), ids.end());
  for (auto id : ids) {
    printf("%d\n", id);
  }
  return 0;
}