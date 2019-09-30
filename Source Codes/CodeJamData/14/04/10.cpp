#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<double> me(n), you(n);
  
  rep(i, n) {
    cin >> me[i];
  }
  rep(i, n) {
    cin >> you[i];
  }

  sort(me.begin(), me.end());
  sort(you.begin(), you.end());

  int dans = 0;
  int ans = 0;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; i + j < n; j++) {
      if (me[i + j] < you[j]) goto contd;
    }
    dans = n - i;
    goto lbl;
  contd:;
  }
 lbl:

  int mit = 0, yit = 0;
  while (mit < n && yit < n) {
    if (me[mit] < you[yit]) {
      mit++;
    } else {
      yit++;
    }
    ans = max(ans, yit - mit);
  }
  cout << dans << " " << ans << endl;
}

int main() {
  cout << setprecision(10);
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
