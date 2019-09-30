#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

void solve() {
  int N;
  cin >> N;
  priority_queue<pair<int, int> > q;
  int total = 0;
  rep(i, N) {
    int n;
    cin >> n;
    total += n;
    q.push({n, i});
  }

  if (total % 2) {
      auto e = q.top();
      q.pop();
      cout << (char)('A' + e.second);
      e.first--;
      if (e.first) q.push(e);
      if (!q.empty()) cout << " ";
  }

  while (!q.empty()) {
    rep(i, 2) {
      if (q.empty()) break;
      auto e = q.top();
      q.pop();
      cout << (char)('A' + e.second);
      e.first--;
      if (e.first) q.push(e);
    }
    if (q.empty()) break;
    cout << " ";
  }
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
