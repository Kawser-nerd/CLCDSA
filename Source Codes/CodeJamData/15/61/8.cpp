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

int N, A[1 << 20];
char S[1 << 20];
int L[10][1 << 20], R[10][1 << 20];
int CL[1 << 20], CR[1 << 20];

void solve() {
  scanf("%s", S);
  N = strlen(S);
  for (int i = 0; i < N; ++i) {
    A[i] = S[i] - '0';
  }

  for (int V = 1; ; ++V) {
    int iv = V % 10;
    for (int i = 0; i < N; ++i) {
      L[iv][i] = INF; R[iv][i] = -INF;
    }
    for (int i = 0; i < N; ++i) {
      if (V < A[i]) {
        CL[i] = INF; CR[i] = -INF;
      } else if (V == A[i]) {
        CL[i] = CR[i] = i;
      } else {
        int r = (V - A[i]) % 10;
        CL[i] = min(i, (i == 0 ? 0 : L[r][i - 1]));
        CR[i] = max(i, (i == N-1 ? N-1 : R[r][i + 1]));
      }
      if (CL[i] == 0 && CR[i] == N - 1) {
        printf(" %d\n", V);
        return;
      }
      if (CL[i] < INF) {
        chmin(L[iv][CR[i]], CL[i]);
        chmax(R[iv][CL[i]], CR[i]);
      }
    }
    for (int i = 1; i < N; ++i) {
      chmax(R[iv][i], R[iv][i - 1]);
    }
    for (int i = N - 2; i >= 0; --i) {
      chmin(L[iv][i], L[iv][i + 1]);
    }
  }
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d:", CN);
    solve();
    fflush(stdout);
  }

  return 0;
}
