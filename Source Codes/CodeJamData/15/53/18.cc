#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

double best[511][511];

int main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    int Y, N;
    cin >> Y >> N;
    vector<pair<double, double> > v(N);
    for (int i = 0; i < N; i++) cin >> v[i].first;
    for (int i = 0; i < N; i++) cin >> v[i].second;
    v.push_back(make_pair(0, 0));
    sort(v.begin(), v.end());
    int zpos = 0;
    for (int i = 0; i < v.size(); i++) if (v[i].first == 0) zpos = i;
    for (int i = 0; i <= N+1; i++)
    for (int j = 0; j <= N+1; j++)
      best[i][j] = 1e20;
    priority_queue<pair<double, pair<int, int> > > q;
    q.push(make_pair(-0, make_pair(zpos, zpos)));
    double ret = 1e20;
    while (!q.empty()) {
      double t = -q.top().first;
      int i1 = q.top().second.first, i2 = q.top().second.second;
//cout << t << ' ' << i1 << ' ' << i2 << endl;
      q.pop();
      if (best[i1][i2] <= t) continue;
      best[i1][i2] = t;

      double t2 = t;
      for (int i = i1-1; i >= 0; i--) {
        t2 = max(t2, t+(-v[i].first+t*v[i].second)/(Y-v[i].second));
        q.push(make_pair(-t2-(t2-t), make_pair(i, i2)));
      }
      if (i2 == v.size()-1) ret = min(ret, t2);

      t2 = t;
      for (int i = i2+1; i < v.size(); i++) {
        t2 = max(t2, t+(v[i].first+t*v[i].second)/(Y-v[i].second));
        q.push(make_pair(-t2-(t2-t), make_pair(i1, i)));
      }
      if (i1 == 0) ret = min(ret, t2);
    }

    printf("Case #%d: %.9lf\n", prob++, ret);
  }
}
