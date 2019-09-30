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

  for(i = 0; i < len; i++){
    if('1' <= S[i] && S[i] <= '9'){
      printf("%c", S[i]);
      if('0' <= S[i + 1] && S[i + 1] <= '9'){
	printf("%c\n", S[i + 1]);
      }else{
	printf("\n");
      }
      break;
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^