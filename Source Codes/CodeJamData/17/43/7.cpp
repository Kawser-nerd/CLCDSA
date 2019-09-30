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

const int N = 222;

int sx, sy;
char f[N][N];
vector < ipair > us[N][N];

void go(int x, int y, int d, ipair u)
{
    while (true)
    {
        if (f[x][y] == '#')
            return;
        if (f[x][y] == '+' || f[x][y] == '.')
            us[x][y].push_back(u);
        else if (f[x][y] == '/')
        {
            int d1[] = {3, 2, 1, 0};
            d = d1[d];
        } else {
            int d1[] = {1, 0, 3, 2};
            d = d1[d];
        }
        x += DX[d];
        y += DY[d];
    }
}

struct Konj
{
    ipair a, b;
};


vector < bool > solve(int n, vector < Konj > konjs)
{
    n *= 2;
    static bool e[N][N];
    memset(e, 0, sizeof(e));
    for (Konj k : konjs)
    {
        int x = k.a.X*2 + k.a.Y;
        int y = k.b.X*2 + k.b.Y;
        e[x^1][y] = 1;
        e[y^1][x] = 1;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                e[i][j] |= e[i][k] & e[k][j];

    vector < bool > ans;
    for (int i = 0; i < n/2; ++i)
    {
        if (e[i*2][i*2+1] && e[i*2+1][i*2])
            return vector<bool>();
        if (e[i*2][i*2+1])
            ans.push_back(true);
        else
            ans.push_back(false);
    }
    return ans;
}

void solve()
{
    cin >> sx >> sy;
    for (int i = 0; i < sx; ++i)
        cin >> (f[i+1] + 1);
    sx += 2;
    sy += 2;
    for (int i = 0; i < sx; ++i)
        f[i][0] = f[i][sy-1] = '#';
    for (int i = 0; i < sy; ++i)
        f[0][i] = f[sx-1][i] = '#';

    for (int x = 0; x < sx; ++x)
        for (int y = 0; y < sy; ++y)
            if (f[x][y] == '|' || f[x][y] == '-')
                f[x][y] = '+';

    for (int x = 0; x < sx; ++x)
        for (int y = 0; y < sy; ++y)
            us[x][y].clear();

    int curi = 0;
    for (int x = 0; x < sx; ++x)
        for (int y = 0; y < sy; ++y)
            if (f[x][y] == '+')
            {
                go(x + DX[0], y + DY[0], 0, {curi, 1});
                go(x + DX[1], y + DY[1], 1, {curi, 0});
                go(x + DX[2], y + DY[2], 2, {curi, 1});
                go(x + DX[3], y + DY[3], 3, {curi, 0});
                ++curi;
            }

    vector < Konj > konjs;
    for (int x = 0; x < sx; ++x)
        for (int y = 0; y < sy; ++y)
            if (f[x][y] == '+')
            {
                for (ipair a : us[x][y])
                    konjs.push_back({{a.X, !a.Y}, {a.X, !a.Y}});
            } else if (f[x][y] == '.') {
                assert(sz(us[x][y]) <= 2);
                if (us[x][y].empty())
                {
                    cout << "IMPOSSIBLE\n";
                    return;
                }
                if (sz(us[x][y]) == 1)
                    us[x][y].push_back(us[x][y][0]);
                konjs.push_back({us[x][y][0], us[x][y][1]});
            }

    vector < bool > ans = solve(curi, konjs);
    if (ans.empty())
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    curi = 0;
    for (int x = 0; x < sx; ++x)
        for (int y = 0; y < sy; ++y)
            if (f[x][y] == '+')
                f[x][y] = (ans[curi++] ? '|' : '-');

    cout << "POSSIBLE\n";
    for (int x = 1; x < sx - 1; ++x)
    {
        for (int y = 1; y < sy - 1; ++y)
            cout << f[x][y];
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cout.precision(20);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
    {
		cout << "Case #" << i << ": ";
        solve();
        cerr << "Case " << i << "/" << t << " done\n";
    }
    return 0;
}
