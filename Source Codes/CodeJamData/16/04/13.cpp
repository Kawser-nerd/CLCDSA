#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef long long ll;

void solve() {
  int K, C, S;
  cin >> K >> C >> S;
  if (K > C * S) { cout << " IMPOSSIBLE"; return; }
  vector<vector<int>> v(S, vector<int>(C, 0));
  REP(i,K) v[i/C][i%C] = i;
  set<ll> s;
  REP(i,S) {
    ll b = 1;
    ll res = 0;
    REP(j,C) {
      res += b * v[i][j];
      b *= K;
    }
    if (s.find(res) != s.end()) continue;
    s.insert(res);
    cout << " " << res + 1;
  }
}

int main() {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cout << "Case #" << cas << ":";
    solve();
    cout << endl;
  }
  return 0;
}
