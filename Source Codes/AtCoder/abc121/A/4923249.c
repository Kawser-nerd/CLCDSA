#include <stdio.h>
int main(void)
{
  int H,W,h,w,s;
  scanf("%d%d%d%d",&H,&W,&h,&w);

  s = H*W - h*W - H*w + h*w;

  printf("%d",s);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&H,&W,&h,&w);
   ^