#include <stdio.h>

int tcase;
long long n,K,ans;

int main()
{
    int i,cas;
    long long t,x,high;
    
    scanf("%d",&tcase);
    for(cas=1;cas<=tcase;cas++)
    {
        scanf("%lld%lld",&n,&K);
        for(high=1;high<=K;high<<=1);
        high >>= 1;
        
        t = (n-high+1)/high;
        x = (n-high+1) - t*high;
        
        if(K-high+1 <= x) ans = t+1;
        else ans = t;
        
        printf("Case #%d: %lld %lld\n",cas,ans>>1,(ans-1)>>1);
    }
    
    return 0;
}