//C99

#include <stdio.h>
#include <stdlib.h>

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    int b, n;
    scanf("%d %d", &b, &n);
    int*m = (int*) malloc(b * sizeof(int));
    for (int j = 0; j < b; ++j) {
      scanf("%d", m + j);
    }
    int cm = 1;
    for (; ; ++cm) {
      int ok = 1;
      for (int j = 0; j < b; ++j) {
        if (cm % m[j] > 0) {
          ok = 0;
          break;
        }
      }
      if (ok) break;
    }
    int mod = 0;
    for (int j = 0; j < b; ++j) {
      mod += cm / m[j];
    }
    n = (n - 1) % mod + 1;
    int f = 0;
    int*x = (int*) calloc(b, sizeof(int));
    for (int r = 0; r < n; ++r) {
      f = -1;
      int y = 123;
      for (int j = 0; j < b; ++j) {
        if (x[j] < y) {
          y = x[j];
          f = j;
        }
      }
      if (y > 0) {
        for (int j = 0; j < b; ++j) {
          x[j] -= y;
        }
      }
      x[f] += m[f];
    }
    printf("Case #%d: %d\n", i, f + 1);
    free(m);
    free(x);
  }
}
