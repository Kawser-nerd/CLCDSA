#include <stdio.h>
#include <stdlib.h>

static inline int min(const int a, const int b) {
  return a < b ? a : b;
}
static inline int max(const int a, const int b) {
  return a > b ? a : b;
}

#define Z 2001

int IMOS[Z][Z];
int N, K;

static inline void g(const int x_from, const int x_to, const int y_from, const int y_to) {
  IMOS[x_from][y_from] += 1;
  IMOS[x_to][y_from] -= 1;
  IMOS[x_from][y_to] -= 1;
  IMOS[x_to][y_to] += 1;
}

void f(const int x_from, const int x_to, const int y_from, const int y_to) {
  g(x_from, min(x_to, 2*K), y_from, min(y_to, 2*K));
  if (x_to > 2*K && y_to > 2*K) {
    g(0, x_to-2*K, 0, y_to-2*K);
    g(0, x_to-2*K, y_from, 2*K);
    g(x_from, 2*K, 0, y_to-2*K);
  } else if (x_to > 2*K) {
    g(0, x_to-2*K, y_from, y_to);
  } else if (y_to > 2*K) {
    g(x_from, x_to, 0, y_to-2*K);
  }
}

int main(void) {
  scanf("%d %d\n", &N, &K);

  for (int i = 0; i < N; ++i) {
    int x_from, y_from;
    char c;
    scanf("%d %d %c", &x_from, &y_from, &c);

    int x_add = c == 'W' ? 0 : K;
    x_from = (x_from + x_add) % (2*K);
    y_from %= 2*K;

    int x_to = x_from + K;
    int y_to = y_from + K;
    f(x_from, x_to, y_from, y_to);

    int x_from1 = x_from + K;
    int x_to1 = x_to + K;
    int y_from1 = y_from + K;
    int y_to1 = y_to + K;
    if (x_from1 >= 2*K) {
      x_from1 %= 2*K;
      x_to1 %= 2*K;
    }
    if (y_from1 >= 2*K) {
      y_from1 %= 2*K;
      y_to1 %= 2*K;
    }
    f(x_from1, x_to1, y_from1, y_to1);
  }

  for (int x = 0; x < Z; ++x)
    for (int y = 1; y < Z; ++y)
      IMOS[x][y] += IMOS[x][y-1];

  for (int x = 1; x < Z; ++x)
    for (int y = 0; y < Z; ++y)
      IMOS[x][y] += IMOS[x-1][y];

  int ans = 0;
  for (int x = 0; x < Z; ++x)
    for (int y = 0; y < Z; ++y)
      if (IMOS[x][y] > ans)
        ans = IMOS[x][y];
  printf("%d\n", ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d\n", &N, &K);
   ^
./Main.c:42:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %c", &x_from, &y_from, &c);
     ^