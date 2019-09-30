#include <stdio.h>

int main(){
  char s[11];
  for(int i = 0; i < 11; ++i){
    scanf("%c",&s[i]);
  }
  s[3] = '8';
  printf("%s",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&s[i]);
     ^