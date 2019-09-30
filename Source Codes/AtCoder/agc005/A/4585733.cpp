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
  std::string x;
  int64_t result = 0;
  cin >> x;
  result    = x.size();
  int count = 0;
  for (auto c : x) {
    if (c == 'S') {
      count++;
    } else if (c == 'T') {
      if (count > 0) {
        count--;
        result -= 2;
      }
    }
  }
  cout << result << endl;

  return 0;
}