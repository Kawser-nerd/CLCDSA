#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }

// ========================================================================= //

int n, c, m;
vector < ipair > ts;

int check(int k)
{
    vector < int > cnt(n);
    for (ipair t : ts)
        ++cnt[t.X];
    int rem = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int w = cnt[i];
        if (w <= k)
            rem = max(0, rem - (k - w));
        else
        {
            rem += w - k;
            ans += w - k;
        }
    }
    return rem == 0 ? ans : -1;
}

ipair solve()
{
    cin >> n >> c >> m;
    ts.resize(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> ts[i].X >> ts[i].Y;
        --ts[i].X;
        --ts[i].Y;
    }
    vector < int > ccnt(c);
    for (ipair t : ts)
        ++ccnt[t.Y];
    int mccnt = 0;
    for (int x : ccnt)
        mccnt = max(mccnt, x);
    int l = mccnt - 1, r = 1024;
    int bestB = 0;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        int res = check(mid);
        if (res == -1)
            l = mid;
        else
        {
            r = mid;
            bestB = res;
        }
    }
    return {r, bestB};
}

int main()
{
    ios::sync_with_stdio(false);
	cout.precision(20);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
    {
        ipair ans = solve();
		cout << "Case #" << i << ": " << ans.X << " " << ans.Y << "\n";
        cerr << "Case " << i << "/" << t << " done\n";
    }
    return 0;
}
