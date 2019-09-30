#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 1005;
int n[2], m;
int deg[2][maxn];

int read() {
  if (scanf("%d%d%d", &n[0], &n[1], &m) < 3) {
    return false;
  }
  for (int it = 0; it < 2; it++) {
    for (int i = 0; i < n[it]; i++) {
      deg[it][i] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    deg[0][v]++;
    deg[1][u]++;
  }
  return true;
}

void solve() {
  for (int res = 0; res < maxn; res++) {
    bool ok = true;
    for (int i = 0; i < n[1]; i++) {
      if (deg[1][i] > res) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    int need = 0;
    int bal = 0;
    for (int i = 0; i < n[0]; i++) {
      if (deg[0][i] < res) {
        bal += res - deg[0][i];
      } else {
        int x = deg[0][i] - res;
        if (x > bal) {
          ok = false;
          break;
        }
        need += x;
        bal -= x;
      }
    }
    if (!ok) {
      continue;
    }
    printf("%d %d\n", res, need);
    return;
  }
  assert(false);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  t = 0;
  while (read()) {
    t++;
    printf("Case #%d: ", t);
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
