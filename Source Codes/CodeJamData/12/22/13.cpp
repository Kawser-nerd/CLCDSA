#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    //puts("");
    solve();
  }
}

struct State {
  int x;
  int y;
  ll t;
  State() {;}
  State(int x, int y, ll t) : x(x), y(y), t(t) {;}
  bool operator<(const State &rhs) const {
    return t > rhs.t;
  }
};

int H, h, w;
int ceils[110][110];
int floors[110][110];

bool NeedWait(int fx, int fy, int tx, int ty) {
  ll water = H;
  if (ceils[ty][tx] - floors[ty][tx] < 50 ||
      ceils[ty][tx] - floors[fy][fx] < 50 ||
      ceils[fy][fx] - floors[ty][tx] < 50 ||
      ceils[ty][tx] - water < 50) { return true; }
  return false;
}

ll MoveTime(int fx, int fy, int tx, int ty, ll t) {
  ll water = max(0LL, H - t);
  if (ceils[ty][tx] - floors[ty][tx] < 50 ||
      ceils[ty][tx] - floors[fy][fx] < 50 ||
      ceils[fy][fx] - floors[ty][tx] < 50) { return 1LL << 50; }
  t += max(0LL, 50 + water - ceils[ty][tx]);
  water = max(0LL, H - t);
  if (water - floors[fy][fx] >= 20) {
    t += 10;
  } else {
    t += 100;
  }
  return t;
}

bool visit[110][110];
ll dist[110][110];
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

void solve() {
  MEMSET(dist, 0x0f);
  MEMSET(visit, false);
  scanf("%d %d %d", &H, &h, &w);
  REP(y, h) {
    REP(x, w) {
      scanf("%d", &ceils[y][x]);
    }
  }
  REP(y, h) {
    REP(x, w) {
      scanf("%d", &floors[y][x]);
    }
  }
  priority_queue<State> que;
  que.push(State(0, 0, 0));
  dist[0][0] = 0;
  while (!que.empty()) {
    State s = que.top();
    que.pop();
    if (visit[s.y][s.x]) { continue; }
    visit[s.y][s.x] = true;
    REP(dir, 4) {
      int nx = s.x + dx[dir];
      int ny = s.y + dy[dir];
      if (nx < 0 || nx >= w || ny < 0 || ny >= h || visit[ny][nx]) { continue; }
      if (NeedWait(s.x, s.y, nx, ny)) { continue; }
      dist[ny][nx] = 0;
      que.push(State(nx, ny, 0));
    }
  }
  REP(y, h) {
    REP(x, w) {
      if (dist[y][x] == 0) { que.push(State(x, y, 0)); }
    }
  }
  MEMSET(visit, false);
  ll ans = 1LL << 40;;
  while (!que.empty()) {
    State s = que.top();
    que.pop();
    if (visit[s.y][s.x]) { continue; }
    visit[s.y][s.x] = true;
    if (s.x == w - 1 && s.y == h - 1) {
      ans = s.t;
      break;
    }
    REP(dir, 4) {
      int nx = s.x + dx[dir];
      int ny = s.y + dy[dir];
      ll nt = MoveTime(s.x, s.y, nx, ny, s.t);
      if (nx < 0 || nx >= w || ny < 0 || ny >= h || visit[ny][nx]) { continue; }
      if (dist[ny][nx] <= nt) { continue; }
      dist[ny][nx] = nt;
      que.push(State(nx, ny, nt));
    }
  }
  printf("%lld.%lld\n", ans / 10, ans % 10);
}
