#include<stdio.h>
int main(){
  int a,b,n,m=0;
  scanf("%d %d %d",&a,&b,&n);
  for(m=n;n>=a;m+=b)n-=a-b;
  printf("%d\n",m);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&n);
   ^