#include <fstream>
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

struct edge
{
    int trg;
    int cap;
    int flow;
    int dual;

    edge(int t, int c, int f, int d) : trg(t), cap(c), flow(f), dual(d) {}
};

static int dr[4] = {-1, 0, 1, 0};
static int dc[4] = {0, -1, 0, 1};

static vector<vector<edge> > edges;

static void add_edge(int src, int trg, int cap)
{
    if (cap <= 0) return;
    int id1 = edges[src].size();
    int id2 = edges[trg].size();
    edges[src].push_back(edge(trg, cap, 0, id2));
    edges[trg].push_back(edge(src, 0, 0, id1));
}

static bool augment()
{
    int V = edges.size();
    vi prev(V, -1);
    vector<bool> seen(V, false);

    queue<int> q;
    q.push(V - 2);
    seen[V - 2] = true;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        if (c == V - 1)
        {
            while (c != V - 2)
            {
                int e = prev[c];
                edges[c][e].flow--;
                int dual = edges[c][e].dual;
                c = edges[c][e].trg;
                edges[c][dual].flow++;
            }
            return true;
        }

        for (int i = 0; i < SZ(edges[c]); i++)
        {
            int n = edges[c][i].trg;
            if (edges[c][i].flow < edges[c][i].cap && !seen[n])
            {
                prev[n] = edges[c][i].dual;
                seen[n] = true;
                q.push(n);
            }
        }
    }
    return false;
}

int main()
{
    // ifstream myin("e.in");
    istream &in = cin;
    int cases;
    in >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        edges.clear();

        int total = 0;
        int R, C;
        in >> R >> C;
        vs grid(R);
        vector<vi> ids(R);
        int VS[2] = {0, 0};

        for (int i = 0; i < R; i++)
        {
            in >> grid[i];
            ids[i].resize(C, -1);
            for (int j = 0; j < C; j++)
            {
                int s = (i ^ j) & 1;
                if (grid[i][j] == '?')
                    ids[i][j] = VS[s]++;
                else if (grid[i][j] == '#')
                    total += 2;
            }
        }

        vi values[2];
        values[0].resize(VS[0], 2);
        values[1].resize(VS[1], 2);
        int V = VS[0] + VS[1] + 2;
        edges.resize(V);
        for (int i = 0; i < R; i++)
            for (int j = i & 1; j < C; j += 2)
                for (int d = 0; d < 4; d++)
                {
                    int i2 = i + dr[d];
                    int j2 = j + dc[d];
                    if (i2 >= 0 && i2 < R && j2 >= 0 && j2 < C)
                    {
                        if (grid[i][j] == '.' || grid[i2][j2] == '.')
                            continue;
                        if (grid[i][j] == '#' && grid[i2][j2] == '#')
                            total -= 1;
                        else if (grid[i][j] == '#' && grid[i2][j2] == '?')
                            values[1][ids[i2][j2]] -= 1;
                        else if (grid[i][j] == '?' && grid[i2][j2] == '#')
                            values[0][ids[i][j]] -= 1;
                        else
                            add_edge(ids[i][j], ids[i2][j2] + VS[0], 1);
                    }
                }
        for (int i = 0; i < VS[0]; i++)
        {
            values[0][i] = max(values[0][i], 0);
            add_edge(V - 2, i, values[0][i]);
            total += values[0][i];
        }
        for (int i = 0; i < VS[1]; i++)
        {
            values[1][i] = max(values[1][i], 0);
            add_edge(i + VS[0], V - 1, values[1][i]);
            total += values[1][i];
        }

        while (augment()) total--;

        printf("Case #%d: %d\n", cas + 1, total * 2);
    }
    return 0;
}
