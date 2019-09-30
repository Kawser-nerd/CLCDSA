#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <cassert>

using namespace std;

#define MAXN 50

int N;
string Z[MAXN];
vector<int> E[MAXN];

int S[MAXN];
bool been[MAXN];
bool vis[MAXN];

void dfs(int u) {
  if(vis[u]) return;
  vis[u] = true;

  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if(!been[v]) {
      dfs(v);
    }
  }
}

bool reachall(int dep) {
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < dep; i++) {
    dfs(S[i]);
  }
  for(int i = 0; i < N; i++) {
    if(!been[i] && !vis[i]) {
      return false;
    }
  }
  return true;
}

string solve(int dep) {
  int u = S[dep - 1];
  string result = Z[u];
  for(;;) {
    int bestv = -1;
    string best;
    for(int i = 0; i < E[u].size(); i++) {
      int v = E[u][i];
      if(been[v]) {
        continue;
      }
      if(best.empty() || Z[v] < best) {
        best = Z[v];
        bestv = v;
      }
    }
    if(best.empty()) {
      return result;
    }

    for(int s = dep - 1; ; s--) {
      if(s == 0 || !reachall(s)) {
        break;
      }

      int su = S[s - 1];
      for(int i = 0; i < E[su].size(); i++) {
        int sv = E[su][i];
        if(been[sv]) {
          continue;
        }
        if(Z[sv] < best) {
          return result;
        }
      }
    }

    S[dep] = bestv;
    been[bestv] = true;
    result += solve(dep + 1);
  }
}

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int M;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
      cin >> Z[i];
      E[i].clear();
    }
    for(int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    memset(been, 0, sizeof(been));

/*
for(int i = 0; i < N; i++) {
  S[0] = i;
  been[i] = true;
  printf("%d\n", (int)reachall(1));
  been[i] = false;
}
*/

    int bestu = min_element(Z, Z + N) - Z;
    S[0] = bestu;
    been[bestu] = true;
    printf("Case #%d: ", t);
    printf("%s\n", solve(1).c_str());
  }
  return 0;
}
