#include <stdio.h>
int main (){
int a,b,c,d;
  scanf ("%d %d %d %d",&a,&b,&c,&d);
printf ("%d %d %d %d",b+c-d,-a+c+d,a+b-d,b+c-a);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d %d %d %d",&a,&b,&c,&d);
   ^