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

int64_t get_gcd(int64_t a, int64_t b) {
  if (a < b) std::swap(a, b);
  int64_t r;
  while (1) {
    r = a % b;
    if (r == 0) {
      cerr << "GCD is " << b << endl;
      return b;
    } else {
      a = b;
      b = r;
    }
  }
}

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int64_t n, m;
  cin >> n >> m;
  std::string s, t;
  cin >> s >> t;
  int64_t l = n * m / get_gcd(n, m);
  cerr << " l is " << l << endl;
  for (int64_t b = 0; b <= (m - 1); b++) {
    if ((n * b) % m == 0) {
      int64_t a = n * b / m;
      if (a <= n - 1) {
        if (s[a] != t[b]) {
          cout << "-1" << endl;
          exit(0);
        }
      }
    }
  }
  cout << l << endl;

  return 0;
}