#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>

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


class SatSolver {
  vector<vector<int>> g;
  vector<vector<int>> gt;
  vector<int> ts;
  vector<int> comp;
  vector<bool> used;

  void addEdge(int a, int av, int b, int bv) {
    g[2 * a + av].push_back(2 * b + bv);
    gt[2 * b + bv].push_back(2 * a + av);
  }

  void dfs_ts(int v) {
    if (used[v]) return;
    used[v] = true;
    for (int u : g[v]) {
      dfs_ts(u);
    }
    ts.push_back(v);
  }

  void dfs_comp(int v, int c) {
    if (comp[v] != -1) {
      return;
    }
    comp[v] = c;
    for (int u : gt[v]) {
      dfs_comp(u, c);
    }
  }

public:

  int getN() {
    return (int)g.size() / 2;
  }

  int addVertex() {
    int n = (int) g.size() / 2;
    g.push_back(vector<int>());
    g.push_back(vector<int>());
    gt.push_back(vector<int>());
    gt.push_back(vector<int>());
    return n;
  }

  void addOr(int a, int av, int b, int bv) {
    eprintf("%cx%d || %cx%d = true\n", av ? ' ' : '!', a, bv ? ' ' : '!', b);
    addEdge(a, !av, b, bv);
    addEdge(b, !bv, a, av);
  }

  void addTrue(int a, int av) {
    eprintf("%cx%d = true\n", av ? ' ' : '!', a);
    addEdge(a, !av, a, av);
  }


  vector<bool> solve() {
    int n = g.size() / 2;
    used = vector<bool>(2 * n);
    comp = vector<int>(2 * n, -1);

    vector<bool> res(n);

    for (int i = 0; i < 2 * n; i++) {
      dfs_ts(i);
    }
    reverse(ts.begin(), ts.end());
    for (int i = 0; i < 2 * n; i++) {
      dfs_comp(ts[i], i);
    }

    for (int i = 0; i < n; i++) {
      if (comp[2 * i] == comp[2 * i + 1]) {
        return vector<bool>();
      }
      res[i] = comp[2 * i + 1] > comp[2 * i];
    }
    return res;
  }
};

void PreCalc() {
}

char s[200][200];
vector<pair<int, int>> hit[200][200];
int id[200][200];
int n, m;
vector<bool> ok[2];

const char *NO = "IMPOSSIBLE";

bool go(int i, int j, int di, int dj, pair<int, int> v) {
  while (true) {
    if (i < 0 || j < 0 || i >= n || j >= m) return true;
    if (s[i][j] == '#') return true;
    if (s[i][j] == '/') {
      swap(di, dj);
      di *= -1;
      dj *= -1;
    } else if (s[i][j] == '\\') {
      swap(di, dj);
    } else if (s[i][j] == '.') {
      hit[i][j].push_back(v);
    } else {
      assert(s[i][j] == '-' || s[i][j] == '|');
      return false;
    }
    i += di;
    j += dj;
  }
}

void solve() {
  scanf("%d%d", &n, &m);
  SatSolver solver;

  for (int i = 0; i < n; i++) {
    scanf(" %s", s[i]);
    for (int j = 0; j < m; j++) {
      hit[i][j].clear();
      if (s[i][j] == '-' || s[i][j] == '|') {
        id[i][j] = solver.addVertex();
      } else {
        id[i][j] = -1;
      }
    }
  }

  ok[0] = ok[1] = vector<bool>(solver.getN(), true);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int myid = id[i][j];
      if (myid == -1) continue;
      ok[1][myid] = ok[1][myid] && go(i + 1, j, 1, 0, {myid, 1});
      ok[1][myid] = ok[1][myid] && go(i - 1, j, -1, 0, {myid, 1});
      ok[0][myid] = ok[0][myid] && go(i, j + 1, 0, 1, {myid, 0});
      ok[0][myid] = ok[0][myid] && go(i, j - 1, 0, -1, {myid, 0});

      if (!ok[1][myid] && !ok[0][myid]) {
        puts(NO);
        return;
      }
      if (!ok[1][myid]) {
        solver.addTrue(myid, 0);
      }
      if (!ok[0][myid]) {
        solver.addTrue(myid, 1);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] != '.') continue;
      int ptr = 0;
      for (pair<int, int> it : hit[i][j]) {
        if (ok[it.second][it.first]) {
          hit[i][j][ptr++] = it;
        }
      }
      hit[i][j].resize(ptr);
      if (hit[i][j].size() == 0) {
        puts(NO);
        return;
      } else if (hit[i][j].size() == 1) {
        solver.addTrue(hit[i][j][0].first, hit[i][j][0].second);
      } else if (hit[i][j].size() == 2) {
        solver.addOr(hit[i][j][0].first, hit[i][j][0].second, hit[i][j][1].first, hit[i][j][1].second);
      } else {
        assert(0);
      }
    }
  }
  
  vector<bool> res = solver.solve();
  if (res.size() == 0) {
    puts(NO);
    return;
  }

  puts("POSSIBLE");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (id[i][j] != -1) {
        s[i][j] = res[id[i][j]] ? '|' : '-';
      }
    }
    puts(s[i]);
  }
}


int main() {
#ifdef LOCAL
//  freopen("c.in", "r", stdin);
//  freopen("c.out", "w", stdout);
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