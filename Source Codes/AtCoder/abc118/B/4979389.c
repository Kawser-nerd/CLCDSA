#include <stdio.h>

int main(void){
  int N,M,K,A,res=0;
  int cnt[31]={};
  scanf("%d %d",&N,&M);
  
  for(int i=0;i<N;i++){
    scanf("%d",&K);
    for(int j=0;j<K;j++){
      scanf("%d",&A);
      cnt[A-1]++;
    }
  }
  
  for(int i=0;i<M;i++) if(cnt[i]==N) res++;
  printf("%d\n",res);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&M);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&K);
     ^
./Main.c:11:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&A);
       ^