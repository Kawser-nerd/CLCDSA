#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  char X[2], s[64];
  int len, i;

  scanf("%s%s", X, s);

  len = strlen(s);

  for(i = 0; i < len; i++){
    if(s[i] == X[0]){
      continue;
    }else{
      printf("%c", s[i]);
    }
  }
  printf("\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s", X, s);
   ^