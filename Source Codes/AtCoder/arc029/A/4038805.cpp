/**
 * @brief AtCoder Regular Contest 029<br>
 * A - ??????
 *
 * bit???????
 * @see https://atcoder.jp/contests/arc029/tasks/arc029_1
 */

#include <iostream>
using namespace std;

int main() {
  size_t N; cin >> N;
  int t[N]; for (int i{}; i < N; ++i) cin >> t[i];

  int shortest{numeric_limits<int>::max()};
  for (size_t i{}; i < (1 << N); ++i) {
    int t1{}, t2{};
    for (size_t j{}; j < N; ++j) {
      if (i & (1 << j)) {
        t1 += t[j];
      } else {
        t2 += t[j];
      }
    }
    int t = max(t1, t2);
    if (shortest > t) shortest = t;
  }

  cout << shortest << endl;
  return 0;
}