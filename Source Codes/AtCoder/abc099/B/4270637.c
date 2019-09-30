#include<stdio.h>
int main(){
  int a,b,i,x=0;
  scanf("%d%d",&a,&b);
  for(i=1;i<b-a;i++){
    x+=i;
  }
  printf("%d",x-a);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^