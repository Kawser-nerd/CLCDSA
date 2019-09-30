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
    if(S[i] == 'O' || S[i] == 'D'){
      S[i] = '0';
    }else if(S[i] == 'I'){
      S[i] = '1';
    }else if(S[i] == 'Z'){
      S[i] = '2';
    }else if(S[i] == 'S'){
      S[i] = '5';
    }else if(S[i] == 'B'){
      S[i] = '8';
    }
  }

  for(i = 0; i < len; i++){
    printf("%c", S[i]);
  }
  printf("\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^