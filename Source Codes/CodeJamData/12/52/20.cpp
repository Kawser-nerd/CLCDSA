#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <map>

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


struct UnionFind {
  int parent[20010];
  int corner[20010];
  int edge[20010];
  UnionFind() {
    memset(parent, -1, sizeof(parent));
    MEMSET(corner, 0);
    MEMSET(edge, 0);
  }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) { return false; }
    if (parent[y] < parent[x]) { swap(x, y); }
    parent[x] += parent[y];
    corner[x] |= corner[y];
    edge[x] |= edge[y];
    parent[y] = x;
    return true;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
};

UnionFind ufind;
map<pair<int, int>, int> mapto;
map<int, pair<int, int> > revmap;
int s, m;
bool end;
char ans[1000];
const int dx[6] = { 1, 0, -1, -1, 0, 1 };
const int dy[6] = { 0, -1, -1, 0, 1, 1 };

int Corner(int x, int y) {
  if (x == 1 && y == 1) { return 1 << 0; }
  if (x == s && y == 1) { return 1 << 1; }
  if (x == s * 2 - 1 && y == s) { return 1 << 2; }
  if (x == s * 2 - 1 && y == s * 2 - 1) { return 1 << 3; }
  if (x == s && y == s * 2 - 1) { return 1 << 4; }
  if (x == 1 && y == s) { return 1 << 5; }
  return 0;
}

int Edge(int x, int y) {
  if (Corner(x, y) != 0) { return 0; }
  int z = x - y;
  if (x == 1) { return 1 << 0; }
  if (x == 2 * s - 1) { return 1 << 1; }
  if (y == 1) { return 1 << 2; }
  if (y == 2 * s - 1) { return 1 << 3; }
  if (z == s - 1) { return 1 << 4; }
  if (z == -s + 1) { return 1 << 5; }
  return 0;
}

bool IsRing(int x, int y) {
  REP(dir1, 6) {
    int nx1 = x + dx[dir1];
    int ny1 = y + dy[dir1];
    if (!mapto.count(make_pair(nx1, ny1))) { continue; }
    REP(dir2, dir1 - 1) {
      int nx2 = x + dx[dir2];
      int ny2 = y + dy[dir2];
      if (!mapto.count(make_pair(nx2, ny2))) { continue; }
      if (!ufind.findSet(mapto[make_pair(nx1, ny1)], mapto[make_pair(nx2, ny2)])) { continue; }
      bool connect1 = true;
      bool connect2 = true;
      FOR(dir3, dir2 + 1, dir1) {
        int nx3 = x + dx[dir3];
        int ny3 = y + dy[dir3];
        if (!mapto.count(make_pair(nx3, ny3))) { connect1 = false; break; }
      }
      FOR(dir3, dir1 + 1, dir2 + 6) {
        int nx3 = x + dx[dir3 % 6];
        int ny3 = y + dy[dir3 % 6];
        if (!mapto.count(make_pair(nx3, ny3))) { connect2 = false; break; }
      }
      if (!connect1 && !connect2) { return true; }
    }
  }
  return false;
}

void IsEnd(int turn, bool ring, bool fork, bool bridge) {
  end |= ring | fork | bridge;
  string s;
  if (bridge) { s += "bridge"; }
  if (fork) {
    if (s != "") { s += "-"; }
    s += "fork";
  }
  if (ring) {
    if (s != "") { s += "-"; }
    s += "ring";
  }
  sprintf(ans, "%s in move %d", s.c_str(), turn + 1);
}

void solve() {
  MEMSET(ans, 0);
  ufind = UnionFind();
  mapto.clear();
  revmap.clear();
  end = false;
  scanf("%d %d", &s, &m);
  REP(i, m) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (end) { continue; }

    mapto[make_pair(x, y)] = i;
    revmap[i] = make_pair(x, y);
    ufind.corner[i] |= Corner(x, y);
    ufind.edge[i] |= Edge(x, y);
    //cout << x << " " << y << " " << Edge(x, y) << endl;
    int from = i;
    bool ring = IsRing(x, y);
    REP(dir, 6) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (!mapto.count(make_pair(nx, ny))) { continue; }
      int to = mapto[make_pair(nx, ny)];
      ufind.unionSet(from, to);
    }
    int root = ufind.root(from);
    bool fork = __builtin_popcount(ufind.edge[root]) >= 3;
    bool bridge = __builtin_popcount(ufind.corner[root]) >= 2;
    //cout << __builtin_popcount(ufind.edge[root]) << endl;
    //cout << __builtin_popcount(ufind.corner[root]) << endl;
    //cout << fork << " " << bridge << endl;
    IsEnd(i, ring, fork, bridge);
  }
  if (!end) { sprintf(ans, "none"); }
  printf("%s\n", ans);
}
