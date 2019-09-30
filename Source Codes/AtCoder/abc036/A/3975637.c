#include <stdio.h>
int main(void){
  int a,b,cases=0;
  scanf("%d%d",&a,&b);
  while(1){
    cases++;
    if(a*cases>=b) break;
  }
  printf("%d",cases);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^