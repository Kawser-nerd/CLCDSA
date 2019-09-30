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

static inline ll get_moment(const vector<vll> &accum, const vector<vi> &grid, int r1, int c1, int r2, int c2)
{
    ll ans = accum[r2][c2] - accum[r1][c2] - accum[r2][c1] + accum[r1][c1];
    ans -= grid[r1][c1] + grid[r1][c2 - 1] + grid[r2 - 1][c1] + grid[r2 - 1][c2 - 1];
    return ans;
}

int main(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int R, C, D;
        cin >> R >> C >> D;
        vector<vi> gridv(R, vi(C));
        vector<vi> gridh(R, vi(C));
        vector<vi> gridd(R, vi(C));
        vector<vll> accumv(R + 1, vll(C + 1));
        vector<vll> accumh(R + 1, vll(C + 1));
        vector<vll> accumd(R + 1, vll(C + 1));
        for (int i = 1; i <= R; i++)
        {
            string line;
            cin >> line;
            for (int j = 1; j <= C; j++)
            {
                int w = line[j - 1] - '0';
                ll mv = w * (i - 1);
                ll mh = w * (j - 1);
                gridv[i - 1][j - 1] = mv;
                gridh[i - 1][j - 1] = mh;
                gridd[i - 1][j - 1] = w;
                accumv[i][j] = accumv[i - 1][j] + accumv[i][j - 1] - accumv[i - 1][j - 1] + mv;
                accumh[i][j] = accumh[i - 1][j] + accumh[i][j - 1] - accumh[i - 1][j - 1] + mh;
                accumd[i][j] = accumd[i - 1][j] + accumd[i][j - 1] - accumd[i - 1][j - 1] + w;
            }
        }

        int ans = 2;
        for (int K = min(R, C); K >= 3 && ans == 2; K--)
        {
            ll elements = K * K - 4;
            ll mbase = 0;
            for (int i = 0; i < K; i++)
            {
                ll pop = K;
                if (i == 0 || i == K - 1)
                    pop -= 2;
                mbase += pop * i;
            }
            for (int i = 0; i + K <= R; i++)
                for (int j = 0; j + K <= C; j++)
                {
                    ll mv = get_moment(accumv, gridv, i, j, i + K, j + K);
                    ll mh = get_moment(accumh, gridh, i, j, i + K, j + K);
                    ll w = get_moment(accumd, gridd, i, j, i + K, j + K);
                    ll exp_mv = mbase + elements * i;
                    ll exp_mh = mbase + elements * j;
                    if (mv * elements == exp_mv * w
                        && mh * elements == exp_mh * w)
                    {
                        ans = K;
                        goto found;
                    }
                }
        }
found:
        printf("Case #%d: ", cas + 1);
        if (ans < 3)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
