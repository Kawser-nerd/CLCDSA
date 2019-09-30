/**
 * @brief AtCoder Regular Contest 061<br>
 * C- ??????? / Many Formulas
 *
 * bit???????
 * @see https://arc061.contest.atcoder.jp/tasks/arc061_a
 */
#include <iostream>
using namespace std;

constexpr unsigned BIT = 1;

int main() {
  string S;
  cin >> S;
  size_t len{S.size()};

  long total{};
  for (size_t i{}; i < (BIT << (len - 1)); ++i) {
    long temp = S[0] & 0xF;
    for (size_t j{}; j < len - 1; ++j) {
      if (i & (BIT << j)) {
        total += temp;
        temp = 0;
      }
      temp *= 10;
      temp += S[j + 1] & 0xF;
    }
    total += temp;
  }

  cout << total << endl;
  return 0;
}