#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve() {
  double cps = 2;
  double c,f,x;
  double t = 0;
  cin >> c >> f >> x;
  double ans = x / 2.0;
  
  while (ans > t) {
    t += c / cps;
    cps += f;
    if (ans > t + x / cps) {
      ans = t + x / cps;
    } else {
      //break;
    }
  }
  cout << ans << endl;
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
