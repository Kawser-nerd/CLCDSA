#include<stdio.h>
int main(){
   int a,b,n;
   scanf("%d%d%d",&n,&a,&b);
   int total1=a*n;
   if(total1>b)printf("%d\n",b);
   else printf("%d\n",total1);
} ./Main.c: In function ‘main’:
./Main.c:4:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d%d",&n,&a,&b);
    ^