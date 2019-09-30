#include<iostream>
using namespace std;
long long ok(long long x,long long n)
{
    long long ans;
    if(n%x==0)
        return n*2-x;
    ans=n/x*x*2+ok(n%x,x);
    return ans;
}
int main()
{
    long long n,x,ans;
    scanf("%lld%lld",&n,&x);
    ans=ok(x,n-x)+n;
    printf("%lld\n",ans);
    return 0;
}