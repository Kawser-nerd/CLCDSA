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

int dp[5][128][128][128];

void solve() {
  int N = in();
  int P = in();
  int c[4] = {0, 0, 0, 0};
  for (int i = 0; i < N; ++i) {
    int g = in();
    c[g % P]++;
  }
  printf("%d\n", c[0] + dp[P][c[1]][c[2]][c[3]]);
}

void pre() {
  for (int P = 2; P <= 4; ++P) {
    for (int i = 0; i <= 100; ++i) {
      for (int j = 0; j <= 100; ++j) {
        for (int k = 0; k <= 100; ++k) {
          int s = (i + j * 2 + k * 3) % P == 0 ? 1 : 0;
          chmax(dp[P][i + 1][j][k], dp[P][i][j][k] + s);
          chmax(dp[P][i][j + 1][k], dp[P][i][j][k] + s);
          chmax(dp[P][i][j][k + 1], dp[P][i][j][k] + s);
        }
      }
    }
  }
}

int main() {
  int T = in();

  pre();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
