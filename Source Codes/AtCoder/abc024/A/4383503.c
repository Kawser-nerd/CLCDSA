#include <stdio.h>
int main(){
int a,b,c,d,e,f;
scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
int s=0;
s=a*e+b*f;

if(d>e+f) printf("%d\n",s);
else
if(d<=e+f) printf("%d\n",s-c*(e+f));

return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
 ^