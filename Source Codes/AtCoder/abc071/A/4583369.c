#include <stdlib.h>
#include <stdio.h>
int main(){
int x,a,b;
scanf("%d%d%d",&x,&a,&b);
if(abs(x-a)>abs(x-b)) printf("B");
else if(abs(x-b)>(x-a)) printf("A");


return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d%d",&x,&a,&b);
 ^