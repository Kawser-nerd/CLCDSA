#include <stdio.h>
#include <stdlib.h>
int main(){
int a,b,c,d,e,f,g;
scanf("%d%d%d%d",&a,&b,&c,&d);
e=abs(b-a);
f=abs(c-a);
g=abs(c-b);

if(g<=d&&e<=d||f<=d) printf("Yes");
else printf("No");

return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d%d%d",&a,&b,&c,&d);
 ^