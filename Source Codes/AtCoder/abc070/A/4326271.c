# include <stdio.h>
# include <stdlib.h>

int main(){
  char S[3];
  scanf("%s",S);
  if(S[0]==S[2]) puts("Yes");
  else puts("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^