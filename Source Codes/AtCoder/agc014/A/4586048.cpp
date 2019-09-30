#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

void OutputError(std::string s) {
  cerr << "\033[93m" << s << "\033[m" << endl;
  return;
}

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b && b == c) {
    if (a % 2 == 0) {
      cout << -1 << endl;
    } else {
      cout << 0 << endl;
    }
  } else {
    int res = 0;
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
      if (a == b && b == c) {
        res = -1;
        break;
      }
      int da = a / 2, db = b / 2, dc = c / 2;
      a = dc + db;
      b = dc + da;
      c = da + db;
      res++;
    }
    cout << res << endl;
  }

  return 0;
}