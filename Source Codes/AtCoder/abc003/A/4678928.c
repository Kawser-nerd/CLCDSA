#include <stdio.h>

int main() {
  int N, ave;
  scanf("%d", &N);
  ave = (N + 1) * 10000 / 2;
  printf("%d\n", ave);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^