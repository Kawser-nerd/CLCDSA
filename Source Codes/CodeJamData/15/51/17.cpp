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

int D;
int S[1 << 20];
vector<int> nxt[1 << 20];

int A[1 << 20];

void solve() {
  int N = in();
  D = in();
  int S0 = in();
  int AS = in();
  int CS = in();
  int RS = in();
  int M0 = in();
  int AM = in();
  int CM = in();
  int RM = in();

  for (int i = 0; i < N; ++i) {
    nxt[i].clear();
  }

  for (int i = 0; i < N; ++i) {
    S[i] = S0;
    if (i > 0) {
      nxt[M0 % i].push_back(i);
    }
    S0 = ((Int)S0 * AS + CS) % RS;
    M0 = ((Int)M0 * AM + CM) % RM;
  }

  vector<int> vis(N, 0);
  queue<int> qu, qs, qt;
  qu.push(0); qs.push(S[0] - D); qt.push(S[0]);
  vis[0] = 1;
  memset(A, 0, sizeof(A));
  while (!qu.empty()) {
    int u = qu.front();
    int s = qs.front();
    int t = qt.front();
    qu.pop(); qs.pop(); qt.pop();
    ++A[max(s, 0)];
    --A[t + 1];
    for (const int v : nxt[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        int ss = s, tt = t;
        chmax(ss, S[v] - D);
        chmin(tt, S[v]);
        if (ss <= tt) {
          qu.push(v);
          qs.push(ss);
          qt.push(tt);
        }
      }
    }
  }

  for (int i = 1; i < 1<<20; ++i) {
    A[i] += A[i - 1];
  }

  int res = 0;
  for (int i = S[0] - D; i <= S[0]; ++i) {
    chmax(res, A[i]);
  }

  printf("%d\n", res);
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
