#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int inf = (int)1e9;
const int N = 8010;

bool visited[N];
int cost[N];
vector < pair <int, int> > g[N];
int edge[N];

bool mark[N];

int DFS_MAX;

void dfs_max(int v, int pr, int sum) {
  if (sum > DFS_MAX) {
    DFS_MAX = sum;
  }
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    if (mark[g[v][j].second]) {
      continue;
    }
    int u = g[v][j].first;
    if (u == pr) {
      continue;
    }
    dfs_max(u, v, sum + (visited[u] ? 0 : cost[u]));
  }
}

int get_max(int v) {
  DFS_MAX = 0;
  dfs_max(v, -1, 0);
  return DFS_MAX;
}

bool dfs_get(int v, int fin, int pr, deque <int> &d) {
  if (v == fin) {
    return true;
  }
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j].first;
    if (u == pr) {
      continue;
    }
    d.push_back(g[v][j].second);
    if (dfs_get(u, fin, v, d)) {
      return true;
    }
    d.pop_back();
  }
  return false;
}

deque <int> get_path(int va, int vb) {
  deque <int> d;
  dfs_get(va, vb, -1, d);
  return d;
}

int move_b(deque <int> path, int va, int vb, int total);

int move_a(deque <int> path, int va, int vb, int total) {
  int e = (path.empty() ? -1 : path.front());
  int sz = g[va].size();
  int res = total - get_max(vb);
  for (int j = 0; j < sz; j++) {
    int u = g[va][j].second;
    if (u == e || mark[u]) {
      continue;
    }
    mark[u] = true;
    int da = get_max(g[va][j].first);
    int db = get_max(vb);
    int diff = total + (cost[g[va][j].first] + da) - db;
    if (diff > res) {
      res = diff;
    }
    mark[u] = false;
  }
  if (e != -1) {
    path.pop_front();
    mark[e] = true;
    va = e + edge[e] - va;
    if (!path.empty()) {
      total += cost[va];
    }
    visited[va] = true;
    int cur = -move_b(path, va, vb, -total);
    visited[va] = false;
    if (cur > res) {
      res = cur;
    }
    mark[e] = false;
  }
  return res;
}

int move_b(deque <int> path, int va, int vb, int total) {
  int e = (path.empty() ? -1 : path.back());
  int sz = g[vb].size();
  int res = total - get_max(va);
  for (int j = 0; j < sz; j++) {
    int u = g[vb][j].second;
    if (u == e || mark[u]) {
      continue;
    }
    mark[u] = true;
    int da = get_max(va);
    int db = get_max(g[vb][j].first);
    int diff = total + (cost[g[vb][j].first] + db) - da;
    if (diff > res) {
      res = diff;
    }
    mark[u] = false;
  }
  if (e != -1) {
    path.pop_back();
    mark[e] = true;
    vb = e + edge[e] - vb;
    if (!path.empty()) {
      total += cost[vb];
    }
    visited[vb] = true;
    int cur = -move_a(path, va, vb, -total);
    visited[vb] = false;
    if (cur > res) {
      res = cur;
    }
    mark[e] = false;
  }
  return res;
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", cost + i);
      g[i].clear();
    }
    for (int i = 1; i <= n - 1; i++) {
      scanf("%d", edge + i);
      g[i].push_back(make_pair(edge[i], i));
      g[edge[i]].push_back(make_pair(i, i));
    }
    int ans = -inf;
    for (int va = 1; va <= n; va++) {
      int mn = inf;
      for (int vb = 1; vb <= n; vb++) {
        for (int j = 1; j <= n - 1; j++) {
          mark[j] = false;
        }
        for (int j = 1; j <= n; j++) {
          visited[j] = false;
        }
        if (va == vb) {
          int sz = g[va].size();
          for (int j = 0; j < sz; j++) {
            mark[g[va][j].second] = true;
          }
          int mx1 = 0, mx2 = 0;
          for (int j = 0; j < sz; j++) {
            int u = get_max(g[va][j].first);
            if (u > mx1) {
              mx2 = mx1;
              mx1 = u;
            } else {
              if (u > mx2) {
                mx2 = u;
              }
            }
          }
          int diff = (cost[va] + mx1) - mx2;
          if (diff < mn) {
            mn = diff;
          }
          continue;
        }
        deque <int> path = get_path(va, vb);
        visited[va] = visited[vb] = true;
        int diff = move_a(path, va, vb, cost[va] - cost[vb]);
        if (diff < mn) {
          mn = diff;
        }
      }
      if (mn > ans) {
        ans = mn;
      }
    }
    printf("%d\n", ans);
    fflush(stdout);
  }
  return 0;
}
