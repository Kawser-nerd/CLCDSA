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

namespace MF {
#define MAXN 88888
#define MAXM 888888
#define wint int
#define cint int
#define cdouble double
  int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
  wint capa0[MAXM], capa[MAXM], ex[MAXN];
  cint cost[MAXM];
  cdouble pot[MAXN];
  bool vis[MAXN];
  int itr[MAXN], lev[MAXN], que[MAXN], *qb, *qe;
  void init(int _n) {
    n = _n; m = 0; memset(ptr, ~0, n * 4); memset(ex, 0, n * sizeof(wint));
  }
  void ae(int u, int v, wint w, cint c) {
    next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa0[m] = capa[m] = w; cost[m] = +c; ++m;
    next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa0[m] = capa[m] = 0; cost[m] = -c; ++m;
  }
  wint augment(int u, int t, wint flo) {
    if (u == t) return flo;
    wint f;
    for (int &i = itr[u]; ~i; i = next[i]) if (capa[i] > 0 && lev[u] < lev[zu[i]]) {
      if ((f = augment(zu[i], t, min(flo, capa[i]))) > 0) {
        capa[i] -= f; capa[i ^ 1] += f; return f;
      }
    }
    return 0;
  }
  wint augment(int u, wint flo) {
    wint f;
    if (ex[u] < 0) {
      f = min(flo, -ex[u]); ex[u] += f; return f;
    }
    for (int &i = itr[u]; ~i; i = next[i]) if (capa[i] > 0 && cost[i] + pot[u] - pot[zu[i]] < 0) {
      if ((f = augment(zu[i], min(flo, capa[i]))) > 0) {
        capa[i] -= f; capa[i ^ 1] += f; return f;
      }
    }
    return 0;
  }
  wint dinic(int s, int t, wint flo) {
    int i, u, v;
    wint tof = 0, f;
    for (; tof < flo;) {
      qb = qe = que; memset(lev, ~0, n * 4); memcpy(itr, ptr, n * 4);
      for (lev[*qe++ = s] = 0; qb != qe;) {
        for (i = ptr[u = *qb++]; ~i; i = next[i]) if (capa[i] > 0 && !~lev[v = zu[i]]) {
          lev[*qe++ = v] = lev[u] + 1;
        }
      }
      if (!~lev[t]) break;
      for (; (f = augment(s, t, flo - tof)) > 0;) tof += f;
    }
    return tof;
  }
  void dfs(int u) {
    if (vis[u]) return; vis[u] = 1;
    for (int i = ptr[u]; ~i; i = next[i]) if (capa[i] > 0 && cost[i] + pot[u] - pot[zu[i]] < 0) {
      dfs(zu[i]);
    }
  }
  cint solve() {
    int i, u;
    wint f;
    cdouble eps = 0;
    for (i = 0; i < m; ++i) if (capa[i] > 0) chmax(eps, (cdouble)-cost[i]);
    for (; eps * n >= 1;) {
      eps /= 4;
      for (i = 0; i < m; ++i) if (capa[i] > 0 && cost[i] + pot[zu[i ^ 1]] - pot[zu[i]] < 0) {
        ex[zu[i ^ 1]] -= capa[i]; ex[zu[i]] += capa[i]; capa[i ^ 1] += capa[i]; capa[i] = 0;
      }
      for (;;) {
        memset(vis, 0, n); memcpy(itr, ptr, n * 4);
        for (u = 0; u < n; ++u) if (ex[u] > 0) dfs(u);
        for (u = 0; u < n; ++u) if (vis[u]) pot[u] -= eps;
        for (u = 0; u < n; ++u) for (; ex[u] > 0 && (f = augment(u, ex[u])) > 0;) ex[u] -= f;
        for (u = 0; u < n; ++u) if (ex[u] > 0) break;
        if (u == n) break;
      }
    }
    cint toc = 0;
    for (i = 0; i < m; ++i) if (capa0[i] > capa[i]) toc += (capa0[i] - capa[i]) * cost[i];
    return toc;
  }
}

int adj[128][128], dist[128][128];

void solve() {
  int N, M, K;
  N = in();
  M = in();
  K = in();

  memset(adj, 0, sizeof(adj));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      dist[i][j] = i == j ? 0 : INF;
    }
  }
  for (int i = 0; i < M; ++i) {
    int a = in();
    int b = in();
    adj[a][b] = adj[b][a] = 1;
    dist[a][b] = dist[b][a] = 1;
  }

  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (adj[i][j] && dist[0][i] + dist[j][N - 1] + 1 != dist[0][N - 1]) {
        adj[i][j] = 0;
      }
    }
  }

  int res = dist[0][N - 1] + 1;
  --K;

  MF::init(2 * N);
  #define I(v) (v)
  #define O(v) ((v==0 || v==N-1) ? v : (v + N))
  for (int i = 0; i < N; ++i) {
    if (I(i) != O(i)) {
      MF::ae(I(i), O(i), 1, 0);
    }
    for (int j = 0; j < N; ++j) {
      if (adj[i][j]) {
        MF::ae(O(i), I(j), INF, 0);
      }
    }
  }

  if (MF::dinic(0, N - 1, INF) <= K) {
    ++res;
  }

  printf(" %d\n", res);
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d:", CN);
    solve();
  }

  return 0;
}
