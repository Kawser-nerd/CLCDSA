#include <stdio.h>

int main(){
  int a,b,i,max=-1111111111;
  scanf("%d %d",&a,&b);
  i = a+b;
  if(max <i) max=i;
  i = a-b;
  if(max <i) max=i;
  i = a*b;
  if(max <i) max=i;
  
  printf("%d",max);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^