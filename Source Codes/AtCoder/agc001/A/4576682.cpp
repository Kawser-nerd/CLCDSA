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
  int64_t result = 0;
  std::vector<int> l;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    int m1;
    cin >> m1;
    l.push_back(m1);
  }
  std::sort(l.begin(), l.end());
  for (int i = 0; i < 2 * n; i += 2) {
    result += l[i];
  }
  cout << result << endl;

  return 0;
}