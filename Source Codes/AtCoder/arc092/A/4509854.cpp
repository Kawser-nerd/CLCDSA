#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define INF 10000

struct edge {int to, cap, rev;};

vector<edge> G[202];
bool used[202];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge{to, cap, (int)G[to].size()}));
    G[to].push_back((edge{from, 0, (int)G[from].size()-1}));
}

int dfs(int v, int t, int f, vector<edge> G[]){
    if(v == t) return f;
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(f, e.cap), G);
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int main(){
    int N;
    int a[101], b[101], c[101], d[101];
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i] >> b[i];
        add_edge(0, i, 1);
    }
    for(int i = 1; i <= N; i++){
        cin >> c[i] >> d[i];
        add_edge(N+i, 2*N+1, 1);
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(a[i] < c[j] && b[i] < d[j]){
                add_edge(i, N+j, 1);
            }
        }
    }
    int flow = 0;
    while(true){
        memset(used, 0, sizeof(used));
        int f = dfs(0, 2*N+1, INF, G);
        if(f == 0){
            cout << flow << endl;
            break;
        }
        flow += f;
    }
}