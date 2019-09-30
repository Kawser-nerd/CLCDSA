#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define MOD 10007

static ll mod(ll a, ll m)
{
    a %= m;
    if (a < 0) a += m;
    return a;
}

static ll inverse(ll a, ll m)
{
    a = mod(a, m);
    if (a == 1) return 1;
    return mod((1 - m * inverse(m % a, a)) / a, m);
}

static int itable[MOD];
static int ftable[MOD];

static void setup()
{
    itable[0] = 0;
    ftable[0] = 1;
    for (int i = 1; i < MOD; i++)
    {
        itable[i] = inverse(i, MOD);
        ftable[i] = (ftable[i - 1] * i) % MOD;
    }
}

static void factorial(int n, int &p, int &m)
{
    if (n < MOD)
    {
        p = 0;
        m = ftable[n];
    }
    else
    {
        int s = n / MOD;
        factorial(s, p, m);
        p += s;
        m = (m * ftable[n % MOD]) % MOD;
        if (s & 1) m = mod(-m, MOD);
    }
}

static int choose(int n, int r)
{
    int pa, pb, pc;
    int ma, mb, mc;

    if (r < 0 || r > n) return 0;
    factorial(n, pa, ma);
    factorial(r, pb, mb);
    factorial(n - r, pc, mc);
    if (pa > pb + pc)
        return 0;

    mb = (mb * mc) % MOD;
    return (ma * itable[mb]) % MOD;
}

static ll countit(ll x, ll y)
{
    if (x < 0 || y < 0) return 0;
    int man = x + y;
    if (man % 3) return 0;
    x -= man / 3;
    y -= man / 3;
    return choose(x + y, x);
}

int main()
{
    int cases;
    cin >> cases;
    setup();
    for (int cas = 0; cas < cases; cas++)
    {
        int H, W, R;
        cin >> H >> W >> R;
        vector<pii> rocks(R);
        pii end(H, W);
        pii start(1, 1);
        for (int i = 0; i < R; i++)
            cin >> rocks[i].first >> rocks[i].second;
        sort(RA(rocks));
        rocks.push_back(end);

        ll ans = 0;
        for (int i = (1 << R); i < (2 << R); i++)
        {
            ll cur = 1;
            pii pos = start;
            for (int j = 0; j <= R; j++)
            {
                if (i & (1 << j))
                {
                    int dr = rocks[j].first - pos.first;
                    int dc = rocks[j].second - pos.second;
                    cur = (cur * countit(dr, dc)) % MOD;
                    pos = rocks[j];
                }
            }
            if (__builtin_parity(i))
                ans += cur;
            else
                ans -= cur;
        }
        printf("Case #%d: ", cas + 1);
        printf("%lld\n", mod(ans, MOD));
    }
    return 0;
}
