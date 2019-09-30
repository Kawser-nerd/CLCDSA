#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// c++11
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define mt make_tuple
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1 << 29;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const int MAX_N = 310;
// UnionFind
class UnionFind {
public:
  UnionFind(int size_) : parent(size_, -1), __size(size_) {}
  void unite(int x, int y) {
    if ((x = find(x)) != (y = find(y))) {
      if (parent[y] < parent[x])
        std::swap(x, y);
      parent[x] += parent[y];
      parent[y] = x;
      __size--;
    }
  }
  bool is_parent(int x) { return find(x) == x; }
  bool is_same(int x, int y) { return find(x) == find(y); }
  int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
  int size(int x) { return -parent[find(x)]; }
  int size() const { return __size; }

private:
  std::vector<int> parent;
  int __size;
};
// UnionFind

int N;
ll A[MAX_N][MAX_N];
ll B[MAX_N][MAX_N];
vector<tuple<ll, pii>> graphs;
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
      B[i][j] = A[i][j];
    }
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        B[i][j] = min(B[i][j], B[i][k] + B[k][j]);
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (B[i][j] != A[i][j]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      graphs.emplace_back(mt(A[i][j], mp(i, j)));
    }
  }
  sort(graphs.begin(), graphs.end());
  UnionFind ut(N);
  ll res = 0;
  for (const auto &graph : graphs) {
    ll cost;
    pii pos;
    tie(cost, pos) = graph;
    int a, b;
    a = pos.first;
    b = pos.second;
    bool ok = false;
    if (ut.is_same(a, b)) {
      for (int i = 0; i < N; i++){
        if (i == a or i == b)continue;
        ll tmp = A[a][i] + A[i][b];
        if (tmp == cost){
          ok = true;
          break;
        }
      }
    }

    ut.unite(a, b);
    if (not ok){
      // cerr << res << " " << A[a][b] << endl;
      res += A[a][b];
    }
  }

  cout << res << endl;

  return 0;
}