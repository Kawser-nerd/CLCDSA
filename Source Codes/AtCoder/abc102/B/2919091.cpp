#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
typedef long long ll;
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    int ans = -1;
    REP(i, n)
    cin >> a[i];
    REP(i, n)
    {
        FOR(j, i, n)
        {
            ans = max(ans, abs(a[i] - a[j]));
        }
    }
    cout << ans << endl;
    return 0;
}