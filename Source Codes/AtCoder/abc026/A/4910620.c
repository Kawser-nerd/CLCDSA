#include<stdio.h>

int main(){
  
  int a;
  scanf("%d",&a);
  
  int b=a/2;
  
  printf("%d",b*b);
  
  return 0;
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^