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

#define DBG(...) do { fprintf(stderr, __VA_ARGS__); } while(0)

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

int dp[10050];

int solve2(vector<pair<int, int>> vs) {
  int res = 0;
  sort(vs.begin(), vs.end());
  reverse(vs.begin(), vs.end());

  int as = 0, bs = 0, bp = 0;
  for (const auto& p : vs) {
    as += p.first;
    bs += p.second;
    bp += max(p.second, 0);
    chmax(as, 0);
    chmax(bs, 0);
  }
  res = as + bs;

  fill(dp, dp + 10050, -INF);
  dp[0] = 0;
  for (const auto& p : vs) {
    if (p.first > 0) {
      for (int v = 10000 - p.first; v >= 0; --v) {
        chmax(dp[v + p.first], dp[v] + p.second);
      }
    }
  }
  for (int v = 0; v <= 10000; ++v) {
    if (dp[v] > -INF) {
      chmax(res, v + max(bp + dp[v], 0));
    }
  }

  return res;
}

void solve() {
  int N = in();
  int M = in();

  if (M == 1) {
    int res = 0;
    for (int i = 0; i < N; ++i) {
      res += max(0, in());
    }
    printf(" %d\n", res);
  } else if (M == 2) {
    int res = 0;
    vector<pair<int, int>> vs;
    for (int i = 0; i < N; ++i) {
      int a = in();
      int b = in();
      if (a >= 0 && b >= 0) {
        res += a + b;
      } else if (a <= 0 && b <= 0) {
        continue;
      } else {
        vs.emplace_back(a, b);
      }
    }
    int s1 = solve2(vs);
    for (auto& p : vs) {
      swap(p.first, p.second);
    }
    int s2 = solve2(vs);
    printf(" %d\n", res + max(s1, s2));
  }
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d:", CN);
    solve();
  }

  return 0;
}
