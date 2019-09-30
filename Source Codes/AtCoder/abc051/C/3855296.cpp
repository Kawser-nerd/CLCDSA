#include <iostream>
#include <string>
using namespace std;

string ans = "";

void addstr(int c, string d) {
  for (int i = 0; i < c; i++) {
    ans = ans + d;
  }
}

int main() {
  int sx, sy, tx, ty, dx, dy;
  cin >> sx >> sy >> tx >> ty;

  dx = tx - sx;
  dy = ty - sy;
  addstr(dy, "U");
  addstr(dx, "R");
  addstr(dy, "D");
  addstr(dx + 1, "L");
  addstr(dy + 1, "U");
  addstr(dx + 1, "R");
  addstr(1, "D");
  addstr(1, "R");
  addstr(dy + 1, "D");
  addstr(dx + 1, "L");
  addstr(1, "U");

  cout << ans << endl;
  return 0;
}