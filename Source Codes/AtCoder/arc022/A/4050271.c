#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  char S[128];
  int len, i, j, k;
  int t = 0;

  scanf("%s", S);

  len = strlen(S);

  for(i = 0; i < len; i++){
    if(S[i] == 'I' || S[i] == 'i'){
      for(j = i + 1; j < len; j++){
	if(S[j] == 'C' || S[j] == 'c'){
	  for(k = j + 1; k < len; k++){
	    if(S[k] == 'T' || S[k] == 't'){
	      t = 1;
	      break;
	    }
	  }
	}
	if(t == 1){
	  break;
	}
      }
    }
    if(t == 1){
      break;
    }
  }

  if(t == 1){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^