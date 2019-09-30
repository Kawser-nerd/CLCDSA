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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e4;
const int MOD = 1e9+7;

struct edge_flow{int to, cap, rev;};

class FordFulkerson{
    public:
        int n;
        vector<vector<edge_flow>> edge;
        vector<bool> used;

        FordFulkerson(const vector<vector<edge_flow>>& edge, int n)
            : n(n), edge(edge){}

        int dfs(int v, int t, int f){
            if(v == t){
                return f;
            }
            used[v] = true;

            rep(i, (int)edge[v].size()){
                edge_flow &e = edge[v][i];
                if(not used[e.to] && e.cap > 0){
                    int d = dfs(e.to, t, min(f, e.cap));
                    if(d > 0){
                        e.cap -= d;
                        edge[e.to][e.rev].cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        int max_flow(int s, int t){
            int flow = 0;
            while(true){
                used = vector<bool>(n+1, false);
                int f = dfs(s, t, INF);
                if(f == 0){
                    return flow;
                }
                if(f > 1){
                    return -1;
                }
                flow += f;
            }
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    vector<vector<edge_flow>> graph(h + w + 2, vector<edge_flow>());
    P s, t;
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;

            if(c == 'o'){
                graph[i].push_back(edge_flow{h + j, 1, SZ(graph[h+j])});
                graph[h+j].push_back(edge_flow{i, 0, SZ(graph[i]) - 1});
                graph[h+j].push_back(edge_flow{i, 1, SZ(graph[i])});
                graph[i].push_back(edge_flow{h + j, 0, SZ(graph[h+j]) - 1});
            }else if(c == 'S'){
                s = {i, j};
                graph[h+w].push_back(edge_flow{i, INF, SZ(graph[i])});
                graph[i].push_back(edge_flow{h + w, 0, SZ(graph[h+w]) - 1});
                graph[h+w].push_back(edge_flow{h + j, INF, SZ(graph[h+j])});
                graph[h+j].push_back(edge_flow{h + w, 0, SZ(graph[h+w]) - 1});
            }else if(c == 'T'){
                t = {i, j};
                graph[i].push_back(edge_flow{h + w + 1, INF, SZ(graph[h+w+1])});
                graph[h+w+1].push_back(edge_flow{i, 0, SZ(graph[i]) - 1});
                graph[h+j].push_back(edge_flow{h + w + 1, INF, SZ(graph[h+w+1])});
                graph[h+w+1].push_back(edge_flow{h + j, 0, SZ(graph[h+j]) - 1});
            }
        }
    }

    FordFulkerson ff(graph, h + w + 2);
    cout << ff.max_flow(h + w, h + w + 1) << endl;

    return 0;
}