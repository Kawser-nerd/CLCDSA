#include <iostream>
using namespace std;

int main () {
  int n;
  cin >> n;
  int a[2 * n];
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  sort(a, a + 2 * n);
  for (int i = 0; i < 2 * n; i++) {
    if (i % 2 == 0) {
      ans += a[i];
    }
  }
  cout << ans << endl;
}