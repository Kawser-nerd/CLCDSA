#include <stdio.h>

int digit(int n) {
  int count = 0;
  while (n) {
    count += n % 10;
    n /= 10;
  }
  return count;
}

int main(void) {
  int n, i, ans, tmp;
  scanf("%d", &n);
  ans = 1000000;
  for (i = 1; i < n; i++) {
    tmp = digit(i) + digit(n - i);
    if (tmp < ans) ans = tmp;
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^