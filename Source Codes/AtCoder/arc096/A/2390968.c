#include <stdio.h>
#include <stdlib.h>

int main(void){
  int a, b, c, x, y, ans;
  scanf("%d %d %d %d %d",&a, &b, &c, &x, &y);
  if(a+b<=2*c) ans = a*x+b*y;
  else{
    if(x < y){
      if(2*c < b) ans = 2*c*y;
      else ans = 2*c*x+b*(y-x);
    }else{
      if(2*c < a) ans = 2*c*x;
      else ans = 2*c*y+a*(x-y);
    }
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d %d",&a, &b, &c, &x, &y);
   ^