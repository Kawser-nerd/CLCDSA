#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
  int N;
  int *P;
  scanf("%d", &N);
  P = (int*)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
  }

  int *A = (int*)calloc(N+1, sizeof(int));
  for (int i = 0; i < N; i++) {
    if (A[P[i]-1] > 0) {
      A[P[i]] = A[P[i]-1]+1;
      A[P[i]-1] = 0;
    } else {
      A[P[i]] = 1;
    }
  }
  int max = 0;
  for (int i = 1; i <= N; i++) {
    if (max < A[i]) max = A[i];
  }
  printf("%d\n", N-max);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &P[i]);
     ^