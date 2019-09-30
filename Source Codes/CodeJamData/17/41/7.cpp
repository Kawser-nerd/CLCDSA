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

unordered_map < ull , int > cc[5];
int n, p;
int go(ull v, int rem)
{
    if (cc[rem].find(v) != cc[rem].end())
        return cc[rem][v];
    if (v == 0)
        return 0;
    int ans = 0;
    for (int i = 1; i < p; ++i)
        if (v & (255ULL << (i*8)))
        {
            ull nv = v - (1ULL << (i*8));
            if (i <= rem)
                ans = max(ans, 0 + go(nv, rem - i));
            else
            {
                int crem = rem + p;
                ans = max(ans, !rem + go(nv, crem - i));
            }
        }
    return cc[rem][v] = ans;
}

int solve()
{
    cin >> n >> p;
    ull v = 0;
    int oo = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x % p == 0)
        {
            ++oo;
            continue;
        }
        x %= p;
        v += (1ULL << (x*8));
    }
    for (int i = 0; i < 5; ++i) {
        cc[i].clear();
    }
	return go(v, 0) + oo;
}

int main()
{
    ios::sync_with_stdio(false);
	cout.precision(20);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
    {
		cout << "Case #" << i << ": " << solve() << "\n";
        cerr << "Case " << i << "/" << t << " done\n";
    }
    return 0;
}
