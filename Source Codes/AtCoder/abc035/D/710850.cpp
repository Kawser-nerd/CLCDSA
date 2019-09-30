#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
#define INF 1e9
typedef long long ll;
typedef pair<int,int> P;

void dijkstra(vector<vector<P> >& graph, vector<int>& path){
    priority_queue<P, vector<P>, greater<P> > nodes; //<length of path, index>
    nodes.push(make_pair(0, 0));
    path[0] = 0;
    while (!nodes.empty()) {
        P now = nodes.top();
        nodes.pop();
        
        int index = now.second;
        int len = now.first;
        if (path[index] < len) {
            continue;
        }
        for (int i = 0; i < graph[index].size(); i++) {
            int to = graph[index][i].first;
            int cost = graph[index][i].second;
            if (path[index] + cost < path[to]) {
                path[to] = path[index] + cost;
                nodes.push(make_pair(path[to], to));
            }
        }
    }
}

int main(){
    int N, M, T;
    cin >> N >> M >> T;
    vector<vector<P> > graph(N, vector<P>()),  graph_back(N, vector<P>());
    vector<ll> earn;
    earn.resize(N);
    int a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> earn[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back(make_pair(b, c));
        graph_back[b].push_back(make_pair(a, c));
    }
    vector<int> path(N, INF), path_back(N, INF);
    dijkstra(graph, path);
    dijkstra(graph_back, path_back);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (path[i] == INF || path_back[i] == INF) {
            continue;
        }
        ans = max(ans, (ll)earn[i]*(T-path[i]-path_back[i]));
    }
    cout << ans << endl;
    return 0;
}