#include <stdio.h>

int main() {
  int A,B;
  scanf("%d %d",&A,&B);
  if (A%2 == 1 && B%2 == 1) printf("Yes\n");
  else printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&A,&B);
   ^