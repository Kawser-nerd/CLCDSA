#include <stdio.h>

int main(void){
  int N,K;
  scanf("%d%d",&N,&K);
  int ans = 1;

  for(int i = 0;i < N;i++){
    if(ans <= K){
      ans *= 2;
    }else{
      ans += K;
    }
  }
  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&K);
   ^