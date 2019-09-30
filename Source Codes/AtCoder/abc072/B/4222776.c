#include <stdio.h>
#include <string.h>

int main(void){
  char S[100000];
  scanf("%s",S);

  for(int i = 0;i < strlen(S);i += 2){
    printf("%c",S[i]);
  }
  printf("\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^