#include <stdio.h>

int main(){
  
  int h,i;
  scanf("%d",&h);
  scanf("%d",&i);
  
  printf("%d\n",h-i);
  
  return 0;
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&h);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&i);
   ^