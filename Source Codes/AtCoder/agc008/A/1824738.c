#include <stdio.h>
#include <stdlib.h>
int main() {
  long long x,y,c=0;
  scanf("%lld %lld",&x,&y);
  if (x*y<0||(x==0&&y<0)||(y==0&&x>0)) {
    c=1;
  } else if ((llabs(y)-llabs(x))*x<0) {
    c=2;
  }
  printf("%lld\n",c+llabs(llabs(y)-llabs(x)));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&x,&y);
   ^