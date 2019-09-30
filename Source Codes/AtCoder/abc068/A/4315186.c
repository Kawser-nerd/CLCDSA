#include <stdio.h>

int main(){
  
   int x;
  scanf("%d",&x);
  if(x<100 || x>999){}
  else
  printf("ABC%d",x);
  
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^