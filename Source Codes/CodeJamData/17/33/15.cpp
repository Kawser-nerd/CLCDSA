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

const ld eps = 1e-9;
const int maxn = 60;

int n, k;
ld u;
ld p[maxn];

ld readld() {
  double tmp;
  scanf("%lf", &tmp);
  return tmp;
}

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  u = readld();
  for (int i = 0; i < n; ++i) {
    p[i] = readld();
  }
  return true;
}

void solve() {
  sort(p, p + n);
  p[n] = 1;

  ld res = 0;

  for (int i = 0; i < n; ++i) {
    ld need = 0;
    for (int j = 0; j < i; ++j) {
      need += p[i] - p[j];
    }

    if (need > u + eps) {
      break;
    }
    ld np = min(p[i] + (u - need) / (i + 1), (ld) 1);
    ld cur = 1;
    for (int j = 0; j < n; ++j) {
      cur *= (j <= i ? np : p[j]);
    }

    res = max(res, cur);
  }

  printf("%.10f\n", (double) res);
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


