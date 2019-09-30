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

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int64_t n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  n--;
  int64_t maximum     = a + n * d;
  int64_t minimum     = a - n * d;
  int64_t true_range  = 1 + (d - c) * n;
  int64_t range       = (maximum - minimum + 1);
  int64_t false_range = (range - true_range * (n + 1)) / n;
  //   cerr << "\033[93m" << maximum << " " << minimum << " " << true_range << "
  //   "
  //    << range << " " << false_range << "\033[m" << endl;
  if (false_range <= 0) {
    if (maximum >= b && b >= minimum) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return 0;
  }
  int64_t top = maximum, bottom = maximum - true_range + 1;
  while (bottom >= minimum) {
    // cerr << "\033[93m" << top << " " << bottom << "\033[m" << endl;
    if (bottom <= b && b <= top) {
      cout << "YES" << endl;
      return 0;
    } else if (bottom <= b && top < b) {
      cout << "NO" << endl;
      return 0;
    }
    bottom -= (true_range + false_range);
    top -= (true_range + false_range);
  }
  cout << "NO" << endl;

  return 0;
}