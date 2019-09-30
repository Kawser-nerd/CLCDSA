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

static int H;
static vector<vector<int> > F, C;

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, -1, 0, 1};

static int enter_time(int r1, int c1, int r2, int c2)
{
    if (min(C[r1][c1], C[r2][c2]) - max(F[r1][c1], F[r2][c2]) < 50)
        return INT_MAX;
    int th = (C[r2][c2] - 50);
    if (H <= th)
        return INT_MIN;
    else
        return H - th;
}

struct pqitem
{
    int r;
    int c;
    int prio;

    pqitem() {}
    pqitem(int r, int c, int prio) : r(r), c(c), prio(prio) {}

    bool operator<(const pqitem &b) const
    {
        return prio > b.prio;
    }
};

int dijkstra(int r0, int c0, int t0)
{
    int rows = SZ(F);
    int cols = SZ(F[0]);
    vector<vi> prio(rows, vi(cols, INT_MAX));

    prio[0][0] = t0;
    priority_queue<pqitem> q;
    q.push(pqitem(r0, c0, t0));
    while (!q.empty())
    {
        pqitem cur = q.top();
        q.pop();
        if (cur.prio != prio[cur.r][cur.c])
            continue;

        for (int d = 0; d < 4; d++)
        {
            int r2 = cur.r + dr[d];
            int c2 = cur.c + dc[d];
            if (r2 >= 0 && r2 < rows && c2 >= 0 && c2 < cols)
            {
                int t = enter_time(cur.r, cur.c, r2, c2);
                if (t != INT_MAX)
                {
                    if (t < cur.prio)
                        t = cur.prio;
                    if (H - t >= F[cur.r][cur.c] + 20)
                        t += 10;
                    else
                        t += 100;
                    if (t < prio[r2][c2])
                    {
                        prio[r2][c2] = t;
                        q.push(pqitem(r2, c2, t));
                    }
                }
            }
        }
    }
    return prio.back().back();
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        F.clear(); C.clear();
        int rows, cols;
        cin >> H >> rows >> cols;
        F.resize(rows, vi(cols));
        C = F;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> C[i][j];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> F[i][j];

        int ans = dijkstra(0, 0, INT_MIN + 1);
        if (ans < 0) ans = 0;

        printf("Case #%d: %.1f\n", cas + 1, ans * 0.1);
    }
    return 0;
}
