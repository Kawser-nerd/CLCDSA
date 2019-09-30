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

const int MAX_N = 100000;
int N, M;
int a[MAX_N], b[MAX_N];

vector<int> G[MAX_N];

void add_edge(int v, int u) {
    G[v].push_back(u); G[u].push_back(v);
}


bool rec(int a, int b, int par, int v) {
    if (v == b) return false;
    if (v == a) return true;

    for (int i = 0; i < G[v].size(); ++i) {
        if (G[v][i] != par) {
            return rec(a, b, v, G[v][i]);
        }
    }
}

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N >> M;
  rep(i, M) cin >> a[i] >> b[i];
  rep(i, M) {--a[i]; --b[i];}

  rep(i, M) add_edge(a[i], b[i]);

  int c6 = 0, c4 = 0;
  vector<int> vc4;
  for (int v = 0; v < N; ++v) {
      if (G[v].size()%2 == 1) {
          cout << "No" << endl;
          return 0;
      }
      if (G[v].size() >= 6) {
          ++c6;
      } else if (G[v].size() >= 4) {
          ++c4;
          vc4.push_back(v);
      }
  }

  if (c6 > 0) {
      cout << "Yes" << endl;
      return 0;
  }

  if (c4 > 2) {
      cout << "Yes" << endl;
      return 0;
  }

  
  if (c4 == 2) {
      int a = vc4[0], b = vc4[1];
      for (int i = 0; i < G[a].size(); ++i) {
          if (rec(a, b, a, G[a][i])) {
              cout << "Yes" << endl;
              return 0;
          }
      }
  }

  cout << "No" << endl;

  return 0;
} ./Main.cpp:64:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.