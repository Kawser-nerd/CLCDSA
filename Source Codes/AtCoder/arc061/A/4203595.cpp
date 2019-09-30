#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  size_t len = S.length();

  long total{};
  for (size_t i{}; i < (1 << len-1); ++i) {
    long acc{S[0] & 0xF};
    for (int j{}; j < len-1; ++j) {
      if (i & (1 << j)) {
        total += acc;
        acc = 0;
      }
      acc *= 10;
      acc += S[j+1] & 0xF;
    }
    total += acc;
  }

  cout << total << endl;
  return 0;
} ./Main.cpp:10:33: warning: operator '<<' has lower precedence than '-'; '-' will be evaluated first [-Wshift-op-parentheses]
  for (size_t i{}; i < (1 << len-1); ++i) {
                          ~~ ~~~^~
./Main.cpp:10:33: note: place parentheses around the '-' expression to silence this warning
  for (size_t i{}; i < (1 << len-1); ++i) {
                                ^
                             (    )
1 warning generated.