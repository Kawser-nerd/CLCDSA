#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  char S[16];
  int len, i;

  scanf("%s", S);

  len = strlen(S);

  if(S[0] >= 'a' && S[0] <= 'z'){
    S[0] += 'A' - 'a';
  }

  for(i = 1; i < len; i++){
    if(S[i] >= 'A' && S[i] <= 'Z'){
      S[i] += 'a' - 'A';
    }
  }

  printf("%s\n", S);
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^