#include <stdlib.h>
#include <string.h>
#include <stdio.h>

long long int m[10000];
long long int n;

int main()
{
    long long int T, t;
    long long int x, y, z;
    long long int i;
    long long int max;
    scanf("%lld ",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%lld", &n);
        for(i=0;i<n;++i)
        {
            scanf("%lld",&m[i]);
        }
        for(i=1, y=0, max=0;i<n;++i)
        {
            x = (m[i]<m[i-1])*(m[i-1]-m[i]);
            y += x;
            if(max <x)max = x;
        }
        for(i=0, z=0;i+1<n;++i)
        {
            z += (max<m[i])?max:m[i];
        }
        printf("Case #%lld: %lld %lld\n", t, y, z);
    }

    return 0;
}
