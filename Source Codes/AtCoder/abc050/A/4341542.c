#include <stdio.h>
int main(void){
int a,b;
char d;
scanf("%d %c %d",&a,&d,&b);
if(d=='+'){printf("%d\n",a+b);}
else{printf("%d\n",a-b);}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %c %d",&a,&d,&b);
 ^