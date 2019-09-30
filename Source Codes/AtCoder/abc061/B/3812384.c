#include<stdio.h>
int N, M, a, b, A[51], i;
int main(){
  scanf("%d%d", &N, &M);
  for(i=0; i<M; i++){
    scanf("%d%d", &a, &b);
    A[a]++;
    A[b]++;
  }
  for(i=1; i<=N; i++){
    printf("%d\n", A[i]);
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &N, &M);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^