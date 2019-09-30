#include<stdio.h>
int main(void){
  int n,a,b,min;
  scanf("%d %d %d",&n,&a,&b);
  min=a*n;
  if(b<min){
    min=b;
  }
  printf("%d\n",min);
  return 0;

} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&a,&b);
   ^