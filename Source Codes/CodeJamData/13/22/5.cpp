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

    ios::sync_with_stdio(false);
}

static double binom(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0.0;
    if (r + r > n)
        return binom(n, n - r);
    double v = 1.0;
    for (int i = 1; i <= r; i++)
        v = 0.5 * v * (n - i + 1) / i;
    v *= exp2(r - n);
    return v;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    cout << fixed;
    cout.precision(12);
    for (int cas = 0; cas < cases; cas++)
    {
        ll N, X, Y;
        cin >> N >> X >> Y;
        X = llabs(X);
        ll layer = (X + Y) / 2;
        ll full = 0;
        while ((2 * full + 1) * (full + 1) <= N)
            full++;
        double ans;
        if (layer < full)
            ans = 1.0;
        else if (layer > full)
            ans = 0.0;
        else
        {
            ll M = N - full * (2 * full - 1);
            if (X == 0 || Y >= M)
                ans = 0.0;
            else if (M >= 2 * full + Y + 1)
                ans = 1.0;
            else
            {
                ans = 0.0;
                vector<double> choose(1, 1.0);
                for (int i = 1; i <= M; i++)
                {
                    vector<double> next(i + 1);
                    next[0] = next[i] = 0.5 * choose[0];
                    for (int j = 1; j < i; j++)
                        next[j] = (choose[j - 1] + choose[j]) * 0.5;
                    choose.swap(next);
                }
                ans = accumulate(choose.begin() + Y + 1, choose.end(), 0.0);
            }
        }
        cout << "Case #" << cas + 1 << ": " << ans << "\n";
    }
    return 0;
}
