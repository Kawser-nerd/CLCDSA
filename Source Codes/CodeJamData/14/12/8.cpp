#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 5000;

vector<int> mem_siz;
vector<int> mem_rec;

int siz(const vector<vector<int> >& g, int x, int p) {
  int &ret = mem_siz[x];
  if (ret != -1) return ret;
  ret = 1;
  for (int i = 0; i < int(g[x].size()); ++i) if (g[x][i] != p) {
    ret += siz(g, g[x][i], x);
  }
  return ret;
}

int rec(const vector<vector<int> >& g, int x, int p) {
  int ch = int(g[x].size());
  if (p != -1) --ch;
  
  int &ret = mem_rec[x];
  if (ret != -1) return ret;
  
  // 0 children
  if (ch < 2) return ret = siz(g, x, p)-1;
  
  // 2 children
  vector<pair<int, int> > cost(g[x].size(), pair<int, int>(-INF, -1));
  for (int i = 0; i < int(g[x].size()); ++i) {
    cost[i].second = g[x][i];
  }
  for (int i = 0; i < int(g[x].size()); ++i) if (g[x][i] != p) {
    cost[i].first = siz(g, g[x][i], x)-rec(g, g[x][i], x);
  }
  sort(cost.begin(), cost.end(), greater<pair<int, int> >());
  ret = siz(g, x, p)-1-cost[0].first-cost[1].first;
  return ret;
}

int main() {
  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    for (int i = 0; i < n-1; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    
    int ans = INF;
    for (int i = 0; i < n; ++i) {
      mem_siz = vector<int>(n, -1);
      mem_rec = vector<int>(n, -1);
      int cur = rec(g, i, -1);
      if (cur < ans) ans = cur;
    }
    cout << "Case #" << ca << ": " << ans << endl;
  }
}

