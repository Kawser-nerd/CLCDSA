#include <stdio.h>

int main(void){
  int N,T[100];
  int M,P[100],X[100];
  int i,j;
  int sum = 0;
  
  scanf("%d",&N);
  for(i = 0;i < N; ++i){
    scanf(" %d",&T[i]);
    sum += T[i];
  }
  scanf(" %d",&M);
  for(j = 0;j < M; ++j)	scanf(" %d %d",&P[j],&X[j]);
  
  for(i = 0;i < M; ++i)  printf("%d\n",sum - (T[P[i] - 1] - X[i]));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf(" %d",&T[i]);
     ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %d",&M);
   ^
./Main.c:15:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(j = 0;j < M; ++j) scanf(" %d %d",&P[j],&X[j]);
                         ^