#include <iostream>
#include <vector>
using namespace std;

int main() {
  int w, h, n;
  cin >> w >> h >> n;

  int max_x = w, min_x = 0;
  int max_y = h, min_y = 0;
  int x = 0, y = 0, a = 0;
  for (int i=0; i<n; i++) {
    cin >> x >> y >> a;
    if (a == 1) {
      if (x > min_x) min_x = x;
    }
    if (a == 2) {
      if (max_x > x) max_x = x;
    }
    if (a == 3) {
      if (y > min_y) min_y = y;
    }
    if (a == 4) {
      if (max_y > y) max_y = y;
    }
  }

  int ans = 0;
  if (max_x > min_x && max_y > min_y) ans = (max_x - min_x) * (max_y - min_y);
  cout << ans << endl;
}