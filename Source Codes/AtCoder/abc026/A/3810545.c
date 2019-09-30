#include<stdio.h>
int main(void){
  int n;
  int x;
  int y;
  
  scanf("%d",&n);
  

  
  x=(n/2);
  y=(n/2);
 
  printf("%d",x*y);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^