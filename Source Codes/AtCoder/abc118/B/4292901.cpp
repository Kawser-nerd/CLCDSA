#include <algorithm>
#include <iostream>

using namespace std;

int a[30];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int tmp;
      cin >> tmp;
      tmp--;
      a[tmp]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (a[i] == n)
      ans++;
  }
  cout << ans << endl;
  return 0;
}