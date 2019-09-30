#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;

  long total{};
  for (int i{}; i < (1 << S.length()-1); ++i) {
    long num{S[0] & 0xF};
    for (int j{}; j < S.length()-1; ++j) {
      if (i & (1 << j)) {
        total += num;
        num = 0;
      }
      num *= 10;
      num += S[j+1] & 0xF;
    }
    total += num;
  }

  cout << total << endl;
  return 0;
} ./Main.cpp:9:37: warning: operator '<<' has lower precedence than '-'; '-' will be evaluated first [-Wshift-op-parentheses]
  for (int i{}; i < (1 << S.length()-1); ++i) {
                       ~~ ~~~~~~~~~~^~
./Main.cpp:9:37: note: place parentheses around the '-' expression to silence this warning
  for (int i{}; i < (1 << S.length()-1); ++i) {
                                    ^
                          (           )
1 warning generated.