#include <cmath>
#include <iostream>
#define f first
#define s second
using namespace std;
typedef long long LL;
const int MAXN = 1e6+66;
int main()
{
    LL n,a,b;
    cin>>n;
    int vis = n;
    LL ans = 0;
    LL bb = 1e9+99;
    while(n--)
    {
        cin>>a>>b;
        ans += a;
        if(a == b) vis--;
        if(a > b) bb = min(bb,b);
    }
    if(vis) cout<<(ans-bb);
    else cout<<0;
    return 0;
}