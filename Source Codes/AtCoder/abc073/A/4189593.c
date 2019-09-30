#include <stdio.h>

int main(){
  char S[2];
  scanf("%s",S);
  if(S[0]=='9'||S[1]=='9') puts("Yes");
  else puts("No");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^