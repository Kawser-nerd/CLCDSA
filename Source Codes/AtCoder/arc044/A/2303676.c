#include<stdio.h>
int readint(void){int x;scanf("%d",&x);return x;}
int main(void)
{
    int n=readint();
    if(n==2||n==3||n==5) puts("Prime");
    else if(n%2&&n%3&&n%5&&n!=1) puts("Prime");
    else puts("Not Prime");
	return 0;
} ./Main.c: In function ‘readint’:
./Main.c:2:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int readint(void){int x;scanf("%d",&x);return x;}
                         ^