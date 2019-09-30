#include<stdio.h>
int main(void){
  int H;
  int W;
  int h;
  int w;
  scanf("%d%d",&H,&W);
  scanf("%d%d",&h,&w);
  int ans=(H-h)*(W-w);
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&H,&W);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^