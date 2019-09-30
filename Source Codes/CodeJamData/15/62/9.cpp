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

const Int MO = 1000000007;
Int fact[1 << 21], inv[1 << 21], factinv[1 << 21], perm[1 << 21];

Int comb(int n, int r) {
  return fact[n] * factinv[r] % MO * factinv[n - r] % MO;
}

void solve() {
  int N = in();
  int X = in();

  Int res = 0;
  for (int x = X; x <= N; ++x) {
    (res += comb(N, x) * comb(N, x) % MO * fact[x] % MO * fact[N - x] % MO * perm[N - x] % MO) %= MO;
  }

  printf(" %lld\n", res);
}

int main() {
  int T = in();

  const int LIM = (1 << 21);
  inv[1] = 1;
  for (int i = 2; i < LIM; ++i) {
    inv[i] = MO - MO / i * inv[MO % i] % MO;
  }

  fact[0] = factinv[0] = 1;
  for (int i = 1; i < LIM; ++i) {
    fact[i] = (fact[i - 1] * i) % MO;
    factinv[i] = (factinv[i - 1] * inv[i]) % MO;
  }

  perm[0] = 1;
  perm[1] = 0;
  perm[2] = 1;
  for (int i = 3; i < LIM; ++i) {
    perm[i] = (i - 1) * (perm[i - 1] + perm[i - 2]) % MO;
  }

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d:", CN);
    solve();
  }

  return 0;
}
