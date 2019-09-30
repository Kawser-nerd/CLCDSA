#include <stdio.h>
#include <stdlib.h>

int int_sort( const void * a , const void * b ) {
  return (*(int*)b - *(int*)a);
}

int main(void) {
  int N, K;
  scanf("%d %d", &N, &K);
  int R[100];
  for(int i = 0; i < N; i++) {
    scanf("%d", &R[i]);
  }
  qsort((void*)R, N, sizeof(int), int_sort);

  double C = 0;
  for(int i = 1; i <= K; i++) {
    C = (C + R[K-i]) / 2.0;
  }
  printf("%f\n", C);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &K);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &R[i]);
     ^