#include <stdio.h>
int main(void){
  int a,b,amari;
  scanf("%d",&a);
  scanf("%d",&b);
  amari=a%b;
  if(amari==0) printf("%d\n",0);
  else printf("%d\n",b-amari);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b);
   ^