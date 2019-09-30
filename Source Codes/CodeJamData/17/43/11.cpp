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

const int DR[] = {0, -1, 0, 1}, DC[] = {1, 0, -1, 0};

int R, C;
char F[128][128];
int P[128][128][2], SD[128][128][2];

bool traverse(int id, int sr, int sc, int sd) {
  int init_d = sd;
  while (true) {
    int rr = sr + DR[sd];
    int cc = sc + DC[sd];
    if (F[rr][cc] == '#') {
      break;
    }

    int dd = sd;
    if (F[rr][cc] == '/') dd ^= 1;
    if (F[rr][cc] == '\\')dd ^= 3;

    if (F[rr][cc] == '-' || F[rr][cc] == '|') {
      return false;
    }

    if (F[rr][cc] == '.') {
      P[rr][cc][dd & 1] = id;
      SD[rr][cc][dd & 1] = init_d & 1;
    }
    sr = rr;
    sc = cc;
    sd = dd;
  }
  return true;
}

struct edge {
  int src, dst;
  edge(int s, int d) : src(s), dst(d) { }
};
typedef vector<edge> edges;
typedef vector<edges> graph;
#define VAR(x) ((x)<<1)
#define NOT(x) ((x)^1)

void visit(int v, const graph &g,
    vector<int> &ord, vector<int> &num, int k) {
  if (num[v] >= 0) return;
  num[v] = k;
  for (int i = 0; i < g[v].size(); ++i)
    visit(g[v][i].dst, g, ord, num, k);
  ord.push_back(v);
}

typedef pair<int,int> clause;
bool two_satisfiability(int m, const vector<clause> &cs) {
  int n = m * 2; // m positive vars and m negative vars
  graph g(n), h(n);
  for (int i = 0; i < cs.size(); ++i) {
    int u = cs[i].first, v = cs[i].second;
    g[NOT(u)].push_back( edge(NOT(u), v) );
    g[NOT(v)].push_back( edge(NOT(v), u) );
    h[v].push_back( edge(v, NOT(u)) );
    h[u].push_back( edge(u, NOT(v)) );
  }
  vector<int> num(n, -1), ord, dro;
  for (int i = 0; i < n; ++i)
    visit(i, g, ord, num, i);
  reverse(ord.begin(), ord.end());
  fill(num.begin(), num.end(), -1);
  for (int i = 0; i < n; ++i)
    visit(ord[i], h, dro, num, i);
  for (int i = 0; i < n; ++i)
    if (num[i] == num[NOT(i)])
      return false;
  return true;
}

void solve() {
  R = in();
  C = in();
  memset(F, '#', sizeof(F));
  for (int i = 1; i <= R; ++i) {
    char buf[128];
    scanf("%s", buf);
    for (int j = 1; j <= C; ++j) {
      F[i][j] = buf[j - 1];
      P[i][j][0] = P[i][j][1] = -1;
    }
  }

  vector<int> pr, pc;
  vector<clause> fml;
  int LS = 0;
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      if (F[i][j] == '-' || F[i][j] == '|') {
        bool hori = true, vert = true;
        hori &= traverse(LS, i, j, 0);
        hori &= traverse(LS, i, j, 2);
        vert &= traverse(LS, i, j, 1);
        vert &= traverse(LS, i, j, 3);
        if (!hori && !vert) {
          puts("IMPOSSIBLE");
          return;
        } else if (!hori) {
          fml.emplace_back(NOT(VAR(LS)), NOT(VAR(LS)));
        } else if (!vert) {
          fml.emplace_back(VAR(LS), VAR(LS));
        }
        pr.push_back(i);
        pc.push_back(j);
        ++LS;
      }
    }
  }

  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      if (F[i][j] == '.') {
        if (P[i][j][0] == -1 && P[i][j][1] == -1) {
          puts("IMPOSSIBLE");
          return;
        } else if (P[i][j][0] >= 0 && P[i][j][1] >= 0) {
          fml.emplace_back(VAR(P[i][j][0]) ^ SD[i][j][0], VAR(P[i][j][1]) ^ SD[i][j][1]);
        } else {
          int k = P[i][j][0] >= 0 ? 0 : 1;
          fml.emplace_back(VAR(P[i][j][k]) ^ SD[i][j][k], VAR(P[i][j][k]) ^ SD[i][j][k]);
        }
      }
    }
  }

  if (!two_satisfiability(LS, fml)) {
    puts("IMPOSSIBLE");
  } else {
    vector<int> as;
    for (int i = 0; i < LS; ++i) {
      fml.emplace_back(VAR(i), VAR(i));
      if (two_satisfiability(LS, fml)) {
        as.push_back(0);
      } else {
        as.push_back(1);
        fml.pop_back();
      }
    }
    for (int i = 0; i < LS; ++i) {
      F[pr[i]][pc[i]] = "-|"[as[i]];
    }
    puts("POSSIBLE");
    for (int i = 1; i <= R; ++i) {
      for (int j = 1; j <= C; ++j) {
        putchar(F[i][j]);
      }
      puts("");
    }
  }
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    cerr<<CN<<endl;
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
