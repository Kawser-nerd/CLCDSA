#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <random>

#define _overload(a, b, c, d, ...) d
#define _rep1(X, A, Y) for (int (X) = (A);(X) <= (Y);++(X))
#define _rep2(X, Y) for (int (X) = 0;(X) < (Y);++(X))
#define rep(...) _overload(__VA_ARGS__, _rep1, _rep2)(__VA_ARGS__)
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define _size(X) (int)((X).size())
#define mod(n, m) (((n)%(m)+(m))%m)
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 100;
int N;
int a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N];

const int MAX_V = MAX_N*2;

int V;                 //???
vector<int> G[MAX_V];  //?????????
int match[MAX_V];      //????????
bool used[MAX_V];      //dfs???????????

void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}

bool dfs(int v) {
  used[v] = true;
  for (int i = 0; i < G[v].size(); ++i) {
    int u = G[v][i], w = match[u];
    if (w < 0 || (!used[w] && dfs(w))) {
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}

int bipartite_matching() {
  int res = 0;
  memset(match, -1, sizeof(match));
  for (int v = 0; v < V; ++v) {
    if (match[v] < 0) {
      memset(used, 0, sizeof(used));
      if (dfs(v)) {
        ++res;
      }
    }
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N;
  rep(i, N) cin >> a[i] >> b[i];
  rep(i, N) cin >> c[i] >> d[i];
  V = 2*N;

  rep(i, N) {
      rep(j ,N) {
          if (a[i] < c[j] && b[i] < d[j]) {
              add_edge(i, N+j);
          }
      }
  }

  int ans = bipartite_matching();

  cout << ans << endl;
  return 0;
}