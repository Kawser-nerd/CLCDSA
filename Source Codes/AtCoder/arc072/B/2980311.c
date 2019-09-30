#include <stdio.h>
#include <math.h>

int main(void){
  int x,y;
  scanf("%d%d",&x,&y);
  if(abs(x-y) <= 1)printf("Brown");
  else printf("Alice");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:6: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
   if(abs(x-y) <= 1)printf("Brown");
      ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^