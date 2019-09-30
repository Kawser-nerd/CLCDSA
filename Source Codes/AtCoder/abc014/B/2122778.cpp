#include <iostream>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  int ans = 0, a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if ((x >> i) & 1)
      ans += a;
  }
  cout << ans << endl;
  return 0;
}