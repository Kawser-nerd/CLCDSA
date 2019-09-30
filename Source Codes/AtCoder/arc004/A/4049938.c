#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int N, i, j;
  int max = 0;

  scanf("%d", &N);

  int x[N], y[N];

  for(i = 0; i < N; i++){
    scanf("%d%d", &x[i], &y[i]);
  }

  for(i = 0; i < N; i++){
    for(j = 0; j < i; j++){
      if(max < ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))){
	max = ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
      }
    }
  }

  printf("%.5f\n", (double)sqrt(max));
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &x[i], &y[i]);
     ^