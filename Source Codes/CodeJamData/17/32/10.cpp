///      That's a Cigarette Day, my Sun

#include <bits/stdc++.h>

#pragma pack(1)
#pragma GCC optimize("O3")

#define pb push_back
#define mp make_pair
#define fi first
#define prev asfansjfansjabfasjlbfa
#define se second
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define elif else if
#define out_files freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define all(x) (x).begin(), (x).end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define y1 asnflainflawnfaw
#define y0 snalfklawnfasdaspqw
#define BLEAT cout << "bleat!!!\n"
#define files(x) ((x != "") ? freopen(x".in", "r", stdin), freopen(x".out", "w", stdout) : 0)
#define files_dat_sol(x)  ((x != "") ? freopen(x".dat", "r", stdin), freopen(x".sol", "w", stdout) : 0)
#define next askfnlabfae

using namespace std;

typedef std::vector <int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair <int, int> pii;
typedef std::vector <pii> vii;
typedef double ld;

#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif // WIN32

const int inf = 1000000000;
const ll INF = 1LL*inf*inf;
const long double eps = 1e-9;
const ll md = 1e9 + 7;
const long double EPS = 1e-5;
const ll maxll = std::numeric_limits<ll>::max();
const long double PI = acos(-1.0);

template <typename name> inline name sqr(name x)
{
    return x*x;
}

ld log(ld base, ld n)
{
    return log(n) / log(base);
}

inline ll multmod(ll a, ll b, ll md)
{
    if (!a) return 0;
    if (a % 2 == 1)
        return (multmod(a-1, b, md) + b) % md;
    else
        return sqr(multmod(a/2, b, md)) % md;
}

template <typename name> inline name bpow(const name& base, ll exp, const ll& md = maxll)
{
    if (exp == 1) return base;
    if (exp % 2 == 1)
        return (bpow<name>(base, exp-1, md) * base) % md;
    else
    {
        name k = bpow<name>(base, exp/2, md);
        return (k*k)%md;
    }
}

unsigned char ccc;

inline void read(int &n)
{
    n = 0;
    bool _minus = false;
    while (true) {
        ccc = getchar();
        if (ccc == ' ' || ccc == '\n')
            break;
        if (ccc == '-') {
            _minus = true;
            continue;
        }
        n = n * 10 + ccc - '0';
    }
    if (_minus)
        n *= -1;
}

inline void read(int &n, int& m)
{
    read(n);
    read(m);
}

inline void read(int &n, int &m, int &k)
{
    read(n);
    read(m);
    read(k);
}

inline void read(std::string &s)
{
    s = "";
    while (true)
    {
        ccc = getchar();
        if (ccc == ' ' || ccc == '\n')
            break;
        s += ccc;
    }
}

template<typename T1, typename T2> inline T1 min(const T1 x, const T2 y)
{
    return (x > y ? y : x);
}

template<typename T1, typename T2> inline T1 max(const T1 x, const T2 y)
{
    return (x < y ? y : x);
}

template<typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& rhs)
{
    os << rhs.fi << " " << rhs.se;
    return os;
}

template<typename T1> ostream& operator<<(ostream& os, const vector<T1>& rhs)
{
    for (int i=0; i<(int)rhs.size(); i++)
        cout << rhs[i] << (i == (int)rhs.size() - 1 ? "" : " ");
    return os;
}

template<typename T> inline void minimize(T& value, const T& relax_value)
{
    value = min(value, relax_value);
}

template<typename T> inline void maximize(T& value, const T& relax_value)
{
    value = max(value, relax_value);
}

template<typename T> const vector<T> operator + (const vector<T>& lhs, const T& rhs)
{
    vector<T> buff = lhs;
    for (auto &x : buff)
        x += rhs;
    return buff;
}

///-------------------------End of Template-------------------------///

const int MAXN = 3000;

int dp[MAXN][MAXN][2][2], can[MAXN][2];

main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("debug.txt", "w", stderr);
    #else
        files_dat_sol("exam");
    #endif // LOCAL

    int T;
    scanf(I, &T);
    int num = 1;
    while(T--)
    {

        int cnt1, cnt2;
        scanf(II, &cnt1, &cnt2);

        for (int i=0; i<1440; i++)
            can[i][0] = 1,
            can[i][1] = 1;

        for (int i=0; i<1440; i++)
            for (int j=0; j<1440; j++)
                for (int k=0; k<2; k++)
                    for (int q=0; q<2; q++)
                        dp[i][j][k][q] = inf;

        for (int i=0; i<cnt1; i++)
        {
            int l, r;
            scanf(II, &l, &r);
            for (int j=l; j<r; j++)
                can[j][0] = 0;
        }
        for (int i=0; i<cnt2; i++)
        {
            int l, r;
            scanf(II, &l, &r);
            for (int j=l; j<r; j++)
                can[j][1] = 0;
        }

        if (can[0][0]) dp[1][0][0][0] = 0;
        if (can[0][1]) dp[0][1][1][1] = 0;

        for (int i=1; i<1440; i++)
        {
            for (int j=0; j<min(i + 1, 720); j++)
            {
                if (can[i][0])
                    dp[j+1][i-j][0][0] = min(dp[j][i-j][0][0], dp[j][i-j][0][1] + 1),
                    dp[j+1][i-j][1][0] = min(dp[j][i-j][1][0], dp[j][i-j][1][1] + 1);
                if (can[i][1])
                    dp[i-j][j+1][0][1] = min(dp[i-j][j][0][1], dp[i-j][j][0][0] + 1),
                    dp[i-j][j+1][1][1] = min(dp[i-j][j][1][1], dp[i-j][j][1][0] + 1);
            }
        }

        int ans = min({dp[720][720][0][0], dp[720][720][1][0] + 1, dp[720][720][1][1], dp[720][720][0][1] + 1});

        cout << "Case #" << num << ": " << ans << "\n";
        num++;
    }
}
