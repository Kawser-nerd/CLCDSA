#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using uint = unsigned int;
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#include"debug_deque.hpp"
#define vector DebugDeque
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde);
#endif

struct Graph{
    struct Node{
        vector<int> inEdges, outEdges;
        vector<int>& edges(bool rev = false){ return rev ? inEdges : outEdges; }
    };
    struct Edge{
        int from, dest;
        ll limit, rem;
        Edge(){ }
        Edge(int from, int dest, ll limit = 1): from(from), dest(dest), limit(limit), rem(limit){ }
        int to(bool rev = false){ return rev ? from : dest; }
        ll remain(bool rev = false){ return rev ? limit - rem : rem; }
        void pour(ll qua, bool rev = false){ rem -= rev ? - qua : qua; }
    };
    vector<Node> nodes;
    vector<Edge> edges;
    Graph(int nn, int en = 10): nodes(nn){
        edges.reserve(en);
    }

    void addEdge(int from, int dest, ll limit){
        nodes[from].outEdges.emplace_back(edges.size());
        nodes[dest].inEdges.emplace_back(edges.size());
        edges.emplace_back(from, dest, limit);
    }
    ll flow(int start, int goal, vector<char>& visited, ll cur){
        if(start == goal){ return cur; }
        auto _flow = [&](bool rev = false){
            for(int eidx : nodes[start].edges(rev)){
                Edge& e = edges[eidx];
                int vidx = e.to(rev);
                if(!e.remain(rev) || visited[vidx]){ continue; }
                visited[vidx] = true;
                ll lim = min(cur, e.remain(rev));
                if((lim = flow(vidx, goal, visited, lim))){
                    e.pour(lim, rev);
                    return lim;
                }
            }
            return 0ll;
        };
        ll ret = _flow();
        return ret ? ret : _flow(true);
    }
    ll maxFlow(int start, int goal){
        if(start == goal){ exit(1); }
        ll ret = 0;
        while(1){
            ll prev = ret;
            vector<char> visited(nodes.size());
            ret += flow(start, goal, visited, MLL);
            if(ret == prev){ break; }
        }
        return ret;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    Graph g(n + 2, 2 * n);
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        if(a > 0){
            sum += a;
            g.addEdge(i, n + 1, a);
        }else{
            g.addEdge(0, i, - a);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + i; j <= n; j += i){
            g.addEdge(i, j, MLL);
        }
    }
    ll mi = g.maxFlow(0, n + 1);
    cout << sum - mi << '\n';
}