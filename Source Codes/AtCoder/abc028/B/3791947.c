#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  char S[128];
  int len = 0;
  int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;
  int i;

  scanf("%s", S);

  while(S[len]){
    len++;
  }

  for(i = 0; i < len; i++){
    if(S[i] == 'A'){
      A++;
    }else if(S[i] == 'B'){
      B++;
    }else if(S[i] == 'C'){
      C++;
    }else if(S[i] == 'D'){
      D++;
    }else if(S[i] == 'E'){
      E++;
    }else{
      F++;
    }
  }

  printf("%d %d %d %d %d %d\n", A, B, C, D, E, F);
 
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^