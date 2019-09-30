#include <stdio.h>
int main(void){
int N;
  scanf("%d",&N);
  if(N<=999){
  printf("ABC");
  }
  else{
  printf("ABD");
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^