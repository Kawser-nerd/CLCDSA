#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  char X[64];
  int len, i;
  int t = 0;

  scanf("%s", X);

  len = strlen(X);

  for(i = 0; i < len; i++){
    if(X[i] == 'c'){
      i++;
      if(X[i] != 'h'){
	t = 1;
	break;
      }
    }else if((X[i] != 'o') && (X[i] != 'k') && (X[i] != 'u')){
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
   scanf("%s", X);
   ^