#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main(void){
  int a,b,c,d,sum;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  if(fmin(b,d)-fmax(a,c)<=0) sum=0;
  else sum=fmin(b,d)-fmax(a,c);
  printf("%d",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&a,&b,&c,&d);
   ^