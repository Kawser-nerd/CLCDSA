#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

void dfs(vector<int> &sar, int s, vector<vector<int>> &G){
    if(G[s].empty()){
        sar[s] = 1;
        return;
    }
    int mx = 0;
    int mn = 1 << 30;
    for(int t : G[s]){
        dfs(sar, t, G);
        mx = max(mx, sar[t]);
        mn = min(mn, sar[t]);
    }
    sar[s] = mx+mn+1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i=1; i<N; i++){
        int B;
        cin >> B;
        B--;
        G[B].push_back(i);
    }
    vector<int> sar(N, 0);
    dfs(sar, 0, G);
    cout << sar[0] << endl;
    return 0;
}