#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;



int64_t f(int64_t a, int64_t b) {
  cerr << "\033[93m" << a << " " << b << "\033[m" << endl;
  int64_t n  = std::max(a, b);
  int result = 1;
  while (n >= 10) {
    result++;
    n /= 10;
  }
  return result;
}

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int64_t n;
  cin >> n;
  int64_t result = f(n, 1);
  for (int64_t a = 1; a <= std::pow(n, 0.5) + 1; a++) {
    if (n % a == 0) {
      int64_t b = n / a;
      result    = std::min(result, f(a, b));
    }
  }

  cout << result << endl;

  return 0;
}