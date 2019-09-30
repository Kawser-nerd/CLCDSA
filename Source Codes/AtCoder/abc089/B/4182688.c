#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);
  char S;
  int flag = 0;

  for(int i = 0;i < N;i++){
    scanf("%c",&S);
    if(S == 'Y'){
      flag = 1;
      break;
    }
  }

  if(flag){
    printf("Four\n");
  }else{
    printf("Three\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&S);
     ^