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

const int maxn = 12;
const int pown = (1 << maxn);
const int maxh = 105;
int h, w, maxd;
char c[maxh][maxh];

int read() {
  if (scanf("%d%d%d", &w, &h, &maxd) < 3) {
    return false;
  }
  for (int i = 0; i < h; i++) {
    scanf("%s", c[i]);
  }
  return true;
}

int sids[maxh][maxh];
int tids[maxh][maxh];
pair<int, int> ss[maxn];
pair<int, int> ts[maxn];
int can[pown][maxn];
int d[maxh][maxh];

const int gox[] = {1, 0, -1, 0};
const int goy[] = {0, 1, 0, -1};

bool inside(int x, int y) {
  return 0 <= x && x < h && 0 <= y && y < w;
}

int shoot(int x, int y, int alive) {
  int res = 0;
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + gox[dir], ny = y + goy[dir];
    while (inside(nx, ny) && c[nx][ny] != '#') {
      if (c[nx][ny] == 'T' && (alive & (1 << tids[nx][ny]))) {
        res |= (1 << tids[nx][ny]);
      }
      nx += gox[dir];
      ny += goy[dir];
    }
  }
  return res;
}

int go(int sx, int sy, int alive) {
  vector< pair<int, int> > q;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      d[i][j] = inf;
    }
  }
  d[sx][sy] = 0;
  q.push_back(make_pair(sx, sy));
  int res = 0;
  for (int l = 0; l < sz(q); l++) {
    int x = q[l].first, y = q[l].second;
    int sh = shoot(x, y, alive);
    res |= sh;
    if (sh) {
      continue;
    }
    if (d[x][y] >= maxd) {
      continue;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + gox[dir], ny = y + goy[dir];
      if (!inside(nx, ny) || c[nx][ny] == '#' || (c[nx][ny] == 'T' && (alive & (1 << tids[nx][ny]))) || d[nx][ny] < inf) {
        continue;
      }
      d[nx][ny] = d[x][y] + 1;
      q.push_back(make_pair(nx, ny));
    }
  }
  return res;
}

int dp[pown][pown];

void solve() {
  int n = 0, m = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      sids[i][j] = -1;
      tids[i][j] = -1;
      if (c[i][j] == 'S') {
        sids[i][j] = n;
        ss[n] = make_pair(i, j);
        n++;
      } else if (c[i][j] == 'T') {
        tids[i][j] = m;
        ts[m] = make_pair(i, j);
        m++;
      }
    }
  }
  for (int msk = 0; msk < (1 << m); msk++) {
    for (int i = 0; i < n; i++) {
      int x = ss[i].first, y = ss[i].second;
      can[msk][i] = go(x, y, msk);
    }
  }
  memset(dp, -1, sizeof(dp));
  dp[(1 << n) - 1][(1 << m) - 1] = -2;
  int msk0 = (1 << n) - 1, msk1 = (1 << m) - 1;
  for (int smsk = (1 << n) - 1; smsk >= 0; smsk--) {
    for (int tmsk = (1 << m) - 1; tmsk >= 0; tmsk--) {
      auto cur = dp[smsk][tmsk];
      if (cur == -1) {
        continue;
      }
      if (__builtin_popcount(tmsk) < __builtin_popcount(msk1)) {
        msk0 = smsk;
        msk1 = tmsk;
      }
      for (int i = 0; i < n; i++) {
        if (!(smsk & (1 << i))) {
          continue;
        }
        for (int j = 0; j < m; j++) {
          if (!(tmsk & (1 << j)) || !(can[tmsk][i] & (1 << j))) {
            continue;
          }
          dp[smsk ^ (1 << i)][tmsk ^ (1 << j)] = i * maxn + j;
        }
      }
    }
  }
  vector< pair<int, int> > ans;
  while (msk0 < (1 << n) - 1) {
    auto cur = dp[msk0][msk1];
    assert(cur != -1);
    int s = cur / maxn;
    int t = cur % maxn;
    ans.push_back(make_pair(s, t));
    msk0 |= (1 << s);
    msk1 |= (1 << t);
  }
  reverse(ans.begin(), ans.end());
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  }
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
