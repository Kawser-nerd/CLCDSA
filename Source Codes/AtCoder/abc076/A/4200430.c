#include <stdio.h>

int main(void){
  int R,G;
  scanf("%d%d",&R,&G);

  printf("%d\n",R+(G-R)*2);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&R,&G);
   ^