#include<stdio.h>

int main(void){
  int a,b,c,n;
  
  scanf("%d",&n);
  
  a = n/3600;
  b = (n%3600)/60;
  c = (n%3600)%60;
  
  printf("%02d:%02d:%02d\n",a,b,c);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^