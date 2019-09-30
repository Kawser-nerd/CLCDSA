#include <stdio.h>
int main(){
int a,b;
scanf("%d%d",&a,&b);
if(b%a==0)printf("%d",b/a);
else printf("%d",(b/a)+1);
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d",&a,&b);
 ^