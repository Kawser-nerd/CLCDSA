#include <algorithm>
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
lli MOD = 1000000007;

int n;
lli solve(vector<pair<lli, lli>> g)
{
    int t1, t2;
    vector<pair<lli, lli>> g1, g2;
    rep(i, n)
    {
        t1 = g[i].first;
        t2 = g[i].second;
        if (t1 - t2 < 0)
            g1.push_back(make_pair(t1, t2));
        if (t1 - t2 >= 0)
            g2.push_back(make_pair(t2, t1));
    }
    sort(g1.begin(), g1.end());
    sort(g2.begin(), g2.end());
    reverse(g2.begin(), g2.end());
    lli now = 0, x = 0;
    rep(i, g1.size())
    {
        now += g1[i].first;
        x = max(now, x);
        now -= g1[i].second;
    }
    rep(i, g2.size())
    {
        now += g2[i].second;
        x = max(now, x);
        now -= g2[i].first;
    }
    return x;
}
int main()
{
    cin >> n;
    lli a, b;
    vector<pair<lli, lli>> v;
    rep(i, n)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    using p = pair<lli, lli>;
    sort(v.begin(), v.end(), [](const p l, const p r) -> bool {
        return max(l.first, l.first - l.second + r.first) < max(r.first, r.first - r.second + l.first);
    });
    lli h = 0;
    lli ans = v[0].first;
    rep(i, n)
    {
        //cout << v[i].first << ' ' << v[i].second << endl;
        h += v[i].first;
        ans = max(ans, h);
        h -= v[i].second;
    }
    cout << min(ans, solve(v)) << endl;
}