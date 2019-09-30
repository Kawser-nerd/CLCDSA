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
  std::string s, t;
  cin >> s >> t;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[0]) {
      bool is_same = true;
      for (int j = i; j < n; j++) {
        if (s[j] != t[j - i]) {
          is_same = false;
          break;
        }
      }
      if (is_same) {
        cout << n * 2 - (n - i) << endl;
        exit(0);
      }
    }
  }
  cout << n * 2 << endl;

  return 0;
}