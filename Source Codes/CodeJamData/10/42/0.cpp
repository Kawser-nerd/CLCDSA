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

static int P;
static int costs[12][512];
static int miss[1024];
static map<pair<pii, int>, int> cache;

static int recurse(int A, int B, int lvl, int missed)
{
    pair<pii, int> key(pii(A, B), missed);
    if (cache.count(key)) return cache[key];
    int &ans = cache[key];

    if (B - A == 1)
    {
        if (missed > miss[A]) return ans = INT_MAX;
        else return ans = 0;
    }
    else
    {
        int M = (A + B) / 2;
        ans = INT_MAX;
        int opt1a = recurse(A, M, lvl - 1, missed + 1);
        int opt1b = recurse(M, B, lvl - 1, missed + 1);
        int opt2a = recurse(A, M, lvl - 1, missed);
        int opt2b = recurse(M, B, lvl - 1, missed);

        if (opt1a != INT_MAX && opt1b != INT_MAX)
            ans = opt1a + opt1b;
        if (opt2a != INT_MAX && opt2b != INT_MAX)
        {
            int test = opt2a + opt2b + costs[lvl][A >> lvl];
            if (test < ans) ans = test;
        }
        return ans;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        cache.clear();
        cin >> P;
        for (int i = 0; i < (1 << P); i++)
            cin >> miss[i];
        for (int l = 1; l <= P; l++)
            for (int j = 0; j < (1 << (P - l)); j++)
                cin >> costs[l][j];
        printf("Case #%d: %d\n", cas + 1, recurse(0, 1 << P, P, 0));
    }
    return 0;
}
