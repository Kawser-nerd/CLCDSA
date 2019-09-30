#include <stdio.h>
#include <stdlib.h>

int px[900001],py[900001];
int d[900001];

int main(void){
  int H,W,D;
  scanf("%d%d%d",&H,&W,&D);

  int A;
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      scanf("%d",&A);
      px[A] = i; py[A] = j;
    }
  }

  for(int i = D+1;i <= H*W;i++){
    d[i] = d[i-D]+abs(px[i]-px[i-D])+abs(py[i]-py[i-D]);
  }
  int Q;
  scanf("%d",&Q);

  int L,R;
  for(int i = 0;i < Q;i++){
    scanf("%d%d",&L,&R);
    printf("%d\n",d[R]-d[L]);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&H,&W,&D);
   ^
./Main.c:14:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&A);
       ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&Q);
   ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&L,&R);
     ^