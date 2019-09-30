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

static void dijkstra(const vector<vi> &edges, int start, vector<int> &dists)
{
    int P = SZ(edges);
    queue<int> q;
    q.push(start);
    dists.resize(P);
    fill(RA(dists), -1);
    dists[start] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        FE(e, edges[cur])
        {
            if (dists[*e] == -1)
            {
                dists[*e] = dists[cur] + 1;
                q.push(*e);
            }
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int P, W;
        cin >> P >> W;

        vector<vi> edges(P);
        vector<vector<bool> > edge_table(P, vector<bool>(P));
        for (int i = 0; i < W; i++)
        {
            int a, b;
            scanf(" %d,%d", &a, &b);
            edges[a].push_back(b);
            edges[b].push_back(a);
            edge_table[a][b] = true;
            edge_table[b][a] = true;
        }
        for (int i = 0; i < P; i++)
            sort(RA(edges[i]));

        vi src_dist(P);
        vi dst_dist(P);
        dijkstra(edges, 0, src_dist);
        dijkstra(edges, 1, dst_dist);
        int tdist = src_dist[1];

        vector<vi> forw(P);
        vector<bool> good(P);
        for (int i = 0; i < P; i++)
            good[i] = src_dist[i] + dst_dist[i] == tdist;
        for (int i = 0; i < P; i++)
        {
            FE(e, edges[i])
                if (good[*e] && src_dist[*e] == src_dist[i] + 1)
                    forw[i].push_back(*e);
        }
        assert(good[0]);
        assert(good[1]);
        map<pii, int> dp;

        FE(e, edges[1])
        {
            if (good[*e])
            {
                assert(src_dist[*e] == tdist - 1);
                dp[pii(*e, 1)] = SZ(edges[*e]);
                // printf("%d %d %d\n", *e, 1, SZ(edges[*e]));
            }
        }
        int ans = -1;
        for (int sdist = tdist - 2; sdist >= 0; sdist--)
        {
            for (int p = 0; p < P; p++)
                if (good[p] && src_dist[p] == sdist)
                {
                    FE(qi, forw[p])
                    {
                        int q = *qi;
                        int best = -1;
                        FE(ri, forw[q])
                        {
                            int r = *ri;
                            assert(dp.count(pii(q, r)));
                            int th = dp[pii(q, r)] - 1;
                            FE(ei, edges[p])
                            {
                                int e = *ei;
                                assert(e != r);
                                if (e != q && !edge_table[q][e]
                                    && (r == 1 || !edge_table[r][e]))
                                    th++;
                            }
                            if (th > best)
                                best = th;
                        }
                        assert(best != -1);
                        dp[pii(p, q)] = best;
                        // printf("%d %d %d\n", p, q, best);
                    }
                }
        }
        FE(d, dp)
            if (d->first.first == 0)
                ans = max(ans, d->second);
        printf("Case #%d: %d %d\n", cas + 1, tdist - 1, ans);
    }
    return 0;
}
