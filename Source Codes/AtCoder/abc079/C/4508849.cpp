#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int a = s[0] - '0';
  int b = s[1] - '0';
  int c = s[2] - '0';
  int d = s[3] - '0';

  for (int i=0; i<8; i++) {
    int sum = a;
    char op[4] = "---";
    if (i & (1 << 2)) {
      sum += b;
      op[0] = '+';
    } else {
      sum -= b;
    }
    if (i & (1 << 1)) {
      sum += c;
      op[1] = '+';
    } else {
      sum -= c;
    }
    if (i & 1) {
      sum += d;
      op[2] = '+';
    } else {
      sum -= d;
    }
    if (sum == 7) {
      cout << a << op[0] << b<<op[1]<<c<<op[2]<<d<<"=7";
      break;
    }
  }
}