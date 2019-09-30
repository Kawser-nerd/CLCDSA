#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  char S[64];
  int len = 0;

  scanf("%s", S);

  while(S[len]){
    len++;
  }

  if(S[len - 1] == 'T'){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^