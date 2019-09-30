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

static inline int sqr(int x)
{
    return x * x;
}

static int dist2(int x1, int y1, int x2, int y2)
{
    return sqr(x2 - x1) + sqr(y2 - y1);
}

struct tower
{
    int x, y;
    int r2, s;

    tower(int X, int Y, int R, int S) : x(X), y(Y), r2(R * R), s(S) {}
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int T;
        cin >> T;
        vector<tower> towers;
        vector<vector<int> > edges(T);
        for (int i = 0; i < T; i++)
        {
            int x, y, r, s;
            cin >> x >> y >> r >> s;
            towers.push_back(tower(x, y, r, s));
        }

        for (int i = 0; i < T; i++)
            for (int j = 0; j < T; j++)
                if (i != j && dist2(towers[i].x, towers[i].y, towers[j].x, towers[j].y) <= towers[i].r2)
                    edges[i].push_back(j);

        int best = 0;
        for (int bm = 1; bm < (1 << T); bm++)
        {
            int score = 0;
            for (int i = 0; i < T; i++)
                if ((bm >> i) & 1)
                {
                    score += towers[i].s;
                    for (int j = 0; j < SZ(edges[i]); j++)
                    {
                        int y = edges[i][j];
                        if (!((bm >> y) & 1))
                            goto bad;
                    }
                }
            best = max(best, score);
bad:;
        }

        printf("Case #%d: %d\n", cas + 1, best);
    }
    return 0;
}
