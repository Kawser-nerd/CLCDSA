#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  if((N/10)%111 == 0 || (N%1000)%111 == 0){
    printf("Yes\n");
  }else{
    printf("No\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^