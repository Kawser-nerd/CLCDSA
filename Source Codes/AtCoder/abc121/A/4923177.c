#include<stdio.h>

int main(void)
{
  int H,W,h,w,n,m,k,a;
  scanf("%d%d%d%d",&H,&W,&h,&w);
  n=H*W;
  m=h*W;
  k=(H-h)*w;
  a=n-(k+m);
  printf("%d\n",a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&H,&W,&h,&w);
   ^