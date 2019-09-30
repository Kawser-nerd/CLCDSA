#include<stdio.h>

int main(){
  int N, A[100000], C[100000] = {0}, i, count = 0;
  
  scanf("%d", &N);
  for (i = 0; i < N; i++){
    scanf("%d", &A[i]);
    if(C[A[i] - 1] == 1){
      count++;
    } else {
      C[A[i] - 1] = 1;
    }
  }
  
  printf("%d\n", count);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &A[i]);
     ^