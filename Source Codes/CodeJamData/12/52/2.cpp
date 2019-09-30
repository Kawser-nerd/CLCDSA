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

static const int dx[6] = {1, 1, 0, -1, -1, 0};
static const int dy[6] = {0, 1, 1, 0, -1, -1};

struct board
{
    int S;

    vector<pii> coords;
    vector<vector<int> > rcoords;

    int classify(pii c);
    void add_cell(int x, int y);
    vector<int> get_edges(int id);
};

int board::classify(pii c)
{
    int x = c.first;
    int y = c.second;

    if (x == 1 && y == 1)
        return 0;
    else if (x == 1 && y == S)
        return 1;
    else if (x == S && y == 2 * S - 1)
        return 2;
    else if (x == 2 * S - 1 && y == 2 * S - 1)
        return 3;
    else if (x == 2 * S - 1 && y == S)
        return 4;
    else if (x == S && y == 1)
        return 5;

    else if (x == 1)
        return 6;
    else if (y - x == S - 1)
        return 7;
    else if (y == 2 * S - 1)
        return 8;
    else if (x == 2 * S - 1)
        return 9;
    else if (x - y == S - 1)
        return 10;
    else if (y == 1)
        return 11;

    else
        return 12;
}

void board::add_cell(int x, int y)
{
    pii c(x, y);
    if (rcoords[x][y] >= 0)
        return;
    int id = coords.size();
    rcoords[x][y] = id;
    coords.push_back(c);
}

vector<int> board::get_edges(int id)
{
    vector<int> ans;
    ans.reserve(6);
    pii c = coords[id];
    for (int d = 0; d < 6; d++)
    {
        pii n(c.first + dx[d], c.second + dy[d]);
        if (rcoords[n.first][n.second] >= 0)
            ans.push_back(rcoords[n.first][n.second]);
    }
    return ans;
}

static int find(vector<int> &parent, int x)
{
    int y = x;
    while (parent[y] >= 0)
        y = parent[y];
    while (parent[x] >= 0)
    {
        int n = parent[x];
        parent[x] = y;
        x = n;
    }
    return y;
}

static bool merge(vector<int> &parent, vector<int> &klass, int x, int y)
{
    x = find(parent, x);
    y = find(parent, y);
    if (x == y)
        return false;
    if (-parent[x] > -parent[y])
        swap(x, y);
    parent[y] += parent[x];
    parent[x] = y;
    klass[y] |= klass[x];
    return true;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;

    const int corner_classes = (1 << 6) - 1;
    const int edge_classes = (1 << 12) - (1 << 6);
    const int out_classes = (1 << 12) - 1;
    for (int cas = 0; cas < cases; cas++)
    {
        int S;
        int M;
        cin >> S >> M;
        vector<pii> moves(M);
        for (int i = 0; i < M; i++)
            cin >> moves[i].first >> moves[i].second;

        board b;
        b.S = S;
        b.rcoords.resize(2 * S + 1, vi(2 * S + 1, -1));
        for (int i = 1; i <= S; i++)
            for (int j = 1; j <= S; j++)
            {
                b.add_cell(i, j);
                b.add_cell(i + j - 1, j + S - 1);
                b.add_cell(i + S - 1, i + j - 1);
            }

        int first_bridge = INT_MAX;
        int first_fork = INT_MAX;
        int first_ring = INT_MAX;

        int V = b.coords.size();
        vi parent(V, -1);
        vi klass(V);
        vector<bool> used(V);

        for (int i = 0; i < V; i++)
            klass[i] = 1 << b.classify(b.coords[i]);

        for (int i = 0; i < M; i++)
        {
            pii c = moves[i];
            int id = b.rcoords[c.first][c.second];
            used[id] = true;

            vector<int> neigh = b.get_edges(id);
            for (int j = 0; j < SZ(neigh); j++)
                if (used[neigh[j]])
                    merge(parent, klass, id, neigh[j]);

            int r = find(parent, id);
            if (first_bridge == INT_MAX)
            {
                if (__builtin_popcount(klass[r] & corner_classes) >= 2)
                    first_bridge = i + 1;
            }
            if (first_fork == INT_MAX)
            {
                if (__builtin_popcount(klass[r] & edge_classes) >= 3)
                    first_fork = i + 1;
            }
        }

        fill(RA(parent), -1);
        for (int i = 0; i < V; i++)
            klass[i] = 1 << b.classify(b.coords[i]);
        for (int id = 0; id < V; id++)
        {
            if (used[id])
                continue;

            vector<int> neigh = b.get_edges(id);
            for (int j = 0; j < SZ(neigh); j++)
                if (!used[neigh[j]])
                    merge(parent, klass, id, neigh[j]);
        }

        for (int i = M - 1; i >= 0; i--)
        {
            pii c = moves[i];
            int id = b.rcoords[c.first][c.second];
            used[id] = false;

            vector<int> neigh = b.get_edges(id);
            bool have_out = false;
            bool have_in = false;
            for (int j = 0; j < SZ(neigh); j++)
                if (!used[neigh[j]])
                {
                    int x = find(parent, neigh[j]);
                    if (klass[x] & out_classes)
                        have_out = true;
                    else
                        have_in = true;
                }
            if (klass[id] & out_classes)
                have_out = true;

            for (int j = 0; j < SZ(neigh); j++)
                if (!used[neigh[j]])
                    merge(parent, klass, id, neigh[j]);

            if (have_out && have_in)
                first_ring = i + 1;

        }

        const string names[3] = {"bridge", "fork", "ring"};
        const int firsts[3] = {first_bridge, first_fork, first_ring};
        int F = *min_element(firsts, firsts + 3);
        if (F == INT_MAX) F--;
        bool have = false;

        printf("Case #%d: ", cas + 1);
        for (int i = 0; i < 3; i++)
        {
            if (firsts[i] == F)
            {
                if (!have)
                    have = true;
                else
                    cout << '-';
                cout << names[i];
            }
        }
        if (!have)
            cout << "none";
        else
            cout << " in move " << F;
        cout << '\n';
    }
    return 0;
}
