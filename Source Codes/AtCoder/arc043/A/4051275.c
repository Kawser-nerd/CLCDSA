#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long N, i;
  long double A, B, P, Q, ave;
  long double sum = 0;
  long double max = 0, min = 1000000000;

  scanf("%ld%Lf%Lf", &N, &A, &B);

  long double S[N];

  for(i = 0; i < N; i++){
    scanf("%Lf", &S[i]);
    sum += S[i];
    if(max < S[i]){
      max = S[i];
    }
    if(min > S[i]){
      min = S[i];
    }
  }

  ave = sum / N;

  P = B / (max - min);
  Q = A - ave * P;

  if(max == min){
    printf("-1\n");
  }else{
    printf("%.6Lf %.6Lf\n", P, Q);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%Lf%Lf", &N, &A, &B);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%Lf", &S[i]);
     ^