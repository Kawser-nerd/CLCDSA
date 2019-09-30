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
typedef vector<ll> vll;

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

struct Zombie
{
    int x;
    int y;
    ll t;

    Zombie() {}
    Zombie(int x, int y, ll t) : x(x), y(y), t(t) {}
};

ll dist(int x1, int y1, int x2, int y2)
{
    return max(abs(x2 - x1), abs(y2 - y1));
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int Z;
        cin >> Z;
        vector<Zombie> zom(Z);
        for (int i = 0; i < Z; i++)
        {
            cin >> zom[i].x >> zom[i].y >> zom[i].t;
        }

        vll dp(Z);
        int ans = 0;
        for (int i = 0; i < Z; i++)
        {
            ll reach = dist(0, 0, zom[i].x, zom[i].y) * 100;
            if (reach <= zom[i].t + 1000)
                dp[i] = max(zom[i].t, reach);
            else
                dp[i] = INT_MAX;
        }
        while (count(RA(dp), INT_MAX) < Z)
        {
            ans++;
            vll dp2(Z, INT_MAX);
            for (int i = 0; i < Z; i++)
            {
                for (int j = 0; j < Z; j++)
                {
                    if (i != j && dp[j] != INT_MAX)
                    {
                        ll reach = dp[j] + max(750LL, 100LL * dist(zom[j].x, zom[j].y, zom[i].x, zom[i].y));
                        if (reach <= zom[i].t + 1000)
                        {
                            dp2[i] = min(dp2[i], max(reach, zom[i].t));
                        }
                    }
                }
            }
            dp.swap(dp2);
        }
        printf("Case #%d: %d\n", cas + 1, ans);
    }
    return 0;
}
