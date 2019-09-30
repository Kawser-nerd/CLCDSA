#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int root(vector<int> &r, int i) {
  if (r[i] == i) {
    return i;
  } else {
    return r[i] = root(r, r[i]);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n, 0);
  vector<int> r(n, 0);
  for (int i = 0; i < n; i++) {
    r[i] = i;
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    int rx = root(r, x);
    int ry = root(r, y);
    if (rx != ry) {
      r[rx] = ry;
    }
  }
  vector<vector<int>> gis(n, vector<int>());
  vector<vector<int>> gps(n, vector<int>());
  for (int i = 0; i < n; i++) {
    root(r, i);
    gis[r[i]].push_back(i);
    gps[r[i]].push_back(p[i]);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    auto &gi = gis[i];
    auto &gp = gps[i];
    sort(gp.begin(), gp.end());
    int lg = gi.size();
    int ji = 0;
    int jp = 0;
    while (ji < lg && jp < lg) {
      if (gi[ji] == gp[jp]) {
        cnt++;
        ji++;
        jp++;
      } else if (gi[ji] < gp[jp]) {
        ji++;
      } else {
        jp++;
      }
    }
  }
  cout << cnt << endl;
}