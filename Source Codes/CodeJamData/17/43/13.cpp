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

const int maxn = 505;
int h, w;
char c[maxn][maxn];

int read() {
  if (scanf("%d%d", &h, &w) < 2) {
    return false;
  }
  for (int i = 0; i < w + 2; i++) {
    c[0][i] = '#';
  }
  for (int i = 1; i <= h; i++) {
    c[i][0] = '#';
    scanf("%s", c[i] + 1);
    c[i][w + 1] = '#';
  }
  for (int i = 0; i < w + 2; i++) {
    c[h + 1][i] = '#';
  }
  h += 2;
  w += 2;
  return true;
}

int ids[maxn][maxn];
pair<int, int> ps[maxn];
vector<int> bs[maxn][maxn][2];
vector<int> g[maxn];
vector<int> gr[maxn];

void addEdge(int v, int u) {
  g[v ^ 1].push_back(u);
  gr[u].push_back(v ^ 1);
  g[u ^ 1].push_back(v);
  gr[v].push_back(u ^ 1);
}

const int gox[] = {1, 0, -1, 0};
const int goy[] = {0, 1, 0, -1};

void go(int x, int y, int dir, int t, int sid) {
  if (c[x][y] == '/') {
    dir ^= 3;
  } else if (c[x][y] == '\\') {
    dir ^= 1;
  }
  if (c[x][y] == '.') {
    bs[x][y][(dir & 1)].push_back(2 * sid + t);
  }
  int nx = x + gox[dir], ny = y + goy[dir];
  if (c[nx][ny] == '#') {
    return;
  } else if (c[nx][ny] == '-') {
    addEdge(2 * sid + (t ^ 1), 2 * sid + (t ^ 1));
  } else {
    go(nx, ny, dir, t, sid);
  }
}

vector<int> p;
int used[maxn];

void dfs0(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (!used[u]) {
      dfs0(u);
    }
  }
  p.push_back(v);
}

int col[maxn];
int take[maxn];
vector<int> cs[maxn];

void dfs(int v, int c) {
  col[v] = c;
  cs[c].push_back(v);
  for (int i = 0; i < sz(gr[v]); i++) {
    int u = gr[v][i];
    if (col[u] == -1) {
      dfs(u, c);
    }
  }
}

void solve() {
  int n = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      for (int it = 0; it < 2; it++) {
        bs[i][j][it].clear();
      }
      ids[i][j] = -1;
      if (c[i][j] == '|') {
        c[i][j] = '-';
      }
      if (c[i][j] == '-') {
        ids[i][j] = n;
        ps[n] = make_pair(i, j);
        n++;
      }
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    g[i].clear();
    gr[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int sx = ps[i].first, sy = ps[i].second;
    for (int dir = 0; dir < 4; dir++) {
      go(sx, sy, dir, (dir & 1), i);
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (c[i][j] == '.') {
        int v = -1, u = -1;
        for (int it = 0; it < 2; it++) {
          auto &cur = (!it ? v : u);
          if (sz(bs[i][j][it]) == 1) {
            cur = bs[i][j][it][0];
          }
        }
        if (v == -1) {
          if (u == -1) {
            printf("IMPOSSIBLE\n");
            return;
          }
          addEdge(u, u);
        } else if (u == -1) {
          addEdge(v, v);
        } else {
          addEdge(v, u);
        }
      }
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    used[i] = false;
  }
  p.clear();
  for (int i = 0; i < 2 * n; i++) {
    if (!used[i]) {
      dfs0(i);
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    col[i] = -1;
  }
  int curc = 0;
  for (int i = 2 * n - 1; i >= 0; i--) {
    int v = p[i];
    if (col[v] == -1) {
      cs[curc].clear();
      dfs(v, curc++);
    }
  }
  for (int i = 0; i < 2 * n; i += 2) {
    if (col[i] == col[i + 1]) {
      printf("IMPOSSIBLE\n");
      return;
    }
  }
  printf("POSSIBLE\n");
  for (int i = curc - 1; i >= 0; i--) {
    if (col[cs[i][0] ^ 1] > col[cs[i][0]]) {
      continue;
    }
    for (int j = 0; j < sz(cs[i]); j++) {
      int v = cs[i][j];
      take[v >> 1] = (v & 1);
    }
  }
  for (int i = 0; i < n; i++) {
    int x = ps[i].first, y = ps[i].second;
    if (take[i] == 0) {
      c[x][y] = '|';
    } else {
      c[x][y] = '-';
    }
  }
  for (int i = 1; i < h - 1; i++) {
    string row;
    for (int j = 1; j < w - 1; j++) {
      row += c[i][j];
    }
    printf("%s\n", row.c_str());
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
