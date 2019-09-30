#include<stdio.h>

int main(void){
 double a,b;
 scanf("%lf",&a);
 b=a/1000;
 if(b<0.1) printf("00\n");
 else if(b>=0.1&&b<=5) printf("%02.0f\n",b*10);
 else if(b>=6&&b<=30) printf("%2.0f\n",b+50);
 else if(b>=35&&b<=70) printf("%2.0f\n",(b-30)/5+80);
 else if(b>70) printf("89\n");
 return 0;
 } ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf",&a);
  ^