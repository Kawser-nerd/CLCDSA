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
  int a, b;
  cin >> a >> b;
  if (a <= 0 && 0 <= b) {
    cout << "Zero" << endl;
  } else if (1 <= a) {
    cout << "Positive" << endl;
  } else if ((b - a + 1) % 2 == 0) {
    cout << "Positive" << endl;
  } else {
    cout << "Negative" << endl;
  }

  return 0;
}