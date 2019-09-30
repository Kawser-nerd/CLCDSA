#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int64_t n, k;
  cin >> n >> k;
  std::vector<std::pair<int64_t, int64_t>> vec(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vec[i] = std::make_pair(a, b);
  }
  std::sort(vec.begin(), vec.end());
  int64_t cum = 0;
  for (int i = 0; i < n; i++) {
    int64_t a, b;
    a = vec[i].first;
    b = vec[i].second;
    cum += b;
    if (cum >= k) {
      cout << a << endl;
      return 0;
    }
  }

  return 0;
}