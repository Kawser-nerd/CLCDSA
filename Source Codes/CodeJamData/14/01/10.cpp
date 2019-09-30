#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve() {
  vector<int> count(17);
  rep(i, 2) {
    int row;
    cin >> row;
    row--;
    rep(j, 4)rep(k, 4) {
      int n;
      cin >> n;
      if (j == row) count[n]++;
    }
  }

  int ans = -1;
  rep(i,17) {
    if (count[i] == 2) {
      if (ans == -1) ans = i;
      else {
	cout << "Bad magician!" << endl;
	return;
      }
    }
  }
  if (ans == -1) {
    cout << "Volunteer cheated!" << endl;
    return;
  }
  cout << ans << endl;
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
