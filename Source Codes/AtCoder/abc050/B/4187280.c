#include<stdio.h>

int main(){
  int N, T[100], M, P, X, tot = 0, i, result[100];
  
  scanf("%d", &N);
  for (i = 0; i < N; i++){
    scanf("%d",&T[i]);
    tot += T[i];
  }
  scanf("%d", &M);
  for (i = 0; i < M; i++){
    scanf("%d %d", &P, &X);
    result[i] = tot - T[P - 1] + X;
  }
  
  for (i = 0; i < M; i++){
    printf("%d\n", result[i]);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&T[i]);
     ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &M);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &P, &X);
     ^