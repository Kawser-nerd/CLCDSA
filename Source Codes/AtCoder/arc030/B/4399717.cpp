#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int n, x;
vector<int> h;

vector<vector<int>> g;

int ans = 0;

bool dfs(int r, int p = -1) {
    bool ret = h[r];
    
    for (int to : g[r]) {
        if (to == p) {
            continue;
        }
        
        if (dfs(to, r)) {
            ret = true;
            ans += 2;
        }
    }
    
    return ret;
}

int main()
{
    cin >> n >> x;
    h.resize(n);
    g.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    dfs(x-1);
    
    cout << ans << endl;
}