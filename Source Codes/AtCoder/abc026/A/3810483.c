#include<stdio.h>

int main(){
  
  int a,x,y;
  
  scanf("%d",&a);
  
  x=a/2;
  y=x;
  
  printf("%d\n",x*y);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^