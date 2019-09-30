#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n;
int L[11], R[11];

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      cin >> L[i] >> R[i]; L[i]--; R[i]--;
    }

    queue<pair<int, int> > q;
    map<pair<int, int>, int> d;
    d[make_pair(0, 0)] = 0;
    q.push(make_pair(0, 0));
    int res = -1;
    while (!q.empty()) {
      pair<int, int> cur = q.front(); q.pop();
      int idx = cur.first, mask = cur.second;
      // cout << idx << " " << mask << endl;

      mask = (mask ^ (1<<idx));
      if ((mask & (1<<idx)) > 0) idx = L[idx];
      else idx = R[idx];

      // cout << "nxt " << idx << " " << mask << endl;

      if (idx == n-1) { res = d[cur] + 1; break; }
      if (d.find(make_pair(idx, mask)) != d.end()) break;
      d[make_pair(idx, mask)] = d[cur] + 1;
      q.push(make_pair(idx, mask));
    }

    cout << "Case #" << c << ": ";
    if (res == -1) cout << "Infinity" << endl;
    else cout << res << endl;
  }
  return 0;
}
