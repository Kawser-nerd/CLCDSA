#include <stdio.h>
#include <stdlib.h>

int main(void){
  int xa,ya,xb,yb,xc,yc;
  scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);

  xb -= xa;
  yb -= ya;
  xc -= xa;
  yc -= ya;

  printf("%.5lf\n",(double)abs(xb*yc-yb*xc)/2);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);
   ^