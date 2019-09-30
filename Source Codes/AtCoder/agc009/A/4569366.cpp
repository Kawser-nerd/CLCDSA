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

  int n;
  cin >> n;
  int64_t result = 0;
  std::vector<int64_t> a, b;
  a.resize(n);
  b.resize(n);

  for (int i = 0; i < n; i++) {
    int m1, m2;
    cin >> m1 >> m2;
    a[i] = m1;
    b[i] = m2;
  }
  for (int i = n - 1; i >= 0; i--) {
    a[i] += result;
    int64_t temp = a[i] % b[i] == 0 ? 0 : b[i] - (a[i] % b[i]);
    result += temp;
  }
  cout << result << endl;

  return 0;
}