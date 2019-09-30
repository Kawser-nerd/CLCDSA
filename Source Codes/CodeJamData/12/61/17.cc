#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

struct zom {
  int x, y, i, t, tt;
  bool operator<(const zom& o) const {
    return tt > o.tt;
  }
};

int n;
int dp[110][1010];
zom z[110];

int absv(int x) { return x > 0 ? x : -x; }

int dist(int x1, int y1, int x2, int y2) {
  return 100 * max(absv(x1-x2), absv(y1-y2));
}

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    cin >> n;
    memset(dp, 0, sizeof(dp));
    memset(z, 0, sizeof(z));

    for (int i = 0; i < n; i++) cin >> z[i].x >> z[i].y >> z[i].t;

    priority_queue<zom> pq;
    for (int i = 0; i < n; i++) {
      z[i].i = i;
      for (int j = 0; j <= 1000; j++) {
        z[i].tt = z[i].t + j;
        pq.push(z[i]);
      }
    }

    for (int i = 0; i < n; i++) {
      int t = dist(0, 0, z[i].x, z[i].y);
      if (t <= z[i].t + 1000) dp[i][max(t, z[i].t)-z[i].t] = 1;
    }

    while (!pq.empty()) {
      zom cur = pq.top(); pq.pop();
      // if (dp[cur.i][cur.tt-cur.t] == 0) continue;

      for (int i = 0; i < n; i++) {
        if (i == cur.i) continue;

        int t = max(cur.tt + dist(cur.x, cur.y, z[i].x, z[i].y), cur.tt + 750);
        if (t <= z[i].t + 1000) dp[i][max(t, z[i].t)-z[i].t] = max(dp[i][max(t, z[i].t)-z[i].t], dp[cur.i][cur.tt-cur.t] + 1);
      }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= 1000; j++)
        res = max(res, dp[i][j]);
    cout << "Case #" << c << ": " << res << endl;
  }
  return 0;
}
