#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

class FordFulkerson {

private:
    // ?????????
    struct edge { int to, cap, rev; };
    const int INF = 1e9;
    vector<vector<edge> > G;
    vector<char> used;

public:

    FordFulkerson(int V){
        G.resize(V);
        used.resize(V);
    }

    void add_uni_edge(int from, int to, int cap) {
        // rev??????????????????????????
        G[from].push_back( edge{ to, cap, SIZE(G[to])});
        G[to].push_back( edge{from, 0, SIZE(G[from]) - 1});
    }

    // ????
    void add_bi_edge(int v1, int v2, int cap) {
        add_uni_edge(v1, v2, cap);
        add_uni_edge(v2, v1, cap);
    }

    // v??t?????????
    // f????v??????????????????????
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;

        // v?????????????
        REP(i, SIZE(G[v])){
            edge &e = G[v][i];
            // ???e????????
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (true) {
            fill(ALL(used), 0);
            int f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }

    void debug_print() {
        REP(from, SIZE(G)){
            cout << "from " << from << ": " << endl;
            for (auto e : G[from]) {
                printf(" -> %d, capacity(%d), rev(%d)\n", e.to, e.cap, G[e.to][e.rev].cap);
            }
            cout << endl;
        }
    }

};

int main(void)
{
    cin.sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    vector<string> cells(H);

    pair<int,int> pos_s;
    pair<int,int> pos_t;
    REP(h, H) {
        cin >> cells[h];
        REP(w, W) {
            if (cells[h][w] == 'S') {
                cells[h][w] = 'o';
                pos_s = mp(h,w);
            }
            else if (cells[h][w] == 'T') {
                cells[h][w] = 'o';
                pos_t = mp(h,w);
            }
        }
    }

    if (pos_s.first == pos_t.first || pos_s.second == pos_t.second) {
        cout << -1 << endl;
        return 0;
    }

    FordFulkerson ff(H + W + 2);
    REP(h, H) {
        REP(w, W) {
            if (cells[h][w] == 'o') {
                ff.add_bi_edge(h, H + w, 1);
            }
        }
    }
    ff.add_uni_edge(H + W, pos_s.first, 1e7);
    ff.add_uni_edge(H + W, H + pos_s.second, 1e7);
    ff.add_uni_edge(pos_t.first, H + W + 1, 1e7);
    ff.add_uni_edge(H + pos_t.second, H + W + 1, 1e7);
    auto flow = ff.max_flow(H + W, H + W + 1);
    cout << flow << endl;

    return 0;
}