#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 1e5 + 10;
int n, m, path[MAXN], sz;
bool vis[MAXN];
vector<int> adj[MAXN];

void dfs(int v){
    if (!vis[v])
        path[sz++] = v;
    vis[v] = 1;
    for (int u:adj[v])
        if (!vis[u]){
            dfs(u);
            break;
        }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (m--){
        int u, v;	cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0);

    reverse(path, path + sz);
    dfs(0);
    
    cout << sz << "\n";
    for (int i = 0; i < sz; i++)
        cout << path[i]+1 << " ";
    cout << "\n";
    return 0;
}