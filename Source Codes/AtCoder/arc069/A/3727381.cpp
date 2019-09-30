#include<stdio.h>
#define ll long long
int main()
{
    ll n, m;
    while(scanf("%lld%lld", &n, &m)!=EOF)
    {
        ll ans=0;
        if(m/2>n) ans+=n+(m-2*n)/4;
        else ans+=m/2;
        printf("%lld\n", ans);
    }
    return 0;
}