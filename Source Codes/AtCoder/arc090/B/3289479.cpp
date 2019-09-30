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

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
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

const int MAX_N = 100000, MAX_M = 200000;
int N, M;
int L[MAX_M], R[MAX_M], D[MAX_M];

                            
struct edge { int to, cost; };
const int MAX_V = MAX_N+1, INF = 10000010;


vector<edge> G[MAX_V];
ll d[MAX_V];

void rec(int v) {
  for (int i = 0; i < G[v].size(); ++i) {
    edge e = G[v][i];
    if (d[e.to] < INFLL) continue;
    d[e.to] = d[v] + e.cost;
    rec(e.to);
  }
}

int main() {
  cin >> N >> M;
  rep(i, M) cin >> L[i] >> R[i] >> D[i];

  rep(i, M) {
    G[L[i]].push_back((edge){R[i], D[i]});
    G[R[i]].push_back((edge){L[i], -D[i]});
  }

  fill(d, d+N+1, INFLL);
  for (int i = 1; i <= N; ++i) {
    if (d[i] == INFLL) {
      d[i] = 0; rec(i);
    }
  }

  rep(i, M) {
    if (d[R[i]]-d[L[i]] != D[i]) {
      cout << "No" << endl; return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}