#include <iostream>
#include <sstream>
using namespace std;

int main() {
  string s;
  cin >> s;

  for (int i{}; i < (1 << (s.length() - 1)); ++i) {
    ostringstream oss;
    int num{s[0] & 0xF};
    oss << s[0];
    for (int j{}; j < s.length() - 1; ++j) {
      if (i & (1 << j)) {
        oss << '+';
        num += s[j+1] & 0xF;
      } else {
        oss << '-';
        num -= s[j+1] & 0xF;
      }
      oss << s[j+1];
    }
    if (num == 7) {
      cout << oss.str() << "=7" << endl;
      break;
    }
  }

  return 0;
}