#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  string s;
  int t;
  cin >> s >> t;
  int x{}, y{}, other{};
  for (auto e : s) {
    switch (e) {
      case 'L':
        --x;
        break;
      case 'R':
        ++x;
        break;
      case 'U':
        ++y;
        break;
      case 'D':
        --y;
        break;
      default:
        ++other;
        break;
    }
  }
  int d = abs(x) + abs(y);
  if (t == 1) {
    cout << d + other << endl;
  } else if (d - other > 0) {
    cout << d - other << endl;
  } else if (abs(d - other) % 2 == 0) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
}