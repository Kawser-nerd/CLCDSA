#include<stdio.h>
int main(){
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
if(a<b)printf("%d",c/a);
else printf("%d",c/b);
return 0;} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d%d",&a,&b,&c);
 ^