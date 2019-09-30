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

  long long a, b, c;
  cin >> a >> b >> c;

  if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
    cout << 0 << endl;
    exit(0);
  } else {
    long long x = b * c, y = c * a, z = a * b;
    cout << std::min({x, y, z});
    exit(0);
  }

  return 0;
}