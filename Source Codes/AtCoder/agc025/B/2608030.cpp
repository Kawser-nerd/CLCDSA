#include <stdio.h>

const int MOD=998244353;
long long powmod(long long b,int e)
{
    if (e==1) return b;
    if (e&1) return (powmod((b*b)%MOD,e/2)*b)%MOD;
    return powmod((b*b)%MOD,e/2);
}
long long inv(int x)
{
    return powmod(x,MOD-2);
}
long long fac[300005];
long long invfac[300005];
long long choose(int a,int b)
{
    if (b<0 || b>a) return 0;
    return (((fac[a]*invfac[b])%MOD)*invfac[a-b])%MOD;
}

int n;
long long a,b,k,t;

long long ans=0;

int main()
{
    #ifdef NOT_DMOJ
    freopen("data.txt","r",stdin);
    #endif // NOT_DMOJ
    fac[0]=invfac[0]=1;
    for (int i=1; i<=300000; i++) {
        fac[i]=(fac[i-1]*i)%MOD;
        invfac[i]=(invfac[i-1]*inv(i))%MOD;
    }
    scanf("%d",&n);
    scanf("%lld%lld%lld",&a,&b,&k);
    for (int i=0; i<=n; i++) {
        t=k-a*i;
        if (t<0 || t%b) continue;
        t/=b;
        if (t>n) continue;
        // get (n choose i)*(n choose t)
        //printf("pick %d %d\n",i,t);
        ans+=(choose(n,i)*choose(n,t))%MOD;
    }
    printf("%lld\n",ans%MOD);
}