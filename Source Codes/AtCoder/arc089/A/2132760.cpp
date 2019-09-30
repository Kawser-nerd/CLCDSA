#include <iostream>

int dist(int x1, int y1, int x2, int y2) {
  int xdist = 0, ydist;
  if (x1 > x2) xdist = x1 - x2;
  else xdist = x2 - x1;
  if (y1 > y2) ydist = y1 - y2;
  else ydist = y2 - y1;
  return xdist + ydist;
}

int main() {
  int n;
  std::cin >> n;

  bool ok = true;
  int t1 = 0, x1 = 0, y1 = 0;
  for (int i = 0; i < n; i++) {
    int t2 = 0, x2 = 0, y2 = 0;
    std::cin >> t2 >> x2 >> y2;
    int d = dist(x1, y1, x2, y2);
    int z = (t2 - t1) - d;
    if (z < 0 || z % 2 != 0) {
      ok = false;
      break;
    }
    t1 = t2;
    x1 = x2;
    y1 = y2;
  }
  if (ok) std::cout << "Yes";
  else std::cout << "No";
  return 0;
}