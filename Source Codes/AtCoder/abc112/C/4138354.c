#include <stdio.h>

long long absu(int a){
  if(a > 0){
    return a;
  }
  return -a;
}

long long max(long long a,long long b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int N;
  scanf("%d",&N);
  int x[N],y[N];
  long long h[N];

  for(int i = 0;i < N;i++){
    scanf("%d%d%lld",&x[i],&y[i],&h[i]);
  }

  long long H;
  for(int i = 0;i < N;i++){
    if(h[i] != 0){
      for(int cx = 0;cx <= 100;cx++){
        for(int cy = 0;cy <= 100;cy++){
          H = h[i]+absu(cx-x[i])+absu(cy-y[i]);
          for(int j = 0;j < N;j++){
            if(h[j] != max(H-absu(cx-x[j])-absu(cy-y[j]),0)){
              break;
            }
            if(j == N-1){
              printf("%d %d %lld\n",cx,cy,H);
              return 0;
            }
          }
        }
      }
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%lld",&x[i],&y[i],&h[i]);
     ^