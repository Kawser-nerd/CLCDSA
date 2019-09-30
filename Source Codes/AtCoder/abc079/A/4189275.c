#include <stdio.h>

int main(){
  char S[4];
  int k,judge=0;
  scanf("%s",S);
  if(S[0]==S[1]&&S[1]==S[2]) puts("Yes");
  else if(S[1]==S[2]&&S[2]==S[3]) puts("Yes");
  else puts("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^