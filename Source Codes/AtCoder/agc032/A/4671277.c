#include<stdio.h>

int main(){
  int N;
  scanf("%d", &N);

  int i, B[N];

  for(i = 0; i < N; i++){
    scanf("%d", &B[i]);
  }

  for(i = 0; i < N; i++){
    if(B[i] > i + 1){
      printf("-1\n");
      return 0;
    }
  }
  
  int j, k;
  int A[N];
  int c[2];

  for(i = 0; i < N; i++){
    j = 0;
    k = 0;
    c[0] = 0;
    c[1] = 0;
    while(k < N){
      if(B[k] == j + 1 && B[k] > c[0]){
        c[0] = B[k];
        c[1] = k;
        //printf("%d %d\n", c[0], c[1]);
      }
      if(B[k] != 0){
        j++;
      }
      k++;
    }
    A[N - 1 - i] = c[0];
    B[c[1]] = 0;
  }

  for(i = 0; i < N; i++){
    printf("%d\n", A[i]);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &B[i]);
     ^