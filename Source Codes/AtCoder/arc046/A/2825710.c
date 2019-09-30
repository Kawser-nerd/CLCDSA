#include<stdio.h>
int main(){
  int n,i;
  scanf("%d",&n);
  n--;
  for(i=0;i<n/9+1;i++)printf("%d",n%9+1);
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^