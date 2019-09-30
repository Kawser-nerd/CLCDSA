#include<stdio.h>
int main(){
  int a,b,k,i;
  scanf("%d%d%d",&a,&b,&k);
  for(i=a;i<=b;i++){
    if(i<a+k||i>b-k) printf("%d\n",i);
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&k);
   ^