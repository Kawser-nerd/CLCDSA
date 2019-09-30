#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

Int D[128][128];
int E[128], S[128];
double X[128][128];

void solve() {
  int N = in();
  int Q = in();
  for (int i = 0; i < N; ++i) {
    E[i] = in();
    S[i] = in();
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      D[i][j] = lin();
      if (D[i][j] == -1) {
        D[i][j] = (i == j ? 0 : INFLL);
      }
    }
  }

  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        chmin(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j) {
        X[i][j] = 0;
      } else {
        if (D[i][j] > E[i]) {
          X[i][j] = INFLL;
        } else {
          X[i][j] = D[i][j] / double(S[i]);
        }
      }
    }
  }

  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        chmin(X[i][j], X[i][k] + X[k][j]);
      }
    }
  }

  for (int i = 0; i < Q; ++i) {
    int u = in() - 1;
    int v = in() - 1;
    printf(" %.9f", X[u][v]);
  }
  puts("");
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d:", CN);
    solve();
  }

  return 0;
}
