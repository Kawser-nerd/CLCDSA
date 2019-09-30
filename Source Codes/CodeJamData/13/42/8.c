#include <stdio.h>


int main()
{
    int T,t;


    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        int n;
        long long p,pp;
        int x,y;
        int i;

        scanf("%d %lld",&n,&p);

        if (p==(1LL<<n))
        {
            printf("Case #%d: %lld %lld\n",t,p-1,p-1);
            continue;
        }

        for(x=0;;x++)
            if (((1LL<<(n-1-x))&(p-1))==0)
                break;

        for(y=0;y<n;y++)
            if (((1LL<<(n-1-y))&p)!=0)
                break;

        printf("Case #%d: %lld %lld\n",t,(1LL<<x+1)-2,(1LL<<n)-(1LL<<y+1));
    }

    return 0;
}
