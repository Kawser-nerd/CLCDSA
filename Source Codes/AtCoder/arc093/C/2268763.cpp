#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_V = 1000, MAX_E = 2000, MOD = 1e9+7;

static const int MAX_UF = MAX_V;

template <class T> class UnionFind {
private:
  T par[MAX_UF];
  T rank[MAX_UF];
  
public:
  T find(T x);
  void init(T n);
  void unite(T x, T y);
  bool same (T x, T y);
};

template <class T> void UnionFind<T>::init(T n) {
  for (T i = 0; i < n; ++i) {
    par[i] = i;
    rank[i] = 0;
  }
}

template <class T> T UnionFind<T>::find(T x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

template <class T> void UnionFind<T>::unite(T x, T y) {
  x = find(x); y = find(y);
  if (x == y) {
    return;
  } else {
    if (rank[x] > rank[y]) {
      par[y] = x;
    } else {
      par[x] = y;
      if (rank[x] == rank[y]) ++rank[y];
    }
  }
}

template <class T> bool UnionFind<T>::same(T x, T y) {
  return find(x) == find(y);
}

struct edge { int cost, u, v; };

edge es[MAX_E];
int E, V;

bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}

ll kruskal(UnionFind<int> uf) {
  ll res = 0;

  for (int i = 0; i < E; ++i) {
    edge e = es[i];
    if (!uf.same(e.v, e.u)) {
      uf.unite(e.v, e.u);
      res += e.cost;
    }
  }

  return res;
}

int N, M;
ll X;
ll mst_cost[MAX_E]; //???????????????????

//x^n?mod????????
ll mod_pow(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll res = mod_pow((x*x) % mod, n/2, mod);
  if (n & 1) res = (res*x) % mod;
  return res;
}

ll f(ll x) {
  int c = 0;
  for (int i = 0; i < E; ++i) {
    if (mst_cost[i] <= x) ++c;
  }
  if (c == 0) return mod_pow(2, M, MOD);
  else return mod_pow(2,M-c+1, MOD);
}

int main() {
  cin >> N >> M >> X;
  E = M; V = N;
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    es[i].cost = w; es[i].u = --u; es[i].v = --v;
  }
  sort(es, es+E, comp);

  if (N == 1) { 
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0; i < E; ++i) {
    UnionFind<int> uf;
    uf.init(V);
    uf.unite(es[i].u, es[i].v);
    mst_cost[i] = kruskal(uf) + es[i].cost;
  }

  ll ans = (f(X-1) - f(X) + MOD) % MOD;

  cout << ans << endl;
}