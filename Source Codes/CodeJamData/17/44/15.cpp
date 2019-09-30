#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x, ...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef long double ld;

void PreCalc() {
}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

char s[200][200];
int id[200][200];
int view[200][200];
vector<pair<int, int>> sol;
vector<pair<int, int>> att;
int r, c;

bool inside(int x, int y) {
  return 0 <= x && x < r && 0 <= y && y < c;
}

const int MAXT = 10;

int dp[1 << MAXT][1 << MAXT];
int d[200][200];
pair<int, int> p[1 << MAXT][1 << MAXT];

int bfs(int sx, int sy, int m, int mask) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      d[i][j] = -1;
    }
  }
  d[sx][sy] = 0;
  queue<pair<int, int>> q;
  q.push({sx, sy});
  int ans = 0;
  while (!q.empty()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();

    ans |= view[x][y];
    if (view[x][y] & mask) continue;
    if (d[x][y] == m) continue;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (inside(nx, ny) && s[nx][ny] != '#' && d[nx][ny] == -1) {
        d[nx][ny] = d[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
  return ans;
}

void restore(int mt, int ms) {
  if (dp[mt][ms] == 0) return;
  int i, j;
  tie(i, j) = p[mt][ms];
  printf("%d %d\n", i + 1, j + 1);
  restore(mt ^ (1 << j), ms ^ (1 << i));
}

void solve() {
  int m;
  scanf("%d%d%d", &c, &r, &m);
  sol.clear();
  att.clear();

  for (int i = 0; i < r; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < c; j++) {
      if (s[i][j] == 'S') {
        sol.push_back({i, j});
        id[i][j] = (int) sol.size();
      } else if (s[i][j] == 'T') {
        att.push_back({i, j});
        id[i][j] = (int) att.size();
      } else {
        id[i][j] = -1;
      }
      view[i][j] = 0;
    }
  }

  int S = sol.size();
  int T = att.size();

  for (int i = 0; i < T; i++) {
    for (int j = 0; j < 4; j++) {
      int x = att[i].first;
      int y = att[i].second;
      while (inside(x, y) && s[x][y] != '#') {
        view[x][y] |= (1 << i);
        x += dx[j];
        y += dy[j];
      }
    }
  }

  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < (1 << T); i++) {
    vector<int> kmask(S);
    for (int j = 0; j < S; j++) {
      kmask[j] = bfs(sol[j].first, sol[j].second, m, i);
    }
    for (int j = 0; j < (1 << S); j++) {
      for (int k = 0; k < S; k++) {
        if (j & (1 << k)) {
          for (int t = 0; t < T; t++) {
            if ((i & (1 << t)) && (kmask[k] & (1 << t))) {
              int nval = dp[i ^ (1 << t)][j ^ (1 << k)] + 1;
              if (dp[i][j] < nval) {
                dp[i][j] = nval;
                p[i][j] = {k, t};
              }
            }
          }
        }
      }
    }
  }

  int mT = (1 << T) - 1;
  int mS = (1 << S) - 1;
  printf("%d\n", dp[mT][mS]);
  restore(mT, mS);
}


int main() {
#ifdef LOCAL
//  freopen("d.in", "r", stdin);
//  freopen("d.out", "w", stdout);
#endif

  PreCalc();
  TIMESTAMP(PreCalc);

  char buf[1000];
  int testNum;
  fgets(buf, sizeof buf, stdin);
  sscanf(buf, "%d", &testNum);

  for (int testId = 1; testId <= testNum; testId++) {
    if (testId <= 20 || testId >= testNum - 20 || testId % 10 == 0)
      TIMESTAMPf("Test %d", testId);
    printf("Case #%d: ", testId);
    solve();
  }

  TIMESTAMP(end);
  return 0;
}