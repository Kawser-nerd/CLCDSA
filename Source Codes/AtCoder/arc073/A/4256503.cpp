#include <cstdio>
#include <vector>

int main() {
  int N, T;
  scanf("%d %d", &N, &T);

  int res = 0;
  int last = -T;
  for (int i = 0; i < N; ++i) {
    int t;
    scanf("%d", &t);

    if (last+T < t) {
      res += T;
    } else {
      res += t-last;
    }
    last = t;
  }
  printf("%d\n", res);
}