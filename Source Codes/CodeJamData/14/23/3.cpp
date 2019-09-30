#pragma comment(linker, "/STACK:1000000000")
#if 1
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int , int> pii;
typedef vector <int> veci;
typedef vector <veci> graph;
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define iss istringstream
#define oss ostringstream
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define dbgv(x) {cerr << #x << " ={"; for (int _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define NAME "problem"

template<class T> string to_str(const T &a) { oss os; os << a; return os.str(); }
template<> string to_str<LD>(const LD& a) { oss os; os.precision(10); os.setf(ios::fixed); os << a; return os.str(); }
template<class T> T from_str(const string &s) { iss is; T val; is >> val; return val; }
string T(int test) { ostringstream os; os << "Case #" << test << ":"; return os.str(); }
int _test_start = -1, _test_end = -1;
bool need_to_run(int test) { return _test_start == -1 || _test_start <= test && test <= _test_end; }

string dfs(const graph &g, vector<int> &used, const vector<string> &zip, int u)
{
    string res = zip[u];
    used[u] = 1;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if (!used[v])
            res += dfs(g, used, zip, v);
    }
    return res;
}
void dfs2(const graph &g, vector<int> &used, int u)
{
    used[u] = 1;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if (!used[v])
            dfs2(g, used,  v);
    }
}
struct cmp_t
{
    vector<string> zip;
    cmp_t(const vector<string> &zip) : zip(zip) {}
    bool operator() (int i, int j)
    {
        return zip[i] < zip[j];
    }
};

bool can(const graph &g, vector<int> path, vector<int> used, int ind, int u)
{
    path.resize(ind + 1);
    path.push_back(u);
    for (int i = (int)path.size() - 1; i >= 0; --i)
        dfs2(g, used, path[i]);
    int visited = accumulate(used.begin(), used.end(), 0);
    return visited == g.size();
}
void solve(int test)
{
    // read
    int n, m;
    cin >> n >> m;
    vector<string> zip(n);
    for (int i = 0; i < n; ++i)
        cin >> zip[i];
    graph g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v; scanf("%d%d", &u, &v);
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cmp_t cmp(zip);
    for (int i = 0; i < n; ++i)
        sort(g[i].begin(), g[i].end(), cmp);
    vector<int> ord(n);
    for (int i = 0; i < n; ++i)
        ord[i] = i;
    sort(ord.begin(), ord.end(), cmp);
    if (!need_to_run(test)) return;
    // solve
    string res = "";
    for (int start = 0; start < n; ++start)
    {
        vector<int> used(n);
        string cur = dfs(g, used, zip, start);
        int visited = accumulate(used.begin(), used.end(), 0);
        if (visited != n)
            continue;
        if (res == "" || res > cur)
            res = cur;    
        used.assign(n, 0);
        used[start] = true;
        vector<int> path;
        path.push_back(start);
        cur = zip[start];
        bool ok = true;
        for (int i = 1; i < n; ++i)
        {
            int best_city = -1;
            int path_prev = -1;
            for (int i = (int)path.size() - 1; i >= 0; --i)
            {
                int u = path[i];
                for (int j = 0; j < g[u].size(); ++j)
                {
                    int v = g[u][j];
                    if (used[v])
                        continue;
                    if (can(g, path, used, i, v))
                    {
                        if (best_city == -1 || zip[best_city] > zip[v])
                        {
                            best_city = v;
                            path_prev = i;
                        }
                    }
                }
            }
            if (best_city == -1)
            {
                ok = false;
                break;
            }
            path.resize(path_prev + 1);
            path.push_back(best_city);
            cur += zip[best_city];
            used[best_city] = 1;
        }
        if (ok)
        {
            if (res.empty() || res > cur)
                res = cur;
        }
    }

    // write
    cout << T(test) << " " << res << endl;
}

int main(int argc, char *argv[])
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //freopen(NAME ".in","r",stdin); freopen(NAME ".out","w",stdout);
    if (argc == 2) { _test_start = _test_end = from_str<int>(argv[1]); }
    if (argc == 3) { _test_start = from_str<int>(argv[1]); _test_end = from_str<int>(argv[2]); }

    clock_t tstart = clock();

    int tests;
    scanf("%d", &tests);
    for(int test = 1; test <= tests; ++test)
    {
        clock_t tprev = clock();
        solve(test);
        if (need_to_run(test))
            dbg("elapsed for #" << test << ": " << (clock() - tprev) / LD(CLOCKS_PER_SEC));
    }

    dbg("elapsed: " << (clock() - tstart) / LD(CLOCKS_PER_SEC));
    return 0;
}
/*************************
*************************/
#endif

