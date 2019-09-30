#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

inline int rnd(int x) {
  return myrand() % x;
}

#ifdef LOCAL
#define LLD "%lld"
#else
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#endif

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stdout)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define TASK "text"

void precalc() {
}

const int inf = 1.01e9;
const int t = 24 * 60;

bool used[2][t];

bool read() {
  int n[2];
  if (scanf("%d%d", &n[0], &n[1]) < 2) {
    return false;
  }
  memset(used, 0, sizeof(used));
  for (int it = 0; it < 2; ++it) {
    for (int i = 0; i < n[it]; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      for (int j = l; j < r; ++j) {
        used[it][j] = true;
      }
    }
  }
  return true;
}

int dp[2][2][t][t];

void solve() {
  for (int it = 0; it < 2; ++it) {
    for (int it2 = 0; it2 < 2; ++it2) {
      for (int a = 0; a < t; ++a) {
        for (int b = 0; b < t; ++b) {
          dp[it][it2][a][b] = inf;
        }
      }
    }
  }

  dp[0][0][0][0] = 0;
  dp[1][1][0][0] = 0;

  for (int s = 0; s < t; ++s) {
    for (int a = 0; a <= s; ++a) {
      int b = s - a;

      for (int st = 0; st < 2; ++st) {
        for (int cur = 0; cur < 2; ++cur) {
          int cdp = dp[st][cur][a][b];
          if (!used[cur][s]) {
            int & ndp = dp[st][cur][a + 1][b];
            ndp = min(ndp, cdp);
          }
          if (!used[1 - cur][s]) {
            int & ndp = dp[st][1 - cur][b + 1][a];
            ndp = min(ndp, cdp + 1);
          }
        }
      }
    }
  }

  int res = inf;

  for (int st = 0; st < 2; ++st) {
    for (int cur = 0; cur < 2; ++cur) {
      int cres = dp[st][cur][t / 2][t / 2];
      if (cres == inf) {
        continue;
      }
      if (st != cur) {
        ++cres;
      }
      assert(cres % 2 == 0);
      res = min(res, cres);
    }
  }

  printf("%d\n", res);
}

int main() {
  srand(rdtsc());
  precalc();
#ifdef LOCAL 
  assert(freopen(TASK".out", "w", stdout));
  assert(freopen(TASK".in", "r", stdin));
#endif

  int T;
  scanf("%d", &T);

  for (int tn = 0; tn < T; ++tn) {
    assert(read());
    printf("Case #%d: ", tn + 1);
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}


