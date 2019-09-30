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

const int INF = 1e15;
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
                flow += f;
            }
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<edge_flow>> graph(n + 2, vector<edge_flow>());
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;

        if(a > 0){
            sum += a;
            graph[i].push_back(edge_flow{n + 1, a, SZ(graph[n+1])});
            graph[n+1].push_back(edge_flow{i, 0, SZ(graph[i]) - 1});
        }else{
            graph[0].push_back(edge_flow{i, -a, SZ(graph[i])});
            graph[i].push_back(edge_flow{0, 0, SZ(graph[0]) - 1});
        }

        for(int j = i; j <= n; j += i){
            graph[i].push_back(edge_flow{j, INF, SZ(graph[j])});
            graph[j].push_back(edge_flow{i, 0, SZ(graph[i]) - 1});
        }
    }

    FordFulkerson ff(graph, n + 2);
    int ans = ff.max_flow(0, n + 1);
    cout << sum - ans << endl;

    return 0;
}