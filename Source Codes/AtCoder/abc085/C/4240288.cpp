#include <cstdio>

int main() {
  int N, Y;
  scanf("%d %d", &N, &Y);

  for (int i = 0; i <= N; ++i)
    for (int j = 0; j <= N; ++j) {
      int k = N - (i+j);
      if (k < 0) break;
      if (i + 5*j + 10*k == Y/1000)
        return !printf("%d %d %d\n", k, j, i);
    }
  puts("-1 -1 -1");
}