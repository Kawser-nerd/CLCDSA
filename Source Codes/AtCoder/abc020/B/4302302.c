#include<stdio.h>
int main(){
  int a,b;
  scanf("%d%d",&a,&b);
  printf("%d\n",2*(b+a*(10+(b/10>0)*90+(b/100>0)*900)));
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^