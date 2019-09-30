#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  char S[12][16];
  int i, j;
  int len[12];
  int ans = 0;

  for(i = 0; i < 12; i++){
    len[i] = 0;
  }

  for(i = 0; i < 12; i++){
    scanf("%s", S[i]);
    while(S[i][len[i]]){
      len[i]++;
    }
    for(j = 0; j < len[i]; j++){
      if(S[i][j] == 'r'){
	ans++;
	break;
      }
    }
  }

  printf("%d\n", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S[i]);
     ^