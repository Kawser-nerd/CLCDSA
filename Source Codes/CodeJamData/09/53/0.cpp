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

#define MAX_ROWS 32

static int N;
static vector<pii> rows[MAX_ROWS];
static int R;

static vector<vi> edges;

static int next_in_row(int r, int low_x)
{
    int p = 0;
    while (p < SZ(rows[r]) && rows[r][p].first <= low_x)
        p++;
    if (p >= SZ(rows[r]))
        return -1;
    else
        return rows[r][p].second;
}

static void make_edges()
{
    for (int i = 1; i < R; i++)
        for (int x = 0; x < SZ(rows[i]); x++)
            for (int j = i - 1; j <= i + 1; j++)
            {
                int nxt = next_in_row(j, rows[i][x].first);
                if (nxt != -1)
                {
                    assert(nxt >= 0 && nxt < N);
                    edges[rows[i][x].second].push_back(nxt);
                    edges[nxt].push_back(rows[i][x].second);
                }
            }
}

static int colour()
{
    int ans = 0;
    vi mask(N, 0);
    vi color(N, -1);
    int todo = N;

    while (todo > 0)
    {
        for (int i = 0; i < R; i++)
            rows[i].clear();

        int best = -1;
        int best_cover = -1;
        for (int i = 0; i < N; i++)
        {
            int cover = __builtin_popcount(mask[i]);
            if (cover > best_cover && color[i] == -1)
            {
                best_cover = cover;
                best = i;
            }
        }

        int c = __builtin_ctz(~(unsigned int)mask[best]);
        ans = max(ans, c + 1);
        color[best] = c;
        for (int i = 0; i < SZ(edges[best]); i++)
            mask[edges[best][i]] |= 1 << c;
        todo--;
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        edges.clear();

        R = 31;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int x, y;
            cin >> x >> y;
            rows[y].push_back(pii(x, i));
        }
        for (int i = 1; i < R; i++)
            sort(RA(rows[i]));

        edges.resize(N);
        make_edges();

        int ans = min(colour(), 4);
        printf("Case #%d: %d\n", cas + 1, ans);
    }
    return 0;
}
