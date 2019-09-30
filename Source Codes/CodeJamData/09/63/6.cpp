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
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;
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

#define MOD 10007

struct hash_ll
{
    size_t operator()(ll x) const
    {
        return x % 1000000007;
    }
};

#define HSIZE 200000007

static int R, C;
static char grid[11][12];
static char upper[11][12];
static unsigned int cache[HSIZE][2];

static int recurse(ull key, int empty, int *used, char first, int c)
{
    if (c == C)
    {
        key += 15 - c;
        first++;
        c = 0;
    }
    if (first > 'z')
    {
        return empty == 0 ? 1 : 0;
    }

    unsigned int kmod = key % HSIZE;
    if (cache[kmod][0] == (key >> 20))
        return cache[kmod][1];

    int ans = recurse(key + 1, empty, used, first, c + 1);
    if (used[c] < R
        && (c == 0 || used[c] < used[c - 1])
        && first <= upper[used[c]][c]
        && (grid[used[c]][c] == '.' || grid[used[c]][c] == first))
    {
        used[c]++;
        ans += recurse(key + (512LL << (4 * c)), empty - 1, used, first, c);
        if (ans >= MOD) ans -= MOD;
        used[c]--;
    }
    cache[kmod][0] = key >> 20;
    cache[kmod][1] = ans;
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        cin >> R >> C;
        for (int i = 0; i < R; i++)
            cin >> grid[i];
        memset(cache, -1, sizeof(cache));

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                upper[i][j] = 'z';
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (grid[i][j] != '.')
                {
                    for (int i2 = 0; i2 <= i; i2++)
                        for (int j2 = 0; j2 <= j; j2++)
                            upper[i2][j2] = min(upper[i2][j2], grid[i][j]);
                }

        int used[12] = {};
        int ans = recurse(0, R * C, used, 'a', 0);
        printf("Case #%d: %d\n", cas + 1, ans);
    }
    return 0;
}
