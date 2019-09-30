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

int S[1024];
Int MA[1024], MI[1024];

void solve() {
  int N = in();
  int K = in();
  for (int i = 0; i < N - K + 1; ++i) {
    S[i] = in();
  }

  Int largest = 0;
  for (int i = 0; i < K; ++i) {
    MA[i] = MI[i] = 0;
    Int cur = 0;
    for (int j = i + K; j < N; j += K) {
      cur += S[j - K + 1] - S[j - K];
      chmax(MA[i], cur);
      chmin(MI[i], cur);
    }
    chmax(largest, MA[i] - MI[i]);
  }

  Int target = (S[0] % K + K) % K;
  for (int i = 0; i < K; ++i) {
    target += (MI[i] % K + K) % K;
    target %= K;
  }

  Int lo = largest - 1, hi = largest + K;
  while (hi - lo > 1) {
    Int mid = (hi + lo) / 2;
    Int can = 0;
    for (int i = 0; i < K; ++i) {
      can += mid - (MA[i] - MI[i]);   
    }
    if (can >= target) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  printf("%lld\n", hi);
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
