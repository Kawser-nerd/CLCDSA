#include <stdio.h>
#include <math.h>
int main(void){
  int a,b,c,x,max;
  scanf("%d%d%d%d",&a,&b,&c,&x);
  int sum=a+b+c;
  max=fmax(a,fmax(b,c));
  sum-=max;
  for(int i=1;i<=x;i++){
    max*=2;
  }
  printf("%d",sum+max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&a,&b,&c,&x);
   ^