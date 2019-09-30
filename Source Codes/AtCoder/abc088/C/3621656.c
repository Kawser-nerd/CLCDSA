#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){
  
  int c[3][3];
  int i, j;

  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      scanf("%d", &c[i][j]);
    }
  }

  if((((c[0][0] - c[0][1]) == (c[1][0] - c[1][1]) && (c[0][0] - c[0][1]) == (c[2][0] - c[2][1]))) && (((c[0][0] - c[0][2]) == (c[1][0] - c[1][2]) && (c[0][0] - c[0][2]) == (c[2][0] - c[2][2])))){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &c[i][j]);
       ^