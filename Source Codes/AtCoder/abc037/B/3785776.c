#include<stdio.h>
int N, Q, L, R, T, i, j;
int A[100];
int main(){
  scanf("%d%d", &N, &Q);
  for(i=0; i<Q; i++){
    scanf("%d%d%d", &L, &R, &T);
    for(j=L-1; j<R; j++){
      A[j]=T;
    }
  }
  for(i=0; i<N; i++){
    printf("%d\n", A[i]);
  }
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &N, &Q);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &L, &R, &T);
     ^