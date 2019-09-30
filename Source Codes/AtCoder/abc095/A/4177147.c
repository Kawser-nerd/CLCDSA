#include <stdio.h>

int main(void){
  char S[3];

  scanf("%s",S);
  int ans = 700;

  for(int i = 0;i < 3;i++){
    if(S[i] == 'o')
      ans += 100;
  }

  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^