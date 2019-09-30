#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define FOR(i, k, n) for (int(i) = (k); (i) < (n); ++(i))
#define rep(i, n) FOR(i, 0, n)
#define all(v) begin(v), end(v)
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) cerr << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef deque<bool> db;
template <class T>
using vv = vector<vector<T>>;

struct UnionFind
{
  vector<int> par;
  vector<int> sizes;
  int N;

  UnionFind(int n) : par(n), sizes(n, 1)
  {
    for (int i = 0; i < n; i++)
      par[i] = i;
    N = n;
  }

  int find(int x)
  {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }

  void unite(int x, int y)
  {
    x = find(x);
    y = find(y);
    if (x == y)
      return;

    if (sizes[x] < sizes[y])
    {
      par[x] = y;
      sizes[y] += sizes[x];
    }
    else
    {
      par[y] = x;
      sizes[x] += sizes[y];
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }

  int size(int x) { return sizes[find(x)]; }
};

int main()
{
  int n, m;
  cin >> n >> m;

  vi p(n);

  rep(i, n)
  {
    cin >> p[i];
    p[i]--;
  }

  UnionFind uf(n);

  rep(i, m)
  {
    int x, y;
    cin >> x >> y;
    uf.unite(x - 1, y - 1);
  }

  int count = 0;

  rep(i, n)
  {
    if (uf.same(p[i], i))
      count++;
  }
  cout << count << endl;
  return 0;
}