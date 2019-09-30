#include <iostream>
using namespace std;
const int maxn = 200005;
const int INF = 1000000005;
typedef long long ll;
ll a[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    ll ans = 0;
    bool flag = true;
    if(a[1] != 0)flag = false;
    for(int i = n; i >= 2; i--)
    {
        if(a[i] > a[i-1])
        {
            if(a[i]-a[i-1] != 1)flag = false;
            ans++;
        }
        else if(a[i] <= a[i-1])
        {
            ans += a[i];
        }
    }
    if(flag)cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}