#include<stdio.h>
int main(){
  int a,b,c,d,e,f,i;
  scanf("%d %d",&a,&b);
  scanf("%d %d",&c,&d);
  scanf("%d %d",&e,&f);
  
  a = (a*b)/10;
  c = (c*d)/10;
  e = (e*f)/10;
  
  printf("%d\n",a+c+e);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&c,&d);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&e,&f);
   ^