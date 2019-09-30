#include<stdio.h>
typedef long long ll;
ll solve(ll x,ll n)
{
    ll ans;
    if(n%x==0)
        return n*2-x;
    ans=n/x*x*2+solve(n%x,x);
    return ans;
}
int main()
{
    ll n,x;
    ll ans;
 
    scanf("%lld%lld",&n,&x);
    ans=solve(x,n-x)+n;
    printf("%lld\n",ans);
    return 0;
}