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
#include <ext/hash_map>
#include <fcntl.h>
#include <unistd.h>

using namespace std;
using namespace __gnu_cxx;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int8_t, int8_t> pos;

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

static int N;
static int R, C;
static char grid[13][14];

struct state
{
    pos xy[5];
    int8_t d;

    bool operator ==(const state &b) const
    {
        return memcmp(this, &b, sizeof(b)) == 0;
    }
};

struct hash_state
{
    size_t operator()(const state &s) const
    {
        size_t v = 0;
        size_t v2 = 0;
        const char *chs = (const char *) &s;
        memcpy(&v, chs, sizeof(v));
        memcpy(&v2, chs + sizeof(v), sizeof(s) - sizeof(v));
        return v + 37 * v2;
    }
};

struct pqitem
{
    state s;
    int prio;

    bool operator <(const pqitem &q) const
    {
        return prio > q.prio;
    }
    pqitem() {}
    pqitem(const state &s, int prio) : s(s), prio(prio) {}
};

static void canon(state &s)
{
    sort(s.xy, s.xy + N);
}

static inline bool safe(const state &s, int r, int c)
{
    if (r >= 0 && r < R && c >= 0 && c < C && grid[r][c] != '#')
    {
        for (int i = 0; i < N; i++)
            if (r == s.xy[i].first && c == s.xy[i].second)
                return false;
        return true;
    }
    else
        return false;
}

static int danger(state &s)
{
    int parent[5] = {-1, -1, -1, -1, -1};
    int comps = N;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            int d = abs(s.xy[i].first - s.xy[j].first) + abs(s.xy[i].second - s.xy[j].second);
            if (d == 0) return s.d = 2;
            if (d == 1 && comps > 1)
            {
                int p = i;
                while (parent[p] > 0) p = parent[p];
                int q = j;
                while (parent[q] > 0) q = parent[q];
                if (p != q)
                {
                    parent[q] = p;
                    comps--;
                }
            }
        }
    if (comps == 1) s.d = 0;
    else s.d = 1;

    return s.d;
}

static void dump(const state &s)
{
    for (int i = 0; i < N; i++)
        cerr << (int) s.xy[i].first << "," << (int) s.xy[i].second << " ";
    cerr << "\n";
}

static state src, trg;

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, -1, 0, 1};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        cin >> R >> C;
        memset(&src, 0, sizeof(src));
        memset(&trg, 0, sizeof(trg));
        int iS = 0, iT = 0;
        for (int i = 0; i < R; i++)
        {
            cin >> grid[i];
            for (int j = 0; j < C; j++)
            {
                switch (grid[i][j])
                {
                case 'x':
                    grid[i][j] = '.';
                    trg.xy[iT++] = pos(i, j);
                    break;
                case 'o':
                    grid[i][j] = '.';
                    src.xy[iS++] = pos(i, j);
                    break;
                case 'w':
                    grid[i][j] = '.';
                    src.xy[iS++] = pos(i, j);
                    trg.xy[iT++] = pos(i, j);
                    break;
                }
            }
        }
        assert(iS == iT);
        assert(iS <= 5);
        N = iS;

        queue<state> q;
        hash_map<state, int, hash_state> prio;
        hash_map<state, state, hash_state> prev;
        q.push(src);
        prio[src] = 0;
        while (!q.empty() && !prio.count(trg))
        {
            state s = q.front();
            int p = prio[s];
            q.pop();

            for (int i = 0; i < N; i++)
                for (int dir = 0; dir < 4; dir++)
                {
                    if (safe(s, s.xy[i].first + dr[dir], s.xy[i].second + dc[dir])
                        && safe(s, s.xy[i].first - dr[dir], s.xy[i].second - dc[dir]))
                    {
                        state nxt = s;
                        nxt.xy[i].first += dr[dir];
                        nxt.xy[i].second += dc[dir];

                        canon(nxt);
                        if (danger(nxt) + s.d <= 1 && !prio.count(nxt))
                        {
                            prio[nxt] = p + 1;
                            q.push(nxt);
                            prev[nxt] = s;
                            //dump(nxt);
                        }
                    }
                }
        }
        if (!prio.count(trg))
            prio[trg] = -1;
        else
        {
#if 0
            state s = trg;
            while (!(s == src))
            {
                dump(s);
                s = prev[s];
            }
            dump(s);
#endif
        }

        printf("Case #%d: %d\n", cas + 1, prio[trg]);
    }
    return 0;
}
