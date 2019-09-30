#include <algorithm>
#include <iostream>

using namespace std;

int q[200001];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int num;
    cin >> num;
    q[num] = i;
  }

  int maxcnt = 1;
  int cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (q[i] > q[i - 1]) {
      cnt++;
    } else {
      if (cnt > maxcnt) {
        maxcnt = cnt;
      }
      cnt = 1;
    }
  }
  if (cnt > maxcnt) {
    maxcnt = cnt;
  }

  cout << n - maxcnt << endl;
}