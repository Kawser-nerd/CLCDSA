#include <iostream>
using namespace std;
#define LL long long

const LL MOD = 1e9 + 7;
LL n;

LL get(LL x, LL y)
{
    LL ret = 0;
    while(x >= y) {
        ret += x / y;
        x /= y;
    }
    return ret;
}


bool prime(int x)
{
    if(x < 2) return false;
    if(x == 2) return true;
    if(x % 2 == 0) return false;
    for(int i=3;i*i<=x;i+=2) if(x % i == 0) return false;
    return true;
}

int main()
{

    while(cin >> n){
        LL ans = 1;
        for(int i=2;i<=n;i++){
            if(!prime(i)) continue;
            LL dv = get(n, i);
//            cout << i << ' ' << dv << '\n';
            ans = (ans * (dv + 1LL)) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}