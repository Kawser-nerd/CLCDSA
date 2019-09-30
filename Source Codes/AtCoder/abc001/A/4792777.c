#include <stdio.h>

int main(){
  int h1,h2;
  scanf("%d\n%d",&h1,&h2);
  printf("%d\n",h1-h2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d\n%d",&h1,&h2);
   ^