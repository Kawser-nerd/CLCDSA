#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

void solve() {
  long long B, M;
  cin >> B >> M;
  if (M > (1LL << (B - 2))) {
    cout << "IMPOSSIBLE" << endl;
    return;
  } else {
    cout << "POSSIBLE" << endl;
  }
  
  int direct = 0;
  if (M == (1LL << (B - 2))) {
    direct = 1;
    M--;
  }
  cout << 0;
  rep (i, B - 2) {
    if (M & (1LL << (B - 3 - i))) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << direct << endl;
  rep (i, B - 1) {
    rep(j, B) {
      cout << (j > i + 1);
    }
    cout << endl;
  }

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
