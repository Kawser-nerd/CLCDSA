#include<stdio.h>
int main(){
  int i,j=0;
  
  scanf("%d",&i);
  j = i - 1;
  printf("%d\n",j);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&i);
   ^