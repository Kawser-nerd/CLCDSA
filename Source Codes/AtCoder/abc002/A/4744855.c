#include <stdio.h>
int main(){
  long x,y;
  scanf("%ld%ld",&x,&y);
  (x>y) ? printf("%ld\n",x) : printf("%ld\n",y);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld",&x,&y);
   ^