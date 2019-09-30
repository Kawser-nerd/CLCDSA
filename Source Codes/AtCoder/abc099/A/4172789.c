#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  if(N < 1000)
    printf("ABC\n");
  else
    printf("ABD\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^