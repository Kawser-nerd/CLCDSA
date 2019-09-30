#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> P;
lli MOD = 1000000007;
int main()
{
    lli n, x;
    cin >> n >> x;
    lli ans = 0;
    lli a[100005];
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n - 1)
    {
        if (a[i] + a[i + 1] > x) {
            lli tmp = a[i + 1];
            a[i + 1] = max(0LL, x - a[i]);
            ans += tmp - a[i + 1];
            if (a[i] + a[i + 1] > x) {
                ans += a[i] - x + a[i + 1];
            }
        }
    }
    cout << ans << endl;
}