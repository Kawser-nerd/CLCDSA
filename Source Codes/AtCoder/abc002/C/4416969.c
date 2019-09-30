#include<stdio.h>
#include<stdlib.h>

int main(){
  int x[9],i=0;
  for(;i<6;i++) scanf("%d",&x[i]);
  double s= abs( (x[2]-x[0])*(x[5]-x[1]) - (x[3]-x[1])*(x[4]-x[0]));
  printf("%lf",s/2);
} ./Main.c: In function ‘main’:
./Main.c:6:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(;i<6;i++) scanf("%d",&x[i]);
                 ^