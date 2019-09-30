#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int A[4][4], i, j;
  int t = 0;

  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      scanf("%d", &A[i][j]);
    }
  }

  for(i = 0; i < 4; i++){
    for(j = 1; j < 4; j++){
      if(A[i][j] == A[i][j - 1]){
	t = 1;
	break;
      }
    }
    if(t == 1){
      break;
    }
  }

  if(t == 0){
    for(j = 0; j < 4; j++){
      for(i = 1; i < 4; i++){
	if(A[i][j] == A[i - 1][j]){
	  t = 1;
	  break;
	}
      }
      if(t == 1){
	break;
      }
    }
  }

  if(t == 1){
    printf("CONTINUE\n");
  }else{
    printf("GAMEOVER\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &A[i][j]);
       ^