#include <stdio.h>

int main(void){
  int N,M,a;
  scanf("%d%d",&N,&M);

  int cnt[N];
  for(int i = 0;i < N;i++) cnt[i] = 0;

  for(int i = 0;i < 2*M;i++){
    scanf("%d",&a);
    cnt[a-1]++;
  }

  for(int i = 0;i < N;i++) printf("%d\n",cnt[i]);


  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^