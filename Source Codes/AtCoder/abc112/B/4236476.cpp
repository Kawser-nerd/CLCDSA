#include <cstdio>
#include <algorithm>

int main() {
  int N, T;
  scanf("%d %d", &N, &T);

  int c_min = 1001;
  for (int i = 0; i < N; ++i) {
    int c, t;
    scanf("%d %d", &c, &t);

    if (t <= T)
      c_min = std::min(c_min, c);
  }

  if (c_min > 1000) {
    puts("TLE");
  } else {
    printf("%d\n", c_min);
  }
}