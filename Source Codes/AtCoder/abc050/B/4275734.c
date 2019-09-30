#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  int T[N];
  int sum = 0;
  for(int i = 0;i < N;i++){
    scanf("%d",&T[i]);
    sum += T[i];
  }

  int M;
  scanf("%d",&M);

  int p,x;
  for(int i = 0;i < M;i++){
    scanf("%d%d",&p,&x);
    printf("%d\n",sum-T[p-1]+x);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&T[i]);
     ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&M);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&p,&x);
     ^