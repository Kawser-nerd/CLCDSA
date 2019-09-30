#include <stdio.h>
int main(void){
  int h,w,ans=0;
  scanf("%d %d",&h,&w);
  ans+=(w-1)*h;
  ans+=w*(h-1);
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&h,&w);
   ^