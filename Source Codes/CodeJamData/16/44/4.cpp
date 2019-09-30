#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

const int N = 424;
const int M = 4242424;

char graph[N][N];
int x[N];
bool was[N];

int dp[M];
int m, a[N], b[N], c[N], state[N];

void solve(int v, int st, int sa, int sb, int &res) {
  if (v == m) {
    if (sa == sb) {
      res = min(res, sa * sa + dp[st]);
    }
    return;
  }
  for (int j = 0; j <= state[v]; j++) {
    solve(v + 1, st * (1 + c[v]) + j, sa + a[v] * (state[v] - j), sb + b[v] * (state[v] - j), res);
  }
}

void dfs(int v, int st) {
  if (v == m) {
    if (st == 0) {
      dp[st] = 0;
    } else {
      dp[st] = inf;
      solve(0, 0, 0, 0, dp[st]);
    }
    return;
  }
  for (int j = 0; j <= c[v]; j++) {
    state[v] = j;
    dfs(v + 1, st * (1 + c[v]) + j);
  }
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
    for (int i = 0; i < n; i++) {
      scanf("%s", graph[i]);
    }
    for (int i = 0; i < 2 * n; i++) {
      was[i] = false;
    }
    vector < pair <int, int> > v;
    for (int i = 0; i < 2 * n; i++) {
      if (was[i]) {
        continue;
      }
      int b = 0, e = 1;
      x[0] = i;
      was[i] = true;
      while (b < e) {
        if (x[b] < n) {
          for (int j = 0; j < n; j++) {
            if (!was[n + j] && graph[x[b]][j] == '1') {
              x[e] = n + j;
              was[x[e]] = true;
              e++;
            }
          }
        } else {
          for (int j = 0; j < n; j++) {
            if (!was[j] && graph[j][x[b] - n] == '1') {
              x[e] = j;
              was[x[e]] = true;
              e++;
            }
          }
        }
        b++;
      }
      int c0 = 0, c1 = 0;
      for (int j = 0; j < e; j++) {
        if (x[j] < n) {
          c0++;
        } else {
          c1++;
        }
      }
      v.push_back(make_pair(c0, c1));
    }
    sort(v.begin(), v.end());
    m = 0;
    for (int i = 0; i < (int) v.size(); i++) {
      if (m > 0 && v[i].first == a[m - 1] && v[i].second == b[m - 1]) {
        c[m - 1]++;
      } else {
        a[m] = v[i].first;
        b[m] = v[i].second;
        c[m] = 1;
        m++;
      }
    }
    long long states = 1;
    for (int i = 0; i < m; i++) {
      states *= (1 + c[i]);
    }
    cerr << "test case " << qq << ": states = " << states << endl;
    int had = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        had += (graph[i][j] == '1');
      }
    }
    dfs(0, 0);
    printf("%d\n", dp[states - 1] - had);
  }
  return 0;
}
