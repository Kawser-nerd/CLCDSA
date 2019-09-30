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

int P[3333];

void solve() {
  in();
  int A[3], B[3];
  for (int i = 0; i < 3; ++i) {
    A[i] = in();
    B[(i + 2) % 3] = in();
  }
  int over = 0, over_pos = 0;
  for (int i = 0; i < 3; ++i) {
    if (B[i] > 0 && A[i] <= B[i]) {
      over += B[i] - A[i] + 1;
      over_pos = i;
    }
  }

  if (over > 1) {
    puts("IMPOSSIBLE");
    return;
  } else if (over == 1) {
    bool ok = true;
    for (int i = 1; i <= 2; ++i) {
      ok &= A[(over_pos + i) % 3] == 0 && B[(over_pos + i) % 3] == 0;
    }
    if (ok) {
      for (int i = 0; i < A[over_pos]; ++i) {
        printf("%c%c", "RYB"[over_pos], "GVO"[over_pos]);
      }
      puts("");
    } else {
      puts("IMPOSSIBLE");
    }
    return;
  }

  for (int i = 0; i < 3; ++i) {
    A[i] -= B[i];
  }

  int ma = max({A[0], A[1], A[2]});
  int ot = A[0] + A[1] + A[2] - ma;
  if (ma > ot) {
    puts("IMPOSSIBLE");
    return;
  }

  int mi = 0;
  for (int i = 0; i < 3; ++i) {
    if (A[i] == ma) {
      mi = i;
      break;
    }
  }

  fill(P, P + 3333, -1);
  for (int i = 0; i < A[mi]; ++i) {
    P[3 * i] = mi;
  }
  for (int i = 0; i < A[(mi + 1) % 3]; ++i) {
    P[3 * i + 1] = (mi + 1) % 3;
  }
  for (int i = 0; i < A[(mi + 2) % 3]; ++i) {
    P[3 * (A[mi] - i) - 1] = (mi + 2) % 3;
  }

  for (int i = 0; i < 3333; ++i) {
    if (P[i] == -1) {
      continue;
    }
    putchar("RYB"[P[i]]);
    for (int j = 0; j < B[P[i]]; ++j) {
      putchar("GVO"[P[i]]);
      putchar("RYB"[P[i]]);
    }
    B[P[i]] = 0;
  }
  puts("");
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
