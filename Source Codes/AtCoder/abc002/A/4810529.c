#include <stdio.h>

int
main(){
  int x, y;
  scanf("%d %d",&x, &y);
  if(x < 0 || 1000000000 < y)
    return 1;
  printf("%d\n",x > y? x:y);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&x, &y);
   ^