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
    int delta;
    string delta_str;

    edge() {}
    edge(int t, int d, const string &ds) : trg(t), delta(d), delta_str(ds) {}
};

static vector<vector<edge> > edges;

static inline bool compare(const string &a, const string &b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    else return a < b;
}

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, 1, 0, -1};

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        printf("Case #%d:\n", cas + 1);

        int W, Q;
        char grid[30][30];
        int ids[30][30];
        int values[400];
        int V = 0;

        cin >> W >> Q;
        for (int i = 0; i < W; i++)
            cin >> grid[i];

        for (int i = 0; i < W; i++)
            for (int j = 0; j < W; j++)
                if (grid[i][j] >= '0' && grid[i][j] <= '9')
                {
                    values[V] = grid[i][j] - '0';
                    ids[i][j] = V++;
                }

        edges.clear();
        edges.resize(V);
        for (int i = 0; i < W; i++)
            for (int j = 0; j < W; j++)
                if (grid[i][j] >= '0' && grid[i][j] <= '9')
                {
                    for (int d1 = 0; d1 < 4; d1++)
                    {
                        int i1 = i + dr[d1];
                        int j1 = j + dc[d1];
                        if (i1 < 0 || i1 >= W || j1 < 0 || j1 >= W)
                            continue;
                        for (int d2 = 0; d2 < 4; d2++)
                        {
                            int i2 = i1 + dr[d2];
                            int j2 = j1 + dc[d2];
                            if (i2 < 0 || i2 >= W || j2 <0 || j2 >= W)
                                continue;

                            int trg = ids[i2][j2];
                            int delta = grid[i2][j2] - '0';
                            string delta_str = "+";
                            delta_str += grid[i2][j2];
                            if (grid[i1][j1] == '-')
                            {
                                delta = -delta;
                                delta_str[0] = '-';
                            }

                            edges[ids[i][j]].push_back(edge(trg, delta, delta_str));
                        }
                    }
                }

        map<pii, string> seen;
        vector<pii> q;
        map<int, string> best;
        for (int i = 0; i < V; i++)
        {
            seen[pii(i, values[i])] = string(1, '0' + values[i]);
            q.push_back(pii(i, values[i]));
        }
        for (int i = 0; i < Q; i++)
        {
            int test;
            cin >> test;
            while (!best.count(test))
            {
                vector<pii> q2;
                for (size_t j = 0; j < q.size(); j++)
                {
                    int cur = q[j].first;
                    int sum = q[j].second;
                    const string &e = seen[q[j]];
                    if (!best.count(sum) || compare(e, best[sum]))
                        best[sum] = e;
                    for (int k = 0; k < SZ(edges[cur]); k++)
                    {
                        pii next(edges[cur][k].trg, sum + edges[cur][k].delta);
                        string repr = e + edges[cur][k].delta_str;
                        if (!seen.count(next))
                            q2.push_back(next);
                        if (!seen.count(next) || compare(repr, seen[next]))
                            seen[next] = repr;
                    }
                }
                q2.swap(q);
            }
            cout << best[test] << "\n";
        }
    }
    return 0;
}
