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

Int F;
char S[1 << 20];

Int myabs(Int a) { return a < 0 ? -a : a; }

bool isgood(Int b, Int a, Int d, Int c) {
  return myabs(1000000 * b * c - a * c * F) < myabs(1000000 * a * d - a * c * F);
}

void solve() {
  int N = in();
  int Fz, Ff;
  scanf("%d.%d", &Fz, &Ff);
  F = Fz * 1000000 + Ff;

  scanf("%s", S);
  int bp = 0, bq = 0, bi = 0;
  for (int i = 0; i < N; ++i) {
    int o = 0;
    for (int j = i; j < N; ++j) {
      if (S[j] == '1') {
        ++o;
      }
      if (bq == 0 || isgood(o, j - i + 1, bp, bq)) {
        bp = o;
        bq = j - i + 1;
        bi = i;
      }
    }
  }

  printf(" %d\n", bi);
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d:", CN);
    solve();
  }

  return 0;
}
