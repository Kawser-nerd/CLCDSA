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

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, -1, 0, 1};

struct qitem
{
    int trg;
    int prio;

    bool operator <(const qitem &b) const { return prio > b.prio; }
    qitem(int t, int p) : trg(t), prio(p) {}
};

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N, M;
        cin >> N >> M;
        vs grid(N);
        vector<vi> ids(N);
        vector<vi> edges;
        vi isf;
        int V = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> grid[i];
            ids[i].resize(M, -1);
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] != '.')
                {
                    ids[i][j] = V++;
                    edges.push_back(vi());
                    isf.push_back(grid[i][j] == 'T' ? 1 : 0);
                }
            }
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == '.') continue;
                for (int d = 0; d < 4; d++)
                {
                    int i2 = i + dr[d];
                    int j2 = j + dc[d];
                    if (i2 < 0 || i2 >= N || j2 < 0 || j2 >= M) continue;
                    if (grid[i2][j2] == '.') continue;
                    edges[ids[i][j]].push_back(ids[i2][j2]);
                }
            }

        vector<int> have(V, 0);
        vector<int> parent(V, -1);
        have[0] = true;
        int total = 0;
        int todo = V - 1;
        while (todo)
        {
            int target = -1;
            priority_queue<qitem> q;
            vector<int> prio(V, INT_MAX);
            for (int i = 0; i < V; i++)
                if (have[i] && isf[i])
                {
                    prio[i] = 0;
                    q.push(qitem(i, 0));
                    parent[i] = -2;
                }
            while (!q.empty())
            {
                int cur = q.top().trg;
                int p = q.top().prio;
                q.pop();
                if (p != prio[cur]) continue;
                if (isf[cur] && !have[cur])
                {
                    target = cur;
                    break;
                }
                p++;
                for (int i = 0; i < SZ(edges[cur]); i++)
                {
                    int nxt = edges[cur][i];
                    if (p < prio[nxt])
                    {
                        prio[nxt] = p;
                        q.push(qitem(nxt, p));
                        parent[nxt] = cur;
                    }
                }
            }

            int first = target == -1 ? 0 : target;
            int last = target == -1 ? V - 1 : target;

            for (int i = first; i <= last; i++)
            {
                target = i;
                while (!have[target])
                {
                    total += prio[target];
                    have[target] = true;
                    todo--;
                    target = parent[target];
                }
            }
        }


        printf("Case #%d: %d\n", cas + 1, total);
    }
    return 0;
}
