#include <iostream>
#include <vector>
#include <algorithm>

enum{ MOD=1000000007 };
template<class T>
static T inv(T a)
{
    T b=MOD;
    T u=0, v=1;
    while(a)
    {
        const auto t=b/a;
        std::swap(b-=t*a,a);
        std::swap(u-=t*v,v);
    }
    return (u+MOD)%MOD;
}

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    for(int H,W,A,B; std::cin >> H >> W >> A >> B; )
    {
        std::vector<long long> fact(std::max(H,W)*2+1); fact[0]=1;
        for(int i=1; i<fact.size(); ++i) fact[i]=fact[i-1]*i%MOD;
        long long sum=0;
        const auto d1=inv(fact[B-1]);
        const auto d2=inv(fact[W-B-1]);
        for(int i=1; i<=H-A; ++i)
        {
            const auto v1 = fact[B+i-2]*inv(fact[i-1])%MOD*d1%MOD;
            const auto v2 = fact[H-i+W-B-1]*inv(fact[H-i])%MOD*d2%MOD;
            sum=(sum+v1*v2)%MOD;
        }
        std::cout << sum << std::endl;
    }
}