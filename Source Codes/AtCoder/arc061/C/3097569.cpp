#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> IP;

const int INF = 1e15;
const int MOD = 1e9+7;

vector<set<int>> line;

class edge{
    public:
        int u;
        int v;
        int w;
        edge() : u(0), v(0), w(0) {}
        edge(int u, int v, int w) : u(u), v(v), w(w) {}

        bool operator==(const edge& e) const {
            return u == e.u && v == e.v && w == e.w;
        }

        bool operator<(const edge& e) const {
            if(w != e.w){
                return w < e.w;
            }

            return u == e.u ? v < e.v : u < e.u;
        }
};

pair<map<P, int>, map<P, P>> dijkstra(const vector<map<int, vector<int>>>& graph, int n, int s){
    map<P, int> d;
    d.emplace(make_pair(s, -1), 0);

    map<P, P> p;
    p.emplace(make_pair(s, -1), make_pair(s, -1));

    priority_queue<IP, vector<IP>, greater<IP>> que;
    que.emplace(0, make_pair(s, -1));

    while(!que.empty()){
        int w = que.top().first;
        P to = que.top().second;
        que.pop();

        if(d.find(to) != d.end() && d[to] < w){
            continue;
        }

        if(to.second == -1){
            for(int l : line[to.first]){
                P from = make_pair(to.first, l);
                int nw = w + 1;
                if(d.find(from) == d.end()){
                    d.emplace(from, INF);
                }

                if(nw < d[from]){
                    d[from] = nw;
                    p[from] = to;
                    que.emplace(nw, from);
                }
            }
            continue;
        }

        P from = make_pair(to.first, -1);
        if(d.find(from) == d.end()){
            d.emplace(from, INF);
        }
        if(w < d[from]){
            d[from] = w;
            p[from] = to;
            que.emplace(w, from);
        }

        //<station, line>
        for(int u : graph[to.first].at(to.second)){
            P from = make_pair(u, to.second);
            if(d.find(from) == d.end()){
                d.emplace(from, INF);
            }
            if(w < d[from]){
                d[from] = w;
                p[from] = to;
                que.emplace(w, from);
            }
        }
    }
    return make_pair(d, p);
}

signed main(){
    int n, m;
    cin >> n >> m;

    //vector<vector<P>> edge(n+1, vector<P>());
    vector<map<int, vector<int>>> edge(n+1, map<int, vector<int>>());
    line = vector<set<int>>(n+1, set<int>());
    rep(i, m){
        int p, q, c;
        cin >> p >> q >> c;

        if(edge[p].find(c) == edge[p].end()){
            edge[p].emplace(c, vector<int>());
        }
        if(edge[q].find(c) == edge[q].end()){
            edge[q].emplace(c, vector<int>());
        }
        edge[p][c].push_back(q);
        edge[q][c].push_back(p);
        line[p].insert(c);
        line[q].insert(c);
    }

    pair<map<P, int>, map<P, P>> ans = dijkstra(edge, n, 1);
    if(ans.first.find(make_pair(n, -1)) == ans.first.end()){
        cout << -1 << endl;
        return 0;
    }
    cout << ans.first[make_pair(n, -1)] << endl;

    return 0;
}