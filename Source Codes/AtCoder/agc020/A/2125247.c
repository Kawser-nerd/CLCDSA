#include<stdio.h>

int main(void)
{
int a, b, c, d;
scanf("%d%d%d", &a, &b,&c);
d=(c-b)%2;
if(d==0) printf("Alice\n");
else printf("Borys\n");
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d%d", &a, &b,&c);
 ^