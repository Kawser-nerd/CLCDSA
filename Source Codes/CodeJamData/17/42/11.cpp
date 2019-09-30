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

int S[1024], K[1024];

void solve() {
  int N = in();
  int C = in();
  int M = in();
  fill(K, K + C, 0);
  fill(S, S + N, 0);
  for (int i = 0; i < M; ++i) {
    int p = in() - 1;
    int b = in() - 1;
    ++S[p];
    ++K[b];
  }

  int Y = *max_element(K, K + C);
  int ks = 0;
  for (int i = 0; i < N; ++i) {
    ks += S[i];
    chmax(Y, (ks + i) / (i + 1));
  }

  int Z = 0;
  for (int i = 0; i < N; ++i) {
    Z += max(0, S[i] - Y);
  }

  printf("%d %d\n", Y, Z);
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
