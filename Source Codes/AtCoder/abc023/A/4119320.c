#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
  int a,b,n;
  
  scanf("%d",&n);
  
  a = n%10;
  b = (n-a)/10;
  
  printf("%d\n",a+b);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^