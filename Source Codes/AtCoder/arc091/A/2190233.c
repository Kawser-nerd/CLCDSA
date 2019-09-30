#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long  n,m;
    long long sum;
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        if(n==1&&m==1)
            sum=1;
        else if(n==1)
            sum=m-2;
        else if(m==1)
            sum=n-2;
        else
            sum=n*m-m*2-(n-2)*2;
        printf("%lld\n",sum);
    }
    return 0;
}