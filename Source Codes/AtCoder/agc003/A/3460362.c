#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
 
int main(void){

  char S[1024];
  int i;
  int len = 0;
  int n = 0, s = 0, e = 0, w = 0;

  scanf("%s", S);

  while(S[len]){
    len++;
  }

  for(i = 0; i < len; i++){
    if(S[i] == 'N'){
      n = 1;
    }else if(S[i] == 'S'){
      s = 1;
    }else if(S[i] == 'E'){
      e = 1;
    }else{
      w = 1;
    }
  }

  if((n + s == 0 || n + s == 2) && (e + w == 0 || e + w == 2)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
    
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^