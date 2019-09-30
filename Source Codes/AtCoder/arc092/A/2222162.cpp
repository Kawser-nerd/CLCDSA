#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>
#include <algorithm>

using namespace std;
#define all(c) (c).begin(), (c).end()

struct graph {
  int L, R;
  vector<vector<int>> adj;
  graph(int L, int R) : L(L), R(R), adj(L+R) { }
  void add_edge(int u, int v) {
    adj[u].push_back(v+L);
    adj[v+L].push_back(u);
  }
  int maximum_matching() {
    vector<int> visited(L), mate(L+R, -1);
    function<bool(int)> augment = [&](int u) { // DFS
      if (visited[u]) return false;
      visited[u] = true;
      for (int w: adj[u]) {
        int v = mate[w];
        if (v < 0 || augment(v)) {
          mate[u] = w;
          mate[w] = u;
          return true;
        }
      }
      return false;
    };
    int match = 0;
    for (int u = 0; u < L; ++u) {
      fill(all(visited), 0);
      if (augment(u)) ++match;
    }
    return match;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> r, b;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    r.emplace_back(pair<int, int>(x, y));
  }
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    b.emplace_back(pair<int, int>(x, y));
  }
  graph g(n, n);
  for (int i = 0; i < n; i++) {
    auto &er = r[i];
    for (int j = 0; j < n; j++) {
      auto &eb = b[j];
      if (er.first < eb.first && er.second < eb.second) {
        g.add_edge(i,j);
      }
    }
  }
    
  cout << g.maximum_matching() << endl;
  return 0;
}