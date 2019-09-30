#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;

vector<int> E[400];
int D[400][400];
int memo[400][400];

stack<int> st;
stack<int> stsz;
bool vis[400];

int push(int u) {
  int result = 0;
  stsz.push(st.size());
  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if(!vis[v]) {
      vis[v] = true;
      st.push(v);
      ++result;
    }
  }
  return result;
}

void pop() {
  int sz = stsz.top();
  stsz.pop();
  while(st.size() > sz) {
    int u = st.top();
    st.pop();
    vis[u] = false;
  }
}

int solve(int u, int v) {
  if(D[v][1] == 1) return 0;

  int& ref = memo[u][v];
  if(ref != -1) return ref;

  ref = 0;
  for(int i = 0; i < E[v].size(); i++) {
    int x = E[v][i];
    if(D[x][1] >= D[v][1]) continue;
    int res = push(x);
    ref = max(ref, res + solve(v, x));
    pop();
  }
  return ref;
}

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    memset(D, 1, sizeof(D));

    int P, W;
    cin >> P >> W;
    for(int i = 0; i < P; i++) E[i] = vector<int>(1, i);
    for(int i = 0; i < P; i++) D[i][i] = 0;
    for(int i = 0; i < W; i++) {
      string s; cin >> s;
      for(int i = 0; i < s.size(); i++) if(s[i] == ',') s[i] = ' ';
      istringstream sin(s);
      int u, v; sin >> u >> v;
      D[u][v] = D[v][u] = 1;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    for(int k = 0; k < P; k++) {
      for(int i = 0; i < P; i++) {
        for(int j = 0; j < P; j++) {
          D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
        }
      }
    }
    memset(memo, -1, sizeof(memo));
    memset(vis, 0, sizeof(vis));

    int result = 0;
    int r1 = push(0);
    if(D[0][1] == 1) {
      result = r1;
    } else for(int i = 0; i < E[0].size(); i++) {
      int v = E[0][i];
      if(D[v][1] >= D[0][1]) continue;
      int r2 = push(v);
      result = max(result, r1 + r2 + solve(0, v));
      pop();
    }

    printf("Case #%d: %d %d\n", t, D[0][1] - 1, result - D[0][1]);
  }
}
