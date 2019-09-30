#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);

const int mod = (int) 1e9 + 7;

void add(int &x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int mult(int x, int y) {
  return (long long) x * y % mod;
}

int power(int x, int pw) {
  int res = 1;
  for (; pw; pw >>= 1) {
    if (pw & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
  }
  return res;
}

void precalc() {
}


const int maxn = 110;
int dist[maxn][maxn];

int n, q;

int go[maxn][2];

int read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &go[i][0], &go[i][1]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", dist[i] + j);
      if (dist[i][j] == -1) {
        dist[i][j] = inf;
      }
    }
  }
  return 1;
}

int used[maxn];
ld ans[maxn];

void solve() {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int iter = 0; iter < q; ++iter) {
    int S, T;
    scanf("%d%d", &S, &T);
    --S, --T;

    for (int i = 0; i < n; ++i) {
      ans[i] = 1e18;
      used[i] = 0;
    }
    ans[S] = 0;

    for (int iter = 0; iter < n; ++iter) {
      int v = -1;
      for (int i = 0; i < n; ++i) {
        if (used[i]) {
          continue;
        }
        if (v == -1 || ans[v] > ans[i]) {
          v = i;
        }
      }

      used[v] = 1;
      for (int u = 0; u < n; ++u) {
        if (used[u] || dist[v][u] > go[v][0]) {
          continue;
        }
        auto nval = ans[v] + ((ld) dist[v][u] / go[v][1]);
        if (ans[u] > nval) {
          ans[u] = nval;
        }
      }
    }

    printf("%.18f%c", (double) ans[T], " \n"[iter == q - 1]);
  }
}

int main() {
  precalc();
#ifdef LOCAL
  freopen(TASK ".out", "w", stdout);
  assert(freopen(TASK ".in", "r", stdin));
#endif

  int t;
  scanf("%d", &t);
  t = 0;
  while (1) {
    if (!read()) {
      break;
    }
    printf("Case #%d: ", ++t);
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
