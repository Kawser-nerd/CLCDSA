#include<stdio.h>

int main(void)
{
 int H,W,h,w,s=0,s2=0,s3=0;

 scanf("%d %d %d %d",&H,&W,&h,&w);

 s=H-h;

 s2=W-w;

 s3=s*s2;

 printf("%d",s3);

 return 0;} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&H,&W,&h,&w);
  ^