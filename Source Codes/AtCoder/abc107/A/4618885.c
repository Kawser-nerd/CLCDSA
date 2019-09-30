#include <stdio.h>
int main() {
  int N, i;
  scanf("%d %d", &N, &i);
  int ans = N - i + 1;
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &i);
   ^