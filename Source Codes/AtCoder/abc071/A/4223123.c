#include <stdio.h>
#include <stdlib.h>

int main(void){
  int x,a,b;
  scanf("%d%d%d",&x,&a,&b);

  if(abs(x-a) > abs(x-b)) printf("B\n");
  else printf("A\n");


  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&x,&a,&b);
   ^