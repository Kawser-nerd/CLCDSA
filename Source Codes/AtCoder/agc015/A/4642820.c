#include <stdio.h>
#include <stdlib.h>



int main()
{
    long int n;
    long int a,b;
    long int s,s1,s2;
    scanf("%ld %ld %ld",&n,&a,&b);
    //
    if(a>b||n<1||(n==1&&a!=b)||a>1000000000||b>1000000000||n>1000000000)
        printf("0");
    else
    {
        s1=a*(n-1)+b;
        s2=a+b*(n-1);
        s=s2-s1+1;
        printf("%ld",s);
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld",&n,&a,&b);
     ^