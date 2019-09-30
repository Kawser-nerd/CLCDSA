#include <iostream>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int ans = 0;

  while (true) {
    if (x == 0 && y == 0)
      break;
    int tmp = min(x, y);
    if (x > 0 && y > 0) {
      if (ans + 2 * c > ans + a + b) {
        ans += tmp * (a + b);
        x -= tmp;
        y -= tmp;
      } else {
        ans += tmp * 2 * c;
        x -= tmp;
        y -= tmp;
      }
    } else if (x == 0 && y > 0) {
      if (ans + 2 * c > ans + b) {
        ans += y * b;
        y -= y;
      } else {
        ans += y * 2 * c;
        y -= y;
      }
    } else if (y == 0 && x > 0) {
      if (ans + 2 * c > ans + a) {
        ans += x * a;
        x -= x;
      } else {
        ans += x * 2 * c;
        x -= x;
      }
    }
  }

  cout << ans << endl;
  return 0;
}