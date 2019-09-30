#include <stdio.h>

void Katsusando(int M, int N) {
  int i, j, K, food, A[M], B[M];
  for (i = 0; i < M; i++) {
    A[i] = 1;
  }
  for (i = 0; i < N && scanf("%d",&K); i++) {
    for (j = 0; j < M; j++) {
      B[j] = 0;
    }
    for (j = 0; j < K && scanf("%d",&food); j++) {
      B[food-1] = 1;
    }
    for (j = 0; j < M; j++) {
      if (!B[j]) {
        A[j] = 0;
      }
    }
  }
  for (i = 0, j = 0; i < M; i++) {
    if (A[i]) {
      j += 1;
    }
  }
  printf("%d",j);
}

int main(void) {
  int N, M;
  scanf("%d%d",&N,&M);
  Katsusando(M,N);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^