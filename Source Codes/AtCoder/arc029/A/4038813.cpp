/**
 * @brief AtCoder Regular Contest 029<br>
 * A - ??????
 *
 * bit???????
 * @see https://atcoder.jp/contests/arc029/tasks/arc029_1
 */

#include <iostream>
using namespace std;

constexpr unsigned BIT = 1;

int main() {
  size_t N;
  cin >> N;
  int t[N];
  for (int i{}; i < N; ++i) cin >> t[i];

  int shortest{numeric_limits<int>::max()};
  for (size_t i{}; i < (BIT << N); ++i) {
    int t1{}, t2{};
    for (size_t j{}; j < N; ++j) {
      if (i & (BIT << j)) {
        t1 += t[j];
      } else {
        t2 += t[j];
      }
    }
    int larger = max(t1, t2);
    if (shortest > larger) shortest = larger;
  }

  cout << shortest << endl;
  return 0;
}