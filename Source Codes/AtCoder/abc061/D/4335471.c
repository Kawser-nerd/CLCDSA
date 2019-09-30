// https://atcoder.jp/contests/abc061/tasks/abc061_d
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long v[1000][1000], d[1000];

void solv(long long n, long long m) {
  long long i, j, max = LLONG_MIN, a, b, c, updated, count;

  for (i = 0; i < n; i++) {
    d[i] = LLONG_MIN;
    for (j = 0; j < n; j++) {
      v[i][j] = LLONG_MAX;
    }
  }
  for (i = 0; i < m; i++) {
    scanf("%lld %lld %lld", &a, &b, &c);
    v[a - 1][b - 1] = c;
  }

  d[0] = 0;
  for (count = 0, updated = 1; updated && count < n; count++) {
    updated = 0;
    for (i = 0 ; i < n; i++) {
      if (d[i] == LLONG_MIN) {
        continue;
      }
      for (j = 0; j < n; j++) {
        if (v[i][j] == LLONG_MAX) {
          continue;
        }
        if (d[j] < d[i] + v[i][j]) {
          d[j] = d[i] + v[i][j];
          updated = 1;
          if (count == n - 1 && j == n - 1) {
            puts("inf");
            return;
          }
        }
      }
    }
  }

  printf("%lld\n", d[n - 1]);
}

int main(int argc, char **argv) {
  long long n, m;

  while (scanf("%lld %lld", &n, &m) != EOF) {
    solv(n, m);
  }

  return 0;
} ./Main.c: In function ‘solv’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld", &a, &b, &c);
     ^