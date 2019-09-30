#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string> 
#include <ctime>

using namespace std;

#undef Fdg_Home

bool can[55][55];
int n, m;
vector<string> codes;

bool used[55] = {0};
bool w[55];

void dfs(int v) {
  w[v] = true;
  for (int u = 0; u < n; ++u) {
    if (can[v][u] && !used[u] && !w[u]) dfs(u);
  }
}

string solve(int st) {
  string ret = codes[st];
  memset(used, 0, sizeof(used));
  vector<int> way(1, st);
  int last = st;
  for (int i = 1; i < n; ++i) {
    string cur = ret + 'C'; int ind = -1, ws = 0;
    for (int tg = way.size() - 1; tg >= 0; --tg) {
      for (int j = 0; j < n; ++j) {
        if (used[j] || j == st || !can[way[tg]][j]) continue;
        used[j] = true;
        memset(w, 0, sizeof(w));
        dfs(j);
        for (int t = 0; t <= tg; ++t)
          dfs(way[t]);
        bool ok = true;
        for (int t = 0; t < n; ++t) {
          if (!w[t] && !used[t] && t != st) {
            ok = false;
            break;
          }
        }
        if (ok && (ret + codes[j]) < cur) {
          cur = ret + codes[j];
          ind = j; ws = tg + 1;
        }
        used[j] = false;
      }
    }
    ret = cur; last = ind;
    while (way.size() > ws) way.pop_back();
    way.push_back(last);
    used[ind] = true;
    if (ret.back() == 'C') exit(-1);
  }
  return ret;
}

void solveTest(int CS) {
  printf("Case #%d: ", CS);
  cin >> n >> m;
  codes.clear();
  codes.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> codes[i];
  memset(can, 0, sizeof(can));
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    can[a][b] = can[b][a] = true;
  }
  string ans = string(1, char((int)'9' + 10));
  for (int i = 0; i < n; ++i)
    ans = min(ans, solve(i));
  cout << ans << endl;
}

int main() {
#ifndef Fdg_Home
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d\n", &T);
  for (int test = 1; test <= T; ++test) {
    solveTest(test);
  }
  return 0;
}