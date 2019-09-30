#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 30;
const int inf = 1e9;

char a[MAX][MAX];
bool bio1[MAX], bio2[MAX];
int N;

void dfs(int x, int type, int& c1, int& c2) {
  if (type == 1) {
    if (bio1[x]) return;
    bio1[x] = true;
    c1++;
    REP(y, N) if (a[x][y]) dfs(y, 2, c1, c2);
  } else {
    if (bio2[x]) return;
    bio2[x] = true;
    c2++;
    REP(y, N) if (a[y][x]) dfs(y, 1, c1, c2);
  }
}

map<vector<pair<int, int>>, int> M[MAX][MAX][MAX];

int solve(vector<pair<int, int>>& v, int a, int b, int c) {
  if (M[a][b][c].count(v)) return M[a][b][c][v];
  if (v.size() == 0) return M[a][b][c][v] = a == b ? 0 : inf;

  if (a == b) {
    auto tmp = v.back();
    v.pop_back();
    int ans = solve(v, tmp.first, tmp.second, 0);
    v.push_back(tmp);
    return M[a][b][c][v] = ans;
  }
  if (c == (int)v.size()) return M[a][b][c][v] = inf;

  
  int ans = solve(v, a, b, c + 1);
  if (c == 0 || v[c] != v[c-1]) {
    auto tmp = v[c];
    swap(v[c], v.back());
    v.pop_back();

    ans = min(ans, a*tmp.second + b*tmp.first + solve(v, a+tmp.first, b+tmp.second, c));
    
    v.push_back(tmp);
    swap(v[c], v.back());
  }
  return M[a][b][c][v] = ans;
}

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    scanf("%d", &N);
    REP(i, N) {
      scanf("%s", a[i]);
      REP(j, N) a[i][j] -= '0';
    }

    REP(i, N) bio1[i] = bio2[i] = false;

    vector<pair<int, int>> v;
    int ans = 0;
    REP(i, N) {
      if (!bio1[i]) {
        int c1 = 0, c2 = 0;
        dfs(i, 1, c1, c2);
        if (c1 != c2) v.push_back({c1, c2});
        ans += c1 * c2;
      }
      if (!bio2[i]) {
        int c1 = 0, c2 = 0;
        dfs(i, 2, c1, c2);
        if (c1 != c2) v.push_back({c1, c2});
        ans += c1 * c2;
      }
    }

    REP(i, N) REP(j, N) ans -= a[i][j];

    REP(i, MAX) REP(j, MAX) REP(k, MAX) M[i][j][k].clear();
    sort(v.begin(), v.end());
    ans += solve(v, 0, 0, 0);
    
    printf("Case #%d: ", tp);
    printf("%d\n", ans);
  }
  return 0;
}
