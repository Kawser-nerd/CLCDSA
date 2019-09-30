#include <stdio.h>

int main() {
  int N,M,C;
  scanf("%d %d %d",&N,&M,&C);
  int A[N][M],B[M];
  for (int i = 0; i < M; i++) {
    scanf("%d",&B[i]);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d",&A[i][j]);
    }
  }
  int ans=0;
  for (int i = 0; i < N; i++) {
    int sum=0;
    for (int j = 0; j < M; j++) {
      sum += A[i][j]*B[j];
    }
    sum += C;
    if (sum > 0) ans++;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&N,&M,&C);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&B[i]);
     ^
./Main.c:12:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&A[i][j]);
       ^