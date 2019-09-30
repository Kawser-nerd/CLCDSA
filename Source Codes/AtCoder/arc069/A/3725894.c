#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int  x,y,s2,s1;
    scanf("%lld%lld",&x,&y);
    if(y<x*2)
        s2=y/2;
    else
    {
        s1=y-x*2;
        s2=x+s1/4;
    }
    printf("%lld",s2);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&x,&y);
     ^