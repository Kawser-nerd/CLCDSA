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
  std::stack<char> stk;
  // OutputError("hogee");
  for (auto c : x) {
    // OutputError("hogee");
    if (c == 'S') {
      // OutputError("push s");
      stk.push('S');
    } else {
      if (stk.size() > 0 && stk.top() == 'S') {
        // OutputError("Pop");
        stk.pop();
      } else {
        // OutputError("push T");
        stk.push('T');
      }
    }
  }
  cout << stk.size() << endl;

  return 0;
}