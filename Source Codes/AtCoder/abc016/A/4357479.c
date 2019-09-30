#include <stdio.h>
int main(void){
  int m,d;
  scanf("%d%d",&m,&d);
  if(m%d==0) printf("YES\n");
  else printf("NO\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&m,&d);
   ^