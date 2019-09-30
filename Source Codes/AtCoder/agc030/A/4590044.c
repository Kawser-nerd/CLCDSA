#include <stdio.h>
int main() {
  int A,B,C;
  /* A:not delicious medicine B:delicious mesicine C:delicious poison */
  scanf("%d %d %d",&A,&B,&C);
  int ans;
  if (A + B >= C) {
    ans	= B + C;
  } else {
    ans	= (A + B) + B + 1;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&A,&B,&C);
   ^