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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
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

static void recurse(ll *X, ll F, int M, int dangle, int unused, ll base, vll &out)
{
    int f = __builtin_ctz(dangle);
    int mf = 1 << f;

    if (dangle == 0)
    {
        if (unused == 0)
            out.push_back(base);
        return;
    }

    for (int p = f + 1; p < M; p++)
    {
        int mp = 1 << p;
        if (dangle & mp)
        {
            vll t;
            recurse(X, F, M, dangle ^ mp ^ mf, unused, base + X[p] - X[f], t);
            out.insert(out.end(), RA(t));
        }
        else if (unused & mp)
        {
            vll t;
            recurse(X, F, M, dangle ^ mp ^ mf, unused ^ mp, base + X[p] - X[f], t);
            out.insert(out.end(), RA(t));
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N;
        ll F;
        ll X[31];
        ll best = -1;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> X[i];
        cin >> F;

        sort(X + 1, X + N);
        X[N] = X[0];
        do
        {
            ll cost = 0;
            for (int i = 0; i < N; i++)
                cost = cost + llabs(X[i + 1] - X[i]);
            if (cost <= F)
                best = max(best, cost);
        } while (next_permutation(X + 1, X + N));


        if (best == -1)
        {
            printf("Case #%d: NO SOLUTION\n", cas + 1);
        }
        else
        {
            printf("Case #%d: %lld\n", cas + 1, best);
        }
    }
    return 0;
}
