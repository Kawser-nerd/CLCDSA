#include<stdio.h>

int main(void){
  double a,b,c,d;
  scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
  if(b/a>d/c) printf("TAKAHASHI\n");
  else if(b/a<d/c) printf("AOKI\n");
  else printf("DRAW\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
   ^