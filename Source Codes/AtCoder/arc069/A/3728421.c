#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long a, b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        if(b>a)
            printf("%lld\n",(b-2*a)/4+a);
        else
            printf("%lld\n",b/2);

    }
    return 0;
}