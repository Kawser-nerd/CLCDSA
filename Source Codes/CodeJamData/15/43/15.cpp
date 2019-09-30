#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TEdge {
    int from, to, c, w;

    TEdge(int from = 0, int to = 0, int c = 0, int w = 0)
        : from(from)
        , to(to)
        , c(c)
        , w(w)
    {
    }
};

const int MAXN = 10000;
vector<TEdge> edges;
vi e[MAXN];
int vis[MAXN];

void addEdge(int from, int to, int c) {
//    cerr << from << ' ' << to << '\n';
    e[from].pb(edges.size());
    edges.pb(TEdge(from, to, c, 0));
    e[to].pb(edges.size());
    edges.pb(TEdge(to, from, 0, 0));
}

bool dfs(int v, int T) {
    if (v == T) return true;
    if (vis[v]) return false;
    vis[v] = 1;
    for (int u: e[v]) {
        TEdge &w = edges[u];
        if (w.w < w.c && dfs(w.to, T)) {
            ++w.w;
            --edges[u ^ 1].w;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int T;
    cin >> T;
    for1(t, T) {
//        cerr << t << '\n';
        int N;
        cin >> N;
        string trash;
        getline(cin, trash);
        vector< vector<string> > words(N);
        vector<string> allw;
        forn(i, N) {
            string s;
            getline(cin, s);
            stringstream ss;
            ss << s;
            string t;
            while (ss >> t) words[i].pb(t), allw.pb(t);
        }
//        cerr << "read\n";
        sort(all(allw));
        allw.erase(unique(all(allw)), allw.end());
        map<string, int> en;
        forn(i, allw.size()) en[allw[i]] = i;
        int S = 2 * allw.size(), T = S + 1;
        edges.clear();
        forn(i, T + 1) e[i].clear();
        forn(i, allw.size()) addEdge(2 * i, 2 * i + 1, 1);
        forn(i, N) {
            if (i < 2) continue;
            forn(j, words[i].size()) forn(k, words[i].size()) addEdge(2 * en[words[i][j]] + 1, 2 * en[words[i][k]], 1);
        }
        for (string w: words[0]) addEdge(S, 2 * en[w], 1e9);
        for (string w: words[1]) addEdge(2 * en[w] + 1, T, 1e9);
//        cerr << "built\n";
        int res = 0;
        while (1) {
//            cerr << res << '\n';
            forn(i, T + 1) vis[i] = 0;
            if (dfs(S, T)) ++res;
            else break;
//            cerr << "ok\n";
        }
//        cerr << "done\n";
        cout << "Case #" << t << ": " << res << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
