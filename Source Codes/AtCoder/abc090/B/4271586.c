#include<stdio.h>
int main(){
  int a,b,i,j=0;
  scanf("%d%d",&a,&b);
  for(i=a;i<=b;i++){
    if(i/10000==i%10&&(i/1000)%10==(i/10)%10)j++;
  }
  printf("%d",j);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^