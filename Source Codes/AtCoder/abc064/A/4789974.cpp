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
  int r, g, b;
  cin >> r >> g >> b;
  if ((r * 100 + g * 10 + b) % 4 == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;

  return 0;
}