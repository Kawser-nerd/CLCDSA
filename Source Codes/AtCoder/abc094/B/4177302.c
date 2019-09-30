#include <stdio.h>

int main(void){
  int N,M,X;
  scanf("%d%d%d",&N,&M,&X);
  int data[N+1],sample;
  int cost = 0,ans;

  for(int i = 0;i < N+1;i++){
    data[i] = 0;
  }

  for(int i = 0;i < M;i++){
    scanf("%d",&sample);
    data[sample] = 1;
  }

  cost = 0;
  for(int i = 0;i < X;i++){
    if(data[i] == 1){
      cost++;
    }
  }
  ans = cost;

  cost = 0;
  for(int i = X;i < N+1;i++){
    if(data[i] == 1){
      cost++;
    }
  }

  if(ans > cost){
    ans = cost;
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&N,&M,&X);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&sample);
     ^