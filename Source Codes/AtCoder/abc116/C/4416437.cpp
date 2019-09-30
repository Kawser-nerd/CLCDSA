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
  int n, res = 0;
  cin >> n;
  std::vector<int> h;
  for (int i = 0; i < n; i++) {
    int m1;
    cin >> m1;
    h.push_back(m1);
  }
  h.push_back(0);
  h.push_back(0);
  int left = 0, right = 0;
  while (left < n && right < n) {
    int rangemin = 100;
    while (h[left] == 0 && left < n) left++;
    right = left;
    while (h[right + 1] != 0 && right < n) {
      right++;
    }
    cerr << left << "\t" << right << endl;
    for (int i = left; i <= right; i++) {
      if (h[i] < rangemin) rangemin = h[i];
    }
    for (int i = left; i <= right; i++) {
      h[i] -= rangemin;
    }
    res += rangemin;
    cerr << rangemin << endl;
  }

  cout << res << endl;

  return 0;
}