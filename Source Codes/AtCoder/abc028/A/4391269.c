#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  if(N <= 59){
    printf("Bad\n");
  }else if(N <= 89){
    printf("Good\n");
  }else if(N <= 99){
    printf("Great\n");
  }else{
    printf("Perfect\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^