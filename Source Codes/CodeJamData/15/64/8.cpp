#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

class Solver {
  struct Edge {
    int to, ne, w;
  };

  vi firs;
  vector<Edge> es;
  int en;
  vi was;
  int wver;

  bool dfs(int v) {
    if (v == en) return true;
    if (was[v] >= wver) return false;
    was[v] = wver;
    for (int i = firs[v]; i >= 0; i = es[i].ne) if (es[i].w > 0) {
      if (dfs(es[i].to)) {
        es[i].w--;
        es[i ^ 1].w++;
        return true;
      }
    }
    return false;
  }
public:
  Solver(int n) : firs(n, -1), es() {}
  void adde(int a, int b, int w) {
    es.pb({b, firs[a], w}); firs[a] = sz(es) - 1;
    es.pb({a, firs[b], 0}); firs[b] = sz(es) - 1;
  }
  int solve(int st, int _en) {
    en = _en;
    was = vi(sz(firs), 0);
    wver = 0;
    int fl = 0;
    for (;;) {
      wver++;
      if (!dfs(st)) break;
      fl++;
    }
    return fl;
  }
};

const int inf = int(1e9);
const int FINF = 1000;

void solve() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vvi es(n);
  vvi g(n, vi(n, inf));
  forn (i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    es[a].pb(b);
    es[b].pb(a);
    g[a][b] = g[b][a] = 1;
  }
  assert(k >= 1);

  forn (i, n) g[i][i] = 0;
  forn (i, n)
  forn (j, n)
  forn (k, n)
    g[j][k] = min(g[j][k], g[j][i] + g[i][k]);

  Solver s(2 * n);
  forn (i, n) {
    s.adde(2 * i, 2 * i + 1, 1);
    for (int b : es[i])
      if (g[0][i] + 1 == g[0][b]) {
        s.adde(2 * i + 1, 2 * b, FINF);
      }
  }
  int fl = s.solve(1, 2 * n - 2);
  if (fl <= k - 1) {
    printf("%d\n", g[0][n - 1] + 2);
  } else {
    printf("%d\n", g[0][n - 1] + 1);
  }
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "";
    if (argc >= 2) fn = argv[1];
    if (endsWith(fn, ".in")) fn = string(fn, 0, fn.length() - 3);
    assert(freopen((fn + ".in").c_str(), "r", stdin));
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  int MARK;
  assert(scanf("%d", &MARK) >= 1);

  int START = 1, TC = MARK;
  if (MARK < 0) {
    START = TC = -MARK;
  }
  for (int TN = START; TN <= TC; TN++) {
    eprintf("Case #%d:\n", TN);
    printf("Case #%d: ", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Caught exception at test case #%d\n", TN);
      return 1;
    }
    fflush(stdout);
    fflush(stderr);
  }
  return 0;
}
