#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

void solve() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  cout << a * b * min(c, k) << endl;

  rep(i, a) {
    rep(j, b) {
      int index = (j - i + c) % c;
      rep(l, min(c, k)) {
        cout << i + 1 << " " << j + 1 << " " << (index + l) % c + 1 << endl;
      }
    }
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
