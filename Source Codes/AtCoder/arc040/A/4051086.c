#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int N, i, j;
  int r = 0, b = 0;

  scanf("%d", &N);

  char S[N][N];

  for(i = 0; i < N; i++){
    scanf("%s", S[i]);
  }

  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      if(S[i][j] == 'R'){
	r++;
      }else if(S[i][j] == 'B'){
	b++;
      }
    }
  }

  if(r > b){
    printf("TAKAHASHI\n");
  }else if(r < b){
    printf("AOKI\n");
  }else{
    printf("DRAW\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S[i]);
     ^