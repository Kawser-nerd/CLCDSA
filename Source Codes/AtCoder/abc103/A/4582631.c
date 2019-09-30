#include <stdlib.h>
#include <stdio.h>
int main(){
int a,b,c,d,e,f;
scanf("%d%d%d",&a,&b,&c);
d=abs(a-b)+abs(a-c);
e=abs(b-a)+abs(b-c);
f=abs(c-a)+abs(c-b);
if(d==e==f) printf("%d",0);
else if(d<=e&&d<=f) printf("%d",d);
else if(e<=d&&e<=f) printf("%d",e);
else if(f<=d&&f<=e) printf("%d",f);




return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d%d",&a,&b,&c);
 ^