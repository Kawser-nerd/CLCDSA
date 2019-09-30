#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  string S;
  int T;
  cin >> S >> T;
  int L = 0, R = 0, U = 0, D = 0, q = 0;
  for (auto x : S) {
    if (x == 'L') L++;
    else if (x == 'R') R++;
    else if (x == 'U') U++;
    else if (x == 'D') D++;
    else q++;
  }
  int l = abs(L - R) + abs(U - D);
  if (T == 1) {
    cout << l+q << endl;
  } else {
    if (q <= l) {
      cout << l-q << endl;
    } else if ((l-q)%2 == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
}