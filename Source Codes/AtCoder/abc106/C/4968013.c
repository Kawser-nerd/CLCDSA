#include <stdio.h>

int main(void){
  char S[100];
  scanf("%s",S);

  long long K;
  scanf("%lld",&K);

  for(int i = 0;i < K;i++){
    if(S[i] != '1'){
      printf("%c\n",S[i]);
      return 0;
    }
  }

  printf("1\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&K);
   ^