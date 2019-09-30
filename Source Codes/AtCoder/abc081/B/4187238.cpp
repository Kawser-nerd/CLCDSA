#include <cstdio>
#include <algorithm>

int main() {
  int N;
  scanf("%d", &N);

  int res = 40;
  for (int i = 0; i < N; ++i) {
    int A;
    scanf("%d", &A);
    int cur = 0;
    while (A % 2 == 0) {
      A /= 2;
      ++cur;
    }
    res = std::min(res, cur);
  }
  printf("%d\n", res);
}