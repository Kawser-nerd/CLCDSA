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

static vector<ll> palin;

static inline ll pow10(int x)
{
    ll a = 1;
    for (int i = 0; i < x; i++)
        a *= 10;
    return a;
}

static void make_pal(const ll *p10p, ll val, int d, int p)
{
    if (2 * p >= d)
        palin.push_back(val);
    else
    {
        if (p == 0)
            val += p10p[0];
        for (int i = p ? 0 : 1; i < 10; i++)
        {
            make_pal(p10p, val, d, p + 1);
            val += p10p[p];
        }
    }
}

static void init()
{
    for (int d = 1; d <= 13; d++)
    {
        ll p10p[20];

        for (int i = 0; i < d / 2; i++)
            p10p[i] = pow10(i) + pow10(d - 1 - i);
        if (d & 1)
            p10p[d / 2] = pow10(d / 2);
        make_pal(p10p, 0, d, 0);
    }

    palin.push_back(pow10(13) + 1);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    init();

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        ll A, B;
        ll sz[2] = {0, 0};
        cin >> A >> B;

        B++;
        ll ptr = 0;
        while (palin[ptr] < A) ptr++;
        if (palin[ptr] >= B)
            sz[0] = B - A + 1;
        else
        {
            sz[0] = palin[ptr] - A + 1;
            int parity = 1;
            while (palin[ptr + 1] < B)
            {
                sz[parity] = (sz[parity] + palin[ptr + 1] - palin[ptr]) % MOD;
                ptr++;
                parity = !parity;
            }
            sz[parity] = (sz[parity] + B - palin[ptr]) % MOD;
        }

        ll ans = sz[0] * sz[0] + sz[1] * sz[1] - sz[0] - sz[1];
        ans %= MOD;
        ans = (ans * ((MOD + 1) / 2)) % MOD;

        printf("Case #%d: %lld\n", cas + 1, ans);
    }
    return 0;
}
