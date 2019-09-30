#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#include <climits>
#include <fcntl.h>
#include <unistd.h>

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

static void redirect(int argc, const char **argv)
{
    if (argc > 1)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }

    if (argc > 2)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }
}

#define MOD 1000000007

static ll factorial[71];
static ll choose[71][71];

static void make_factorial()
{
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i <= 70; i++)
        factorial[i] = (factorial[i - 1] * i) % MOD;

    for (int i = 0; i <= 70; i++)
    {
        choose[i][i] = choose[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
            if (choose[i][j] >= MOD)
                choose[i][j] -= MOD;
        }
    }
}

// axes: 
// - minimum digit (> 0)
// - num summands
// - sum
static int prep[71][71][2415];

static void make_prep(int D)
{
    memset(prep, 0, sizeof(prep));
    for (int low = 0; low <= D; low++)
        prep[low][0][0] = 1;

    int top = D * (D - 1) / 2;
    for (int num = 1; num < D; num++)
        for (int low = D - 1; low > 0; low--)
            for (int sum = 0; sum <= top; sum++)
            {
                ll ans = prep[low + 1][num][sum];
                if (low <= sum)
                {
                    ans += prep[low + 1][num - 1][sum - low];
                    if (ans >= MOD)
                        ans -= MOD;
                }
                prep[low][num][sum] = ans;
            }
}

static int dp[65][35][71][2];

static ll mod(ll a, ll m)
{
    a %= m;
    if (a < 0) a += m;
    return a;
}

static ll inverse(ll a, ll m)
{
    if (a < 0) a += m;

    if (a == 1) return 1;
    return mod((1 - m * inverse(m % a, a)) / a, m);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;

    make_factorial();
    for (int cas = 0; cas < cases; cas++)
    {
        ll N, D;
        cin >> N >> D;
        make_prep(D);

        vector<int> digs;
        while (N)
        {
            digs.push_back(N % D);
            N /= D;
        }

        memset(dp, 0, sizeof(dp));
        int top = D * (D - 1) / 2;
        for (int dig = 0; dig < SZ(digs); dig++)
            for (int carryout = 0; carryout <= D / 2; carryout++)
                for (int zout = 0; zout < 2; zout++)
                    for (int nout = zout; nout <= D; nout++)
                    {
                        ll part = 0;
                        for (int carryin = 0; carryin <= D / 2; carryin++)
                            for (int zin = 0; zin < 2; zin++)
                                for (int nin = max(zin, nout); nin <= D; nin++)
                                {
                                    if (nout < zin)
                                        continue;
                                    int sum = digs[dig] - carryin + D * carryout;
                                    if (sum < 0 || sum > top)
                                        continue;
                                    ll p;
                                    if (dig == 0)
                                    {
                                        p = (carryin == 0 && nin == nout && zin == 0);
                                    }
                                    else
                                    {
                                        p = dp[dig - 1][carryin][nin][zin];
                                        p = (p * choose[nin - zin][nout - zin]) % MOD;
                                        p = (p * factorial[nout]) % MOD;
                                    }
                                    p = (p * prep[1][nout - zout][sum]);
                                    part += p;
                                }
                        dp[dig][carryout][nout][zout] = part % MOD;
                    }

        ll ans = 0;
        for (int nout = 0; nout <= D; nout++)
        {
            ll part = 1; //inverse(factorial[nout], MOD);
            part = (part * dp[SZ(digs) - 1][0][nout][0]) % MOD;
            ans += part;
        }
        ans %= MOD;
        printf("Case #%d: %lld\n", cas + 1, ans);
    }
    return 0;
}
