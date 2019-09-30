#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  char s[1024];
  int len, i;
  int t = 0;

  scanf("%s", s);

  len = strlen(s);

  for(i = 0; i < (len / 2); i++){
    if((s[i] != s[len - 1 - i]) && (s[i] != '*') && (s[len - 1 - i] != '*')){
      t = 1;
      break;
    }
  }

  if(t == 1){
    printf("NO\n");
  }else{
    printf("YES\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^