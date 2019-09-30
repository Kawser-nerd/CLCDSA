#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int countSite(long long int K, long long int C, long long int init)
{
    long long int site=init;
    int i;
    for(i=1;i<C;++i)
    {
        site = (site-1)*K+ (((site-1) %K)+1) + ((site%K)>0);
        //printf("%d\n", site);
    }
    return site;
}

void solve(int K, int C, int S)
{
    int i;
    if(  S*C < K  )
    {
        printf(" IMPOSSIBLE");
    }
    else
    {
        for(i=1;i<=K;i+=C)
        {
            printf(" %lld", countSite((long long int )K, (long long int )C, (long long int )i));
        }
    }

    printf("\n");
}


/*
{
    long long int site[101];
    long long int nowK;
    int i, j;
    for(i=1;i<=K;++i)
    {
        site[i] = i;
    }
    for(i=1, nowK=K;i<C;++i, nowK *= K)
    {
        for(j=1;j<=K;++j)
        {
            site[j] = site[j]+nowK*(j-1);
        }
    }
    for(i=1;i<=K;++i)
    {
        printf(" %lld", site[i]);
    }
    printf("\n");
}
*/
int main()
{
    int t, T;
    int K, C, S;
    scanf("%d",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%d %d %d",&K ,&C ,&S);

        printf("Case #%d:", t);
        solve(K, C, S);
    }

    return 0;
}
