# include <stdio.h>

int main(){
  char S[3];
  scanf("%s",S);
  if(S[0]==S[1]||S[1]==S[2]||S[2]==S[0]) puts("No");
  else puts("Yes");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^