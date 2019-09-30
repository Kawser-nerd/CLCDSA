#include <stdio.h>

int main(void){
  int T,N;
  scanf("%d%d",&T,&N);

  int A[N];
  for(int i = 0;i < N;i++){
    scanf("%d",&A[i]);
  }

  int M,t;
  int num = 0;
  scanf("%d",&M);
  for(int i = 0 ;i < M;i++){
    scanf("%d",&t);
    while(1){
      if(num == N){
        printf("no\n");
        return 0;
      }
      if(0<= t-A[num] && t-A[num] <= T){
        num++;
        break;
      }
      num++;
    }
  }

  printf("yes\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&T,&N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A[i]);
     ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&M);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&t);
     ^