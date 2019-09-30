#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
 
int main(void){

  int H, W;
  int i, j;
  int n = 0;

  scanf("%d%d", &H, &W);

  char A[H][16];

  for(i = 0; i < H; i++){
    scanf("%s", A[i]);
  }

  for(i = 0; i < H; i++){
    for(j = 0; j < W; j++){
      if(A[i][j] == '#'){
	n++;
      }
    }
  }

  if(n == H + W - 1){
    printf("Possible\n");
  }else{
    printf("Impossible\n");
  }
    
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &H, &W);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", A[i]);
     ^