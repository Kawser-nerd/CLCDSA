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
  std::string str;
  bool n = false, w = false, s = false, e = false;
  cin >> str;
  for (auto x : str) {
    if (x == 'N') n = true;
    if (x == 'W') w = true;
    if (x == 'S') s = true;
    if (x == 'E') e = true;
  }
  if (n == s && w == e)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}