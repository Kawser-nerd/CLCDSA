#include <stdio.h>

int main(void){
  int N, D, X;
  int A[100] = {};
  int i, j, k;
  scanf("%d", &N);
  scanf("%d %d", &D, &X);
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  for(i = 0; i < N; i++){
    j = 0;
    while(j*A[i] + 1 <= D){
      X++;
      j++;
    }
  }
  printf("%d\n", X);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &D, &X);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &A[i]);
     ^