#include<stdio.h>
int main(void){
  int n;
  scanf("%d",&n);
  if(n>=1200) printf("ARC\n");
  else printf("ABC\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^