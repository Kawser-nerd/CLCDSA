#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;
#define MOD 1000000007

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, a, b, M;
    cin >> N >> a >> b >> M;
    a--; b--;
    vector<vector<int>> G(N);
    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<int> d(N);
    vector<bool> isVisited(N, false);
    queue<pair<int, int>> que;
    que.push(make_pair(a, 0));
    while(!que.empty()){
        pair<int, int> q = que.front();
        que.pop();
        if(isVisited[q.first]) continue;
        isVisited[q.first] = true;
        d[q.first] = q.second;
        for(int t : G[q.first])
            que.push(make_pair(t, q.second+1));
    }

    vector<pair<int ,int>> order(N);
    for(int i=0; i<N; i++) order[i] = make_pair(d[i], i);
    sort(order.begin(), order.end());

    vector<long long> dp(N);
    dp[a] = 1;
    for(int i=0; i<N; i++){
        int id = order[i].second;
        if(id == a) continue;
        long long sm = 0;
        for(int t : G[id])
            if(d[id] == d[t] + 1){
                sm += dp[t];
                sm %= MOD;
            }
        dp[id] = sm % MOD;
    }
    cout << dp[b] << endl;
    return 0;
}