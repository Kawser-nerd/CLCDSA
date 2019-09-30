#include <stdio.h>

#define MAXN 500
#define MOD 100003

int n;
int c[MAXN][MAXN];
int f[MAXN + 1][MAXN];

void pre() {
  int i, j, k;

  c[0][0] = 1;
  for (j = 1; j < MAXN; ++j) {
    c[j][0] = 1;
    c[j][j] = 1;
    for (k = 1; k < j; ++k)
      c[j][k] = (c[j-1][k-1] + c[j-1][k]) % MOD;
  }
}

int work() {
  int i, j, k;

  pre();

  for (i = 2; i <= MAXN; ++i) {
    f[i][1] = 1;
    for (j = 2; j < i; ++j) {
      f[i][j] = 0;
      for (k = 2 * j - i; k < j; ++k)
	f[i][j] = (f[i][j] + f[j][k] * c[i - j - 1][j - k - 1]) % MOD;
    }
  }
}

int main() {
  int t, i, j, ans;

  work();
  scanf("%d", &t);
  for (i = 1; i <= t; ++i) {
    scanf("%d", &n);

    ans = 0;
    for (j = 1; j < n; ++j)
      ans = (ans + f[n][j]) % MOD;

    printf("Case #%d: %d\n", i, ans);
  }

  return 0;
}
