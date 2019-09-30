#include <cstdio>
#include <algorithm>

constexpr int six_pows[] = {1, 6, 36, 216, 1296, 7776, 46656, 279936};
constexpr int nine_pows[] = {1, 9, 81, 729, 6561, 59049, 531441};

int main() {
  int N;
  scanf("%d", &N);

  int res = N;
  for (int i = 0; i < nine_pows[6]; ++i) {
    int m = 0;
    int cur = 0;
    int k = i;
    for (int j = 0; j < 6; ++j) {
      m += (k % 9) * nine_pows[j];
      cur += k % 9;
      k /= 9;
    }
    if (m > N) continue;
    for (int j = 7; j--;) {
      while (m + six_pows[j] <= N) {
        m += six_pows[j];
        ++cur;
      }
    }
    res = std::min(res, cur);
  }
  printf("%d\n", res);
}