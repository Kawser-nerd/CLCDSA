#include <stdio.h>
#include <stdlib.h>
int main(){int a,b,c,d,e,f,k;scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);k=abs((c-a)*(f-b)-(e-a)*(d-b));if(k%2==0)printf("%d\n",k/2);else printf("%d.5\n",k/2);} ./Main.c: In function ‘main’:
./Main.c:3:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(){int a,b,c,d,e,f,k;scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);k=abs((c-a)*(f-b)-(e-a)*(d-b));if(k%2==0)printf("%d\n",k/2);else printf("%d.5\n",k/2);}
                              ^