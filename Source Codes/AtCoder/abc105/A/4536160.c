#include <stdio.h>
 
int main(void) {
  int n, k, ans; scanf("%d %d", &n, &k);
  printf("%d\n", n%k != 0);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   int n, k, ans; scanf("%d %d", &n, &k);
                  ^