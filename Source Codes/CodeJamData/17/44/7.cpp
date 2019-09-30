#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }

// ========================================================================= //

namespace flow
{
    typedef unsigned int uint;
    typedef unsigned long long ull;

    int const INF = 100 + (int) 1e9;
    ll const INFL = 100 + (ll) 1e18;
    int const N = 3333;

    struct edge_t {
        int to, cap, flow, cost;
        
        edge_t() {}
        
        edge_t(int to, int cap, int cost) :
            to(to), cap(cap), flow(0), cost(cost) {}
    };

    vector<edge_t> edges;
    vector<int> g[N];

    void clear_flow() {
        for (auto& e : edges) {
            e.flow = 0;
        }
    }

    void clear_graph() {
        edges.clear();
        for (int i = 0; i < N; ++i) {
            g[i].clear();
        }
    }

    int add_edge(int v, int to, int cap, int cost) {
        int ret;
        g[v].push_back(ret = edges.size());
        edges.emplace_back(to, cap, cost);
        g[to].push_back(edges.size());
        edges.emplace_back(v, 0, -cost);
        return ret;
    }

    pair<ll, ll> min_cost_flow(int source, int sink, int n, ll need_flow) {
        ll cost = 0;
        ll flow = 0;
        while (flow < need_flow) {
            static int q[N], in_q[N], dist[N], prev[N];
            int tail = 0;
            q[tail++] = source;
            fill(dist, dist + n, INF);
            dist[source] = 0;
            in_q[source] = true;
            for (int head = 0; head != tail;) {
                int v = q[head];
                ++head;
                if (head == N)
                    head = 0;
                in_q[v] = false;
                for (int x : g[v]) {
                    edge_t const& e = edges[x];
                    int to = e.to;
                    if (e.flow < e.cap && dist[to] > dist[v] + e.cost) {
                        dist[to] = dist[v] + e.cost;
                        prev[to] = x;
                        if (!in_q[to]) {
                            q[tail++] = to;
                            if (tail == N)
                                tail = 0;
                            in_q[to] = true;
                        }
                    }
                }
            }
            if (dist[sink] == INF) {
                break;
            }
            ll cur_flow = need_flow - flow;
            for (int v = sink; v != source;) {
                int x = prev[v];
                cur_flow = min<ll>(cur_flow, edges[x].cap - edges[x].flow);
                v = edges[x ^ 1].to;
            }
            flow += cur_flow;
            cost += (ll) cur_flow * dist[sink];
            for (int v = sink; v != source;) {
                int x = prev[v];
                edges[x].flow += cur_flow;
                edges[x ^ 1].flow -= cur_flow;
                v = edges[x ^ 1].to;
            }
        }
        return {cost, flow};
    }

    pair<ll, ll> min_cost_max_flow(int source, int sink, int n) {
        return min_cost_flow(source, sink, n, INFL);
    }
}

const int N = 111;

vector < int > topsort;
vector < bool > vis;
void dfs44(int v, vector<vector<int>> const & e)
{
    if (vis[v])
        return;
    vis[v] = 1;
    for (int nv : e[v])
        dfs44(nv, e);
    topsort.push_back(v);
}

void solve()
{
    flow::clear_graph();
    int sx, sy, m;
    cin >> sy >> sx >> m;
    vector < string > f(sx);
    for (int i = 0; i < sx; ++i)
        cin >> f[i];
    vector < vector < vector < int > > > p2ts(sx, vector<vector<int>>(sy));
    vector < ipair > sc;
    int ti = 0;
    for (int x = 0; x < sx; ++x)
        for (int y = 0; y < sy; ++y)
            if (f[x][y] == 'T')
            {
                for (int nx = x + 1; nx < sx && f[nx][y] != '#'; ++nx)
                    p2ts[nx][y].push_back(ti);
                for (int nx = x - 1; nx >= 0 && f[nx][y] != '#'; --nx)
                    p2ts[nx][y].push_back(ti);
                for (int ny = y + 1; ny < sy && f[x][ny] != '#'; ++ny)
                    p2ts[x][ny].push_back(ti);
                for (int ny = y - 1; ny >= 0 && f[x][ny] != '#'; --ny)
                    p2ts[x][ny].push_back(ti);
                ++ti;
            }
    int si = 0;
    int source = 0, sink = 1, startt = 2, starts = 2 + ti;
    for (int x = 0; x < sx; ++x)
        for (int y = 0; y < sy; ++y)
            if (f[x][y] == 'S')
            {
                sc.emplace_back(x, y);
                vector < vector < int > > d(sx, vector<int>(sy, IINF));
                vector < ipair > q;
                d[x][y] = 0;
                q.emplace_back(x, y);
                vector < bool > was(ti, false);
                for (int i = 0; i < sz(q); ++i)
                {
                    int cx = q[i].X, cy = q[i].Y;
                    int dist = d[cx][cy];
                    if (dist > m)
                        break;
                    for (int t : p2ts[cx][cy])
                        if (!was[t])
                        {
                            was[t] = 1;
                            flow::add_edge(starts + si, startt + t, 1, dist);
                        }
                    for (int g = 0; g < 4; ++g)
                    {
                        int nx = cx + DX[g];
                        int ny = cy + DY[g];
                        if (nx < 0 || ny < 0 || nx >= sx || ny >= sy || f[nx][ny] == '#' || d[nx][ny] <= dist + 1)
                            continue;
                        d[nx][ny] = dist + 1;
                        q.emplace_back(nx, ny);
                    }
                }
                ++si;
            }
    for (int i = 0; i < si; ++i)
        flow::add_edge(source, starts + i, 1, 0);
    for (int i = 0; i < ti; ++i)
        flow::add_edge(startt + i, sink, 1, 0);

    auto mcmf = flow::min_cost_max_flow(source, sink, 2 + si + ti);
    cout << mcmf.Y << "\n";

    vector < ipair > ans;
    for (int ii = 0; ii < mcmf.Y; ++ii)
    {
        int v = source;
        for (int e : flow::g[v])
        {
            if (flow::edges[e].flow == 1)
            {
                flow::edges[e].flow = 0;
                flow::edges[e^1].flow = 1;
                v = flow::edges[e].to;
                break;
            }
        }
        for (int e : flow::g[v])
        {
            if (flow::edges[e].flow == 1)
            {
                flow::edges[e].flow = 0;
                flow::edges[e^1].flow = 1;
                int nv = flow::edges[e].to;
                ans.emplace_back(v - starts, nv - startt);
                v = nv;
                break;
            }
        }
        for (int e : flow::g[v])
        {
            if (flow::edges[e].flow == 1)
            {
                flow::edges[e].flow = 0;
                flow::edges[e^1].flow = 1;
                break;
            }
        }
    }

    vector < int > s2a(si, -1), t2a(ti, -1);
    for (int i = 0; i < sz(ans); ++i)
    {
        s2a[ans[i].X] = i;
        t2a[ans[i].Y] = i;
    }

    vector < vector < int > > ee(sz(ans));
    for (int i = 0; i < sz(ans); ++i)
    {
        int sol = ans[i].X;
        int tur = ans[i].Y;
        int x = sc[sol].X;
        int y = sc[sol].Y;
        vector < vector < int > > d(sx, vector<int>(sy, IINF));
        vector < vector < ipair > > dp(sx, vector<ipair>(sy, {-1, -1}));
        d[x][y] = 0;
        vector < ipair > q;
        q.emplace_back(x, y);
        int tx = -1, ty = -1;
        for (int i = 0; i < sz(q); ++i)
        {
            int cx = q[i].X, cy = q[i].Y;
            int dist = d[cx][cy];
            bool ok = false;
            for (int t : p2ts[cx][cy])
                if (t == tur)
                {
                    ok = true;
                    tx = cx;
                    ty = cy;
                    break;
                }
            if (ok)
                break;
            for (int g = 0; g < 4; ++g)
            {
                int nx = cx + DX[g];
                int ny = cy + DY[g];
                if (nx < 0 || ny < 0 || nx >= sx || ny >= sy || f[nx][ny] == '#' || d[nx][ny] <= dist + 1)
                    continue;
                d[nx][ny] = dist + 1;
                dp[nx][ny] = {cx, cy};
                q.emplace_back(nx, ny);
            }
        }
        assert(tx != -1);
        
        while (true)
        {
            ipair nxy = dp[tx][ty];
            tx = nxy.X;
            ty = nxy.Y;
            if (tx == -1)
                break;
            for (int t : p2ts[tx][ty])
                ee[i].push_back(t2a[t]);
        }
    }

    topsort.clear();
    vis.assign(sz(ans), 0);
    for (int i = 0; i < sz(ans); ++i)
        dfs44(i, ee);
    for (int i : topsort)
        cout << ans[i].X + 1 << " " << ans[i].Y + 1 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
	cout.precision(20);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
    {
		cout << "Case #" << i << ": ";
        solve();
        cerr << "Case " << i << "/" << t << " done\n";
    }
    return 0;
}
