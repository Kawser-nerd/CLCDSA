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
  std::unordered_set<int64_t> set;
  for (int i = 0; i < n; i++) {
    int m1;
    cin >> m1;
    if (set.find(m1) == set.end()) {
      set.insert(m1);
    } else {
      set.erase(m1);
    }
  }
  cout << set.size() << endl;

  return 0;
}