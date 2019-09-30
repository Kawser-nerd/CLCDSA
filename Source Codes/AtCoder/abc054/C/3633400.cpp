#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#define ll long long
#define endl '\n'
using namespace std;
int N, M;

vector<int> adj[9];
bool visited[9];

bool ok()
{
    for(int i = 1; i <= N; i++)
        if(!visited[i]) return false;
    return true;
}

int dfs(int cur)
{
    visited[cur] = true;
    int ret = 0;
    if(ok())
        ret = 1;
    
    for(int i = 0; i < adj[cur].size(); i++)
    {
        auto next = adj[cur][i];
        if(visited[next]) continue;
        ret += dfs(next);
    }
    
    visited[cur] = false;
    return ret;
}

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    cout << dfs(1) << endl;
    return 0;
}