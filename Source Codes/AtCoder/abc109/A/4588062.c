#include <stdio.h>
int main() {
  int A,B,ans;
  scanf("%d %d",&A,&B);
  ans = A*B;
  if (ans % 2 != 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&A,&B);
   ^