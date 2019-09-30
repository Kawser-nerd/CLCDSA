#include<stdio.h>

int main(void){
   int x1,x2,x3,y1,y2,y3;
   double s;
   scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
   
   x2=x2-x1;
   y2=y2-y1;
   x3=x3-x1;
   y3=y3-y1;

   s=(x2*y3>x3*y2)?(double)(x2*y3-x3*y2)/2.0:(double)(y2*x3-y3*x2)/2.0;
   printf("%f\n",s);

   return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    ^