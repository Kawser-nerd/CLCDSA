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

const int maxp = 4;
int n, p;
vector<int> cnt0;

int read() {
  if (scanf("%d%d", &n, &p) < 2) {
    return false;
  }
  cnt0.clear();
  cnt0.resize(p);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    x %= p;
    cnt0[x]++;
  }
  return true;
}

map<pair<int, vector<int> >, int> mem;

int rec(vector<int> cnt, int r) {
  if (mem.count(make_pair(r, cnt))) {
    return mem[make_pair(r, cnt)];
  }
  auto &cur = mem[make_pair(r, cnt)];
  cur = 0;
  for (int i = 0; i < p; i++) {
    if (!cnt[i]) {
      continue;
    }
    vector<int> ncnt = cnt;
    ncnt[i]--;
    int nr = (r + i) % p;
    cur = max(cur, rec(ncnt, nr) + (!r));
  }
  return cur;
}

void solve() {
  mem.clear();
  int res = rec(cnt0, 0);
  printf("%d\n", res);
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
