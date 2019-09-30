#include <stdio.h>
#include <string.h>
int main(void){
  int w,a,b,dis;
  scanf("%d %d %d",&w,&a,&b);
  if(a+w<=b) dis=b-(a+w);
  else dis=a-(b+w);
  if(dis<0) puts("0");
  else printf("%d\n",dis);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&w,&a,&b);
   ^