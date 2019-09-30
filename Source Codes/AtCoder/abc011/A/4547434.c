#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  N++;
  if(N == 13) N = 1;
  printf("%d\n",N);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^