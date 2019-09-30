#include <algorithm>
#include <iostream>

using namespace std;

long a[200001];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  if (a[1] != 0) {
    cout << -1 << endl;
    return 0;
  }
  long cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] - a[i - 1] > 1) {
      cout << -1 << endl;
      return 0;
    }
    if (a[i] == a[i - 1] + 1) {
      cnt++;
    } else {
      cnt += a[i];
    }
  }
  cout << cnt << endl;
}