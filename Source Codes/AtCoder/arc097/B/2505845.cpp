#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int p[100001];

// Union-Find-Tree
struct UnionFind {
  vector<int> par;    //??????????
                      //????????????
  vector<int> sizes;  //???????????????
                      //?????????????????
  int N;

  UnionFind(int n) : par(n), sizes(n, 1) {
    for (int i = 0; i < n; i++) par[i] = i;
    N = n;
  }

  int find(int x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (sizes[x] < sizes[y]) {
      par[x] = y;
      sizes[y] += sizes[x];
    } else {
      par[y] = x;
      sizes[x] += sizes[y];
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }

  int size(int x) { return sizes[find(x)]; }
};

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    p[i] = h - 1;
  }

  UnionFind uf(n);

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    uf.unite(x - 1, y - 1);
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (uf.same(i, p[i])) cnt++;
  }

  cout << cnt << endl;

  return 0;
}