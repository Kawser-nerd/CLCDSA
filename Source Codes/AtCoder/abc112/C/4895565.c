#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int N;
  scanf("%d",&N);

  int x[N],y[N],h[N];
  for(int i = 0;i < N;i++) scanf("%d%d%d",&x[i],&y[i],&h[i]);

  int H;
  for(int i = 0;i < N;i++){
    if(h[i] == 0) continue;
    for(int cx = 0;cx <= 100;cx++){
      for(int cy = 0;cy <= 100;cy++){
        H = h[i]+llabs(cx-x[i])+llabs(cy-y[i]);
        for(int j = 0;j < N;j++){
          if(h[j] != max(H-llabs(cx-x[j])-llabs(cy-y[j]),0)) break;
          if(j == N-1){
            printf("%d %d %d\n",cx,cy,H);
            return 0;
          }
        }
      }
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:16:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d%d%d",&x[i],&y[i],&h[i]);
                            ^