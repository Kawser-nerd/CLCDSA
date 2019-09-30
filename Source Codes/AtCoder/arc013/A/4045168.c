#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int N, M, L, P, Q, R;
  int max = 0;

  scanf("%d%d%d%d%d%d", &N, &M, &L, &P, &Q, &R);

  if(max < (N / P) * (M / Q) * (L / R)){
    max = (N / P) * (M / Q) * (L / R);
  }
  if(max < (N / P) * (M / R) * (L / Q)){
    max = (N / P) * (M / R) * (L / Q);
  }
  if(max < (N / Q) * (M / P) * (L / R)){
    max = (N / Q) * (M / P) * (L / R);
  }
  if(max < (N / Q) * (M / R) * (L / P)){
    max = (N / Q) * (M / R) * (L / P);
  }
  if(max < (N / R) * (M / P) * (L / Q)){
    max = (N / R) * (M / P) * (L / Q);
  }
  if(max < (N / R) * (M / Q) * (L / P)){
    max = (N / R) * (M / Q) * (L / P);
  }

  printf("%d\n", max);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d%d", &N, &M, &L, &P, &Q, &R);
   ^