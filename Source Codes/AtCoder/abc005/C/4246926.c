#include<stdio.h>

int main(){
  int T, N, a[100] = {1000}, M, b[100], i, j, k;
  
  scanf("%d", &T);
  scanf("%d", &N);
  for (i = 0; i < N; i++){
    scanf("%d", &a[i]);
  }
  scanf("%d", &M);
  k = 0;
  for (i = 0; i < M; i++){
    scanf("%d", &b[i]);
    for (j = k; j < N; j++){
      if(a[j] + T >= b[i] && b[i] >= a[j]){
        k = j + 1;
        break;
      }
    }
    if(j == N){
      printf("no\n");
      return 0;
    }
  }
  
  printf("yes\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &T);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &M);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &b[i]);
     ^